/* { dg-do compile } */
/* { dg-require-effective-target arm_cortex_m } */
/* { dg-require-effective-target arm_thumb1_ok } */
/* { dg-options "-O2 -march=armv6s-m -mthumb -mexecute-only" } */

int
foo (int a)
{
  switch(a)
    {
      case 0: return 12;
      case 1: return 2;
      case 2: return 1231;
      case 3: return 0xdead;
      default:
        break;
    }
  
  return -1;
}

/* { dg-final { scan-assembler-not "ldr\[\t \]+r\[0-9\]+, .L" } } */

