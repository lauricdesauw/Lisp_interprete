#pragma once

#include "library.hh"
#include "error.hh"

Env make_env();
Env add_new_binding(std::string name, Object value, Env env);
Env extend_largs_env(Object lpars, Object lvals, Env env);
Object find_value(Object obj, Env env);
std::ostream& print_env(std::ostream& s, Env env);

bool bidingp(Object obj);
Object biding_value(Object obj);
std::string biding_name(Object obj);
