/* { dg-do compile } */
/* { dg-require-effective-target vect_float } */
/* { dg-options "-O3 -funroll-loops -fdump-tree-slp-details" } */

class mydata {
public:
    mydata() {Set(-1.0);}
    void Set (float);
    static int upper() {return 8;}
    float data[8];
};

void mydata::Set (float x)
{
  for (int i=0; i<upper(); i++)
    data[i] = x;
}

/* { dg-final { scan-tree-dump-times "basic block vectorized using SLP" 1 "slp" } } */
/* { dg-final { cleanup-tree-dump "slp" } } */
