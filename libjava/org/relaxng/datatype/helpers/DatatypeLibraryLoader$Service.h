
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __org_relaxng_datatype_helpers_DatatypeLibraryLoader$Service__
#define __org_relaxng_datatype_helpers_DatatypeLibraryLoader$Service__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace net
    {
        class URL;
    }
  }
  namespace org
  {
    namespace relaxng
    {
      namespace datatype
      {
        namespace helpers
        {
            class DatatypeLibraryLoader$Service;
            class DatatypeLibraryLoader$Service$Loader;
        }
      }
    }
  }
}

class org::relaxng::datatype::helpers::DatatypeLibraryLoader$Service : public ::java::lang::Object
{

public:
  DatatypeLibraryLoader$Service(::java::lang::Class *);
  virtual ::java::util::Enumeration * getProviders();
private:
  jboolean moreProviders();
  static ::java::util::Enumeration * parseConfigFile(::java::net::URL *);
public: // actually package-private
  static ::java::util::Vector * access$0(::org::relaxng::datatype::helpers::DatatypeLibraryLoader$Service *);
  static jboolean access$1(::org::relaxng::datatype::helpers::DatatypeLibraryLoader$Service *);
private:
  ::java::lang::Class * __attribute__((aligned(__alignof__( ::java::lang::Object)))) serviceClass;
  ::java::util::Enumeration * configFiles;
  ::java::util::Enumeration * classNames;
  ::java::util::Vector * providers;
  ::org::relaxng::datatype::helpers::DatatypeLibraryLoader$Service$Loader * loader;
  static const jint START = 0;
  static const jint IN_NAME = 1;
  static const jint IN_COMMENT = 2;
public:
  static ::java::lang::Class class$;
};

#endif // __org_relaxng_datatype_helpers_DatatypeLibraryLoader$Service__
