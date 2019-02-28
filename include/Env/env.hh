#pragma once

#include "library.hh"
#include "error.hh"

Env make_env();
Env add_new_binding(std::string name, Object value, Env env);
Env extend_largs_env(Object lpars, Object lvals, Env env);
Object find_value(std::string name, Env env);
std::ostream& print_env(std::ostream& s, Env env);
