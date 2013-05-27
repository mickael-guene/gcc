/* No stack red zone.  PR38644.  */
/* { dg-options "-mthumb -O2" } */
/* { dg-final { scan-assembler "ldrb\[^\n\]*\\n\[\t \]*add\[\t \]*sp" } } */
/* { dg-skip-if "" { arm-*-linux-uclibceabi } "*" "" } */

extern int doStreamReadBlock (int *, char *, int size, int);

char readStream (int *s)
{
       char c = 0;
       doStreamReadBlock (s, &c, 1, *s);
       return c;
}
