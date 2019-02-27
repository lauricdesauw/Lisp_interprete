#pragma once

#include <iostream>
#include <string>
#include "globals.hh"

class API {
  // Object

    public:
        static void check(Object l);

        static Object nil();
        static bool null(Object l);
        static Object t();
        static Object f();

        static bool numberp(Object l);
        static bool stringp(Object l);
        static bool symbolp(Object l);
        static bool listp(Object l);

        static Object cons(Object a, Object l);
        static Object car(Object l);
        static Object cdr(Object l);
        static bool eq(Object a, Object b);

        static Object number_to_object(int n);
        static Object string_to_object(std::string s);
        static Object symbol_to_object(std::string s);
        static Object bool_to_object(bool b);

        static int object_to_number(Object l);
        static std::string object_to_string(Object l);
        static bool object_to_bool(Object l);

    private:
        static const Object object_nil;
        static const Object object_t;
        static const Object object_f;

    // Env

    public:
        static Env make_env();
        static Env add_new_binding(std::string name, Object value, Env env);
        static Object find_value(std::string name, Env env);
        static std::ostream& print_env(std::ostream& s, Env env);
};
