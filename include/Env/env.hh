#pragma once

#include "library.hh"
#include "error.hh"

// Binding related functions
bool bindingp(Object obj);
Object binding_value(Object obj);
std::string binding_name(Object obj);

// Environment creation
Env make_env();

// Environment edition
Env add_new_binding(std::string name, Object value, Env env);
Env add_new_binding_stat(std::string name, Object value, Env env);
void replace_binding(Object obj_name, Object new_value, Env env);
Env extend_largs_env(Object lpars, Object lvals, Env env);

// Data getters
Object find_value(Object obj, Env env);

// Print data
std::ostream& print_env(std::ostream& s, Env env);
