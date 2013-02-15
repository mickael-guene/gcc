
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __org_omg_IOP_TaggedProfileHelper__
#define __org_omg_IOP_TaggedProfileHelper__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace org
  {
    namespace omg
    {
      namespace CORBA
      {
          class Any;
          class TypeCode;
        namespace portable
        {
            class InputStream;
            class OutputStream;
        }
      }
      namespace IOP
      {
          class TaggedProfile;
          class TaggedProfileHelper;
      }
    }
  }
}

class org::omg::IOP::TaggedProfileHelper : public ::java::lang::Object
{

public:
  TaggedProfileHelper();
  static ::org::omg::CORBA::TypeCode * type();
  static void insert(::org::omg::CORBA::Any *, ::org::omg::IOP::TaggedProfile *);
  static ::org::omg::IOP::TaggedProfile * extract(::org::omg::CORBA::Any *);
  static ::java::lang::String * id();
  static ::org::omg::IOP::TaggedProfile * read(::org::omg::CORBA::portable::InputStream *);
  static void write(::org::omg::CORBA::portable::OutputStream *, ::org::omg::IOP::TaggedProfile *);
  static ::java::lang::Class class$;
};

#endif // __org_omg_IOP_TaggedProfileHelper__
