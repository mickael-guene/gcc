
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_print_ipp_attribute_DetailedStatusMessage__
#define __gnu_javax_print_ipp_attribute_DetailedStatusMessage__

#pragma interface

#include <javax/print/attribute/TextSyntax.h>
extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace print
      {
        namespace ipp
        {
          namespace attribute
          {
              class DetailedStatusMessage;
          }
        }
      }
    }
  }
}

class gnu::javax::print::ipp::attribute::DetailedStatusMessage : public ::javax::print::attribute::TextSyntax
{

public:
  DetailedStatusMessage(::java::lang::String *, ::java::util::Locale *);
  ::java::lang::Class * getCategory();
  ::java::lang::String * getName();
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_print_ipp_attribute_DetailedStatusMessage__
