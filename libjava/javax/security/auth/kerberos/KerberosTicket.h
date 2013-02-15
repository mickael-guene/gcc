
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_security_auth_kerberos_KerberosTicket__
#define __javax_security_auth_kerberos_KerberosTicket__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace net
    {
        class InetAddress;
    }
  }
  namespace javax
  {
    namespace crypto
    {
        class SecretKey;
    }
    namespace security
    {
      namespace auth
      {
        namespace kerberos
        {
            class KerberosPrincipal;
            class KerberosTicket;
            class KeyImpl;
        }
      }
    }
  }
}

class javax::security::auth::kerberos::KerberosTicket : public ::java::lang::Object
{

public:
  KerberosTicket(JArray< jbyte > *, ::javax::security::auth::kerberos::KerberosPrincipal *, ::javax::security::auth::kerberos::KerberosPrincipal *, JArray< jbyte > *, jint, JArray< jboolean > *, ::java::util::Date *, ::java::util::Date *, ::java::util::Date *, ::java::util::Date *, JArray< ::java::net::InetAddress * > *);
  virtual void destroy();
  virtual jboolean isDestroyed();
  virtual jboolean isCurrent();
  virtual void refresh();
  virtual ::javax::security::auth::kerberos::KerberosPrincipal * getClient();
  virtual ::javax::security::auth::kerberos::KerberosPrincipal * getServer();
  virtual jboolean isForwardable();
  virtual jboolean isForwarded();
  virtual jboolean isProxiable();
  virtual jboolean isProxy();
  virtual jboolean isPostdated();
  virtual jboolean isRenewable();
  virtual jboolean isInitial();
  virtual JArray< jboolean > * getFlags();
  virtual ::java::util::Date * getAuthTime();
  virtual ::java::util::Date * getStartTime();
  virtual ::java::util::Date * getEndTime();
  virtual ::java::util::Date * getRenewTill();
  virtual JArray< ::java::net::InetAddress * > * getClientAddresses();
  virtual JArray< jbyte > * getEncoded();
  virtual ::javax::crypto::SecretKey * getSessionKey();
private:
  void checkDestroyed();
public:
  virtual ::java::lang::String * toString();
  virtual jint getSessionKeyType();
private:
  static const jlong serialVersionUID = 7395334370157380539LL;
  static const jint FORWARDABLE = 1;
  static const jint FORWARDED = 2;
  static const jint PROXIABLE = 3;
  static const jint PROXY = 4;
  static const jint POSTDATED = 6;
  static const jint RENEWABLE = 8;
  static const jint INITIAL = 9;
  static const jint NUM_FLAGS = 12;
  JArray< jbyte > * __attribute__((aligned(__alignof__( ::java::lang::Object)))) asn1Encoding;
  ::javax::security::auth::kerberos::KeyImpl * sessionKey;
  JArray< jboolean > * flags;
  ::java::util::Date * authTime;
  ::java::util::Date * startTime;
  ::java::util::Date * endTime;
  ::java::util::Date * renewTill;
  ::javax::security::auth::kerberos::KerberosPrincipal * client;
  ::javax::security::auth::kerberos::KerberosPrincipal * server;
  JArray< ::java::net::InetAddress * > * clientAddresses;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_security_auth_kerberos_KerberosTicket__
