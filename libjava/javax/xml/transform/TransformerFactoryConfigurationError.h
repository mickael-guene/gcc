
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_xml_transform_TransformerFactoryConfigurationError__
#define __javax_xml_transform_TransformerFactoryConfigurationError__

#pragma interface

#include <java/lang/Error.h>
extern "Java"
{
  namespace javax
  {
    namespace xml
    {
      namespace transform
      {
          class TransformerFactoryConfigurationError;
      }
    }
  }
}

class javax::xml::transform::TransformerFactoryConfigurationError : public ::java::lang::Error
{

public:
  TransformerFactoryConfigurationError();
  TransformerFactoryConfigurationError(::java::lang::String *);
  TransformerFactoryConfigurationError(::java::lang::Exception *);
  TransformerFactoryConfigurationError(::java::lang::Exception *, ::java::lang::String *);
  virtual ::java::lang::String * getMessage();
  virtual ::java::lang::Exception * getException();
private:
  static const jlong serialVersionUID = -6527718720676281516LL;
  ::java::lang::Exception * __attribute__((aligned(__alignof__( ::java::lang::Error)))) exception;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_xml_transform_TransformerFactoryConfigurationError__
