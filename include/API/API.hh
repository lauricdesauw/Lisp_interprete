#pragma once

#include <iostream>
#include <string>
#include "globals.hh"

class API {
  /*********** Object **********/

 public:
  // Control Structures
  static void check(Object l);
  static void add_to_GC_root(Object l);

  // Constants access
  static Object nil();
  static bool null(Object l);
  static Object t();
  static Object f();

  // Type tests
  static bool const_objectp(Object l);
  static bool numberp(Object l);
  static bool stringp(Object l);
  static bool symbolp(Object l);
  static bool boolp(Object l);
  static bool listp(Object l);
  static bool pairp(Object l);

  // Lists operators
  static Object cons(Object a, Object l);
  static Object car(Object l);
  static Object cdr(Object l);
  static void rplacd(Object l, Object new_value);

  // C++ to Lisp conversion
  static Object number_to_object(int n);
  static Object string_to_object(std::string s);
  static Object symbol_to_object(std::string s);
  static Object bool_to_object(bool b);

  // Lisp to C++ conversion
  static int object_to_number(Object l);
  static std::string object_to_string(Object l);
  static bool object_to_bool(Object l);

  // User utility data
  static void print_stats();

  // Static environment
  static bool is_static(Object l);
  static Env get_closure(Object l);
  static void set_closure(Object l, Env env);

 private:
  // Constants
  static const Object object_nil;
  static const Object object_t;
  static const Object object_f;

  /********** Environnement **********/

 public:
  static Env make_env();
  static Env add_new_binding(std::string name, Object value, Env env);
  static Object find_value(std::string name, Env env);
  static std::ostream &print_env(std::ostream &s, Env env);
};
