// i++ is never an lvalue
void
f()
{
  bool i = 0;
  i++ = 3; // { dg-error "" }
  // { dg-warning "deprecated" "" { target { ! c++1z } } 6 }
}
