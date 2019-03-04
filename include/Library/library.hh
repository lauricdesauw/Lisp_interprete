#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include "globals.hh"

// Object

void check(Object l);

Object nil();
bool null(Object l);
Object t();
Object f();

Object cons(Object a, Object l);
Object car(Object l);
Object cdr(Object l);
bool eq(Object a, Object b);

bool numberp(Object l);
bool stringp(Object l);
bool symbolp(Object l);
bool boolp(Object l);
bool pairp(Object l);
bool listp(Object l);
bool pairp(Object l);

Object number_to_object(int n);
Object string_to_object(std::string s);
Object symbol_to_object(std::string s);
Object bool_to_object(bool b);

int object_to_number(Object l);
std::string object_to_string(Object l);
bool object_to_bool(Object l);

bool is_static(Object obj);
Env get_closure(Object obj);
void set_closure(Object obj, Env env);

std::ostream& print_object_aux(std::ostream& s, Object l,bool b);
std::ostream& print_object(std::ostream& s, Object l);
std::ostream& operator<<(std::ostream& s, Object l);
std::ostream& print_type(std::ostream& s, Object l);
void print_stats();

// Derived function

Object car(Object l, int n);
Object cdr(Object l, int n);
Object cadr(Object l);
Object cddr(Object l);
void rplacd(Object l, Object new_value);

Object list2(Object l1, Object l2);
