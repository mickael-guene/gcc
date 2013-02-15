/* Linux-specific atomic operations for ARM EABI.
   Copyright (C) 2008, 2009, 2010 Free Software Foundation, Inc.
   Contributed by CodeSourcery.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

#if defined(__ARM_ARCH_2__)
# define __ARM_ARCH__ 2
#endif

#if defined(__ARM_ARCH_3__)
# define __ARM_ARCH__ 3
#endif

#if defined(__ARM_ARCH_3M__) || defined(__ARM_ARCH_4__) \
  || defined(__ARM_ARCH_4T__)
/* We use __ARM_ARCH__ set to 4 here, but in reality it's any processor with
   long multiply instructions.  That includes v3M.  */
# define __ARM_ARCH__ 4
#endif

#if defined(__ARM_ARCH_5__) || defined(__ARM_ARCH_5T__) \
  || defined(__ARM_ARCH_5E__) || defined(__ARM_ARCH_5TE__) \
  || defined(__ARM_ARCH_5TEJ__)
# define __ARM_ARCH__ 5
#endif

#if defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) \
  || defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) \
  || defined(__ARM_ARCH_6ZK__) || defined(__ARM_ARCH_6T2__) \
  || defined(__ARM_ARCH_6M__)
# define __ARM_ARCH__ 6
#endif

#if defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) \
  || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) \
  || defined(__ARM_ARCH_7EM__)
# define __ARM_ARCH__ 7
#endif

#ifndef __ARM_ARCH__
#error Unable to determine architecture.
#endif

/* Kernel helper for compare-and-exchange.  */
typedef int (__kernel_cmpxchg_t) (int oldval, int newval, int *ptr);
#if __FDPIC__
#define __kernel_cmpxchg __fdpic_cmpxchg
#else
#define __kernel_cmpxchg (*(__kernel_cmpxchg_t *) 0xffff0fc0)
#endif

/* Kernel helper for memory barrier.  */
typedef void (__kernel_dmb_t) (void);
#if __FDPIC__
#define __kernel_dmb __fdpic_dmb
#else
#define __kernel_dmb (*(__kernel_dmb_t *) 0xffff0fa0)
#endif

#if __FDPIC__
static int __fdpic_cmpxchg(int oldval, int newval, int *ptr)
{
#if __ARM_ARCH__ < 6
  #error architecture support not yet implemented
  /* use swap instruction (but is it always safe ? (interrupt?)) */
#else
  int result;

  asm volatile("1: ldrex r3, [%[ptr]]\n\t"
               "subs  r3, r3, %[oldval]\n\t"
               "strexeq r3, %[newval], [%[ptr]]\n\t"
               "teqeq r3, #1\n\t"
               "beq 1b\n\t"
               "rsbs  %[result], r3, #0\n\t"
               : [result] "=r" (result)
               : [oldval] "r" (oldval) , [newval] "r" (newval), [ptr] "r" (ptr)
                : "r3");
    return result;
#endif
}

static void __fdpic_dmb()
{
#if __ARM_ARCH__ < 6
  /* no op ?. perhaps flush write buffer ? */
  return ;
#else
 #if __ARM_ARCH__ >= 7
  asm volatile("dmb\n\t");
 #elif __ARM_ARCH__ == 6
  asm volatile("mcr p15, 0, r0, c7, c10, 5\n\t");
 #endif
#endif
}

#endif

/* Note: we implement byte, short and int versions of atomic operations using
   the above kernel helpers; see linux-atomic-64bit.c for "long long" (64-bit)
   operations.  */

#define HIDDEN __attribute__ ((visibility ("hidden")))

#ifdef __ARMEL__
#define INVERT_MASK_1 0
#define INVERT_MASK_2 0
#else
#define INVERT_MASK_1 24
#define INVERT_MASK_2 16
#endif

#define MASK_1 0xffu
#define MASK_2 0xffffu

#define FETCH_AND_OP_WORD(OP, PFX_OP, INF_OP)				\
  int HIDDEN								\
  __sync_fetch_and_##OP##_4 (int *ptr, int val)				\
  {									\
    int failure, tmp;							\
									\
    do {								\
      tmp = *ptr;							\
      failure = __kernel_cmpxchg (tmp, PFX_OP (tmp INF_OP val), ptr);	\
    } while (failure != 0);						\
									\
    return tmp;								\
  }

FETCH_AND_OP_WORD (add,   , +)
FETCH_AND_OP_WORD (sub,   , -)
FETCH_AND_OP_WORD (or,    , |)
FETCH_AND_OP_WORD (and,   , &)
FETCH_AND_OP_WORD (xor,   , ^)
FETCH_AND_OP_WORD (nand, ~, &)

#define NAME_oldval(OP, WIDTH) __sync_fetch_and_##OP##_##WIDTH
#define NAME_newval(OP, WIDTH) __sync_##OP##_and_fetch_##WIDTH

/* Implement both __sync_<op>_and_fetch and __sync_fetch_and_<op> for
   subword-sized quantities.  */

#define SUBWORD_SYNC_OP(OP, PFX_OP, INF_OP, TYPE, WIDTH, RETURN)	\
  TYPE HIDDEN								\
  NAME##_##RETURN (OP, WIDTH) (TYPE *ptr, TYPE val)			\
  {									\
    int *wordptr = (int *) ((unsigned int) ptr & ~3);			\
    unsigned int mask, shift, oldval, newval;				\
    int failure;							\
									\
    shift = (((unsigned int) ptr & 3) << 3) ^ INVERT_MASK_##WIDTH;	\
    mask = MASK_##WIDTH << shift;					\
									\
    do {								\
      oldval = *wordptr;						\
      newval = ((PFX_OP (((oldval & mask) >> shift)			\
			 INF_OP (unsigned int) val)) << shift) & mask;	\
      newval |= oldval & ~mask;						\
      failure = __kernel_cmpxchg (oldval, newval, wordptr);		\
    } while (failure != 0);						\
									\
    return (RETURN & mask) >> shift;					\
  }

SUBWORD_SYNC_OP (add,   , +, short, 2, oldval)
SUBWORD_SYNC_OP (sub,   , -, short, 2, oldval)
SUBWORD_SYNC_OP (or,    , |, short, 2, oldval)
SUBWORD_SYNC_OP (and,   , &, short, 2, oldval)
SUBWORD_SYNC_OP (xor,   , ^, short, 2, oldval)
SUBWORD_SYNC_OP (nand, ~, &, short, 2, oldval)

SUBWORD_SYNC_OP (add,   , +, signed char, 1, oldval)
SUBWORD_SYNC_OP (sub,   , -, signed char, 1, oldval)
SUBWORD_SYNC_OP (or,    , |, signed char, 1, oldval)
SUBWORD_SYNC_OP (and,   , &, signed char, 1, oldval)
SUBWORD_SYNC_OP (xor,   , ^, signed char, 1, oldval)
SUBWORD_SYNC_OP (nand, ~, &, signed char, 1, oldval)

#define OP_AND_FETCH_WORD(OP, PFX_OP, INF_OP)				\
  int HIDDEN								\
  __sync_##OP##_and_fetch_4 (int *ptr, int val)				\
  {									\
    int tmp, failure;							\
									\
    do {								\
      tmp = *ptr;							\
      failure = __kernel_cmpxchg (tmp, PFX_OP (tmp INF_OP val), ptr);	\
    } while (failure != 0);						\
									\
    return PFX_OP (tmp INF_OP val);					\
  }

OP_AND_FETCH_WORD (add,   , +)
OP_AND_FETCH_WORD (sub,   , -)
OP_AND_FETCH_WORD (or,    , |)
OP_AND_FETCH_WORD (and,   , &)
OP_AND_FETCH_WORD (xor,   , ^)
OP_AND_FETCH_WORD (nand, ~, &)

SUBWORD_SYNC_OP (add,   , +, short, 2, newval)
SUBWORD_SYNC_OP (sub,   , -, short, 2, newval)
SUBWORD_SYNC_OP (or,    , |, short, 2, newval)
SUBWORD_SYNC_OP (and,   , &, short, 2, newval)
SUBWORD_SYNC_OP (xor,   , ^, short, 2, newval)
SUBWORD_SYNC_OP (nand, ~, &, short, 2, newval)

SUBWORD_SYNC_OP (add,   , +, signed char, 1, newval)
SUBWORD_SYNC_OP (sub,   , -, signed char, 1, newval)
SUBWORD_SYNC_OP (or,    , |, signed char, 1, newval)
SUBWORD_SYNC_OP (and,   , &, signed char, 1, newval)
SUBWORD_SYNC_OP (xor,   , ^, signed char, 1, newval)
SUBWORD_SYNC_OP (nand, ~, &, signed char, 1, newval)

int HIDDEN
__sync_val_compare_and_swap_4 (int *ptr, int oldval, int newval)
{
  int actual_oldval, fail;
    
  while (1)
    {
      actual_oldval = *ptr;

      if (__builtin_expect (oldval != actual_oldval, 0))
	return actual_oldval;

      fail = __kernel_cmpxchg (actual_oldval, newval, ptr);
  
      if (__builtin_expect (!fail, 1))
        return oldval;
    }
}

#define SUBWORD_VAL_CAS(TYPE, WIDTH)					\
  TYPE HIDDEN								\
  __sync_val_compare_and_swap_##WIDTH (TYPE *ptr, TYPE oldval,		\
				       TYPE newval)			\
  {									\
    int *wordptr = (int *)((unsigned int) ptr & ~3), fail;		\
    unsigned int mask, shift, actual_oldval, actual_newval;		\
									\
    shift = (((unsigned int) ptr & 3) << 3) ^ INVERT_MASK_##WIDTH;	\
    mask = MASK_##WIDTH << shift;					\
									\
    while (1)								\
      {									\
	actual_oldval = *wordptr;					\
									\
	if (__builtin_expect (((actual_oldval & mask) >> shift) !=      \
                              ((unsigned int) oldval & MASK_##WIDTH), 0)) \
          return (actual_oldval & mask) >> shift;			\
									\
	actual_newval = (actual_oldval & ~mask)				\
			| (((unsigned int) newval << shift) & mask);	\
									\
	fail = __kernel_cmpxchg (actual_oldval, actual_newval,		\
				 wordptr);				\
									\
      if (__builtin_expect (!fail, 1))                                  \
          return oldval;						\
      }									\
  }

SUBWORD_VAL_CAS (short,       2)
SUBWORD_VAL_CAS (signed char, 1)

typedef unsigned char bool;

bool HIDDEN
__sync_bool_compare_and_swap_4 (int *ptr, int oldval, int newval)
{
  int failure = __kernel_cmpxchg (oldval, newval, ptr);
  return (failure == 0);
}

#define SUBWORD_BOOL_CAS(TYPE, WIDTH)					\
  bool HIDDEN								\
  __sync_bool_compare_and_swap_##WIDTH (TYPE *ptr, TYPE oldval,		\
					TYPE newval)			\
  {									\
    TYPE actual_oldval							\
      = __sync_val_compare_and_swap_##WIDTH (ptr, oldval, newval);	\
    return (oldval == actual_oldval);					\
  }

SUBWORD_BOOL_CAS (short,       2)
SUBWORD_BOOL_CAS (signed char, 1)

void HIDDEN
__sync_synchronize (void)
{
  __kernel_dmb ();
}

int HIDDEN
__sync_lock_test_and_set_4 (int *ptr, int val)
{
  int failure, oldval;

  do {
    oldval = *ptr;
    failure = __kernel_cmpxchg (oldval, val, ptr);
  } while (failure != 0);

  return oldval;
}

#define SUBWORD_TEST_AND_SET(TYPE, WIDTH)				\
  TYPE HIDDEN								\
  __sync_lock_test_and_set_##WIDTH (TYPE *ptr, TYPE val)		\
  {									\
    int failure;							\
    unsigned int oldval, newval, shift, mask;				\
    int *wordptr = (int *) ((unsigned int) ptr & ~3);			\
									\
    shift = (((unsigned int) ptr & 3) << 3) ^ INVERT_MASK_##WIDTH;	\
    mask = MASK_##WIDTH << shift;					\
									\
    do {								\
      oldval = *wordptr;						\
      newval = (oldval & ~mask)						\
	       | (((unsigned int) val << shift) & mask);		\
      failure = __kernel_cmpxchg (oldval, newval, wordptr);		\
    } while (failure != 0);						\
									\
    return (oldval & mask) >> shift;					\
  }

SUBWORD_TEST_AND_SET (short,       2)
SUBWORD_TEST_AND_SET (signed char, 1)

#define SYNC_LOCK_RELEASE(TYPE, WIDTH)					\
  void HIDDEN								\
  __sync_lock_release_##WIDTH (TYPE *ptr)				\
  {									\
    /* All writes before this point must be seen before we release	\
       the lock itself.  */						\
    __kernel_dmb ();							\
    *ptr = 0;								\
  }

SYNC_LOCK_RELEASE (long long,   8)
SYNC_LOCK_RELEASE (int,   4)
SYNC_LOCK_RELEASE (short, 2)
SYNC_LOCK_RELEASE (char,  1)
