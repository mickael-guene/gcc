
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_CORBA_Poa_gnuThreadPolicy__
#define __gnu_CORBA_Poa_gnuThreadPolicy__

#pragma interface

#include <gnu/CORBA/_PolicyImplBase.h>
extern "Java"
{
  namespace gnu
  {
    namespace CORBA
    {
      namespace Poa
      {
          class gnuThreadPolicy;
      }
    }
  }
  namespace org
  {
    namespace omg
    {
      namespace PortableServer
      {
          class ThreadPolicyValue;
      }
    }
  }
}

class gnu::CORBA::Poa::gnuThreadPolicy : public ::gnu::CORBA::_PolicyImplBase
{

public:
  gnuThreadPolicy(::org::omg::PortableServer::ThreadPolicyValue *);
  virtual ::org::omg::PortableServer::ThreadPolicyValue * value();
private:
  static const jlong serialVersionUID = 1LL;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_CORBA_Poa_gnuThreadPolicy__
