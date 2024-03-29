// PR c++/30274
// { dg-do run }

struct S {
  bool x : 4;
};

S s;

int main() {
  s.x++; // { dg-warning "deprecated" "" { target { ! c++1z } } }
  // { dg-error "forbidden" "" { target c++1z } 11 }
  if (s.x != 1)
    return 1;
  ++s.x; // { dg-warning "deprecated" "" { target { ! c++1z } } }
  // { dg-error "forbidden" "" { target c++1z } 15 }
  if (s.x != 1)
    return 2;
}
