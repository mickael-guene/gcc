
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_security_InvalidKeyException__
#define __java_security_InvalidKeyException__

#pragma interface

#include <java/security/KeyException.h>
extern "Java"
{
  namespace java
  {
    namespace security
    {
        class InvalidKeyException;
    }
  }
}

class java::security::InvalidKeyException : public ::java::security::KeyException
{

public:
  InvalidKeyException();
  InvalidKeyException(::java::lang::String *);
  InvalidKeyException(::java::lang::String *, ::java::lang::Throwable *);
  InvalidKeyException(::java::lang::Throwable *);
private:
  static const jlong serialVersionUID = 5698479920593359816LL;
public:
  static ::java::lang::Class class$;
};

#endif // __java_security_InvalidKeyException__
