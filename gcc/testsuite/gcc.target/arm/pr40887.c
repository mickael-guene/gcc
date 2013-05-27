/* { dg-options "-O2 -march=armv5te" { target !arm-*-linux-uclibceabi } }  */
/* { dg-final { scan-assembler "blx" } } */

int (*indirect_func)();

int indirect_call()
{
    return indirect_func();
}
