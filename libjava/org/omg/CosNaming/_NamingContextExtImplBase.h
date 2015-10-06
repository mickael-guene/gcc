
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __org_omg_CosNaming__NamingContextExtImplBase__
#define __org_omg_CosNaming__NamingContextExtImplBase__

#pragma interface

#include <org/omg/CosNaming/_NamingContextImplBase.h>
#include <gcj/array.h>

extern "Java"
{
  namespace org
  {
    namespace omg
    {
      namespace CORBA
      {
          class Object;
          class ServerRequest;
        namespace portable
        {
            class InputStream;
            class OutputStream;
            class ResponseHandler;
        }
      }
      namespace CosNaming
      {
          class NameComponent;
          class _NamingContextExtImplBase;
      }
    }
  }
}

class org::omg::CosNaming::_NamingContextExtImplBase : public ::org::omg::CosNaming::_NamingContextImplBase
{

public:
  _NamingContextExtImplBase();
  virtual JArray< ::java::lang::String * > * _ids();
  virtual ::org::omg::CORBA::portable::OutputStream * _invoke(::java::lang::String *, ::org::omg::CORBA::portable::InputStream *, ::org::omg::CORBA::portable::ResponseHandler *);
  virtual void invoke(::org::omg::CORBA::ServerRequest *);
  virtual ::org::omg::CORBA::Object * resolve_str(::java::lang::String *) = 0;
  virtual JArray< ::org::omg::CosNaming::NameComponent * > * to_name(::java::lang::String *) = 0;
  virtual ::java::lang::String * to_string(JArray< ::org::omg::CosNaming::NameComponent * > *) = 0;
  virtual ::java::lang::String * to_url(::java::lang::String *, ::java::lang::String *) = 0;
public: // actually package-private
  static ::java::util::Hashtable * _methods;
private:
  static JArray< ::java::lang::String * > * __ids;
public:
  static ::java::lang::Class class$;
};

#endif // __org_omg_CosNaming__NamingContextExtImplBase__
