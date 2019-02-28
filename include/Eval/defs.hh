#pragma once

#include "library.hh"

const Object lisp_lambda = symbol_to_object("lambda");
Object do_lambda(Object l);

const Object lisp_quote = symbol_to_object("quote");
Object do_quote(Object l);

const Object lisp_if = symbol_to_object("if");
Object do_if(Object l, Env env);

const Object lisp_plus = symbol_to_object("+");
Object do_plus(Object lvals);

const Object lisp_minus = symbol_to_object("-");
Object do_minus(Object lvals);

const Object lisp_times = symbol_to_object("*");
Object do_times(Object lvals);

const Object lisp_eq = symbol_to_object("=");
Object do_eq(Object lvals);

const Object lisp_inf = symbol_to_object("<");
Object do_inf(Object lvals);

const Object lisp_concat = symbol_to_object("concat");
Object do_concat(Object lvals);

const Object lisp_car = symbol_to_object("car");
Object do_car(Object lvals);

const Object lisp_cdr = symbol_to_object("cdr");
Object do_cdr(Object lvals);

const Object lisp_cons = symbol_to_object("cons");
Object do_cons(Object lvals);

const Object lisp_read = symbol_to_object("read");
Object do_read(Object lvals);

const Object lisp_display = symbol_to_object("display");
Object do_display(Object lvals);

const Object lisp_newline = symbol_to_object("newline");
Object do_newline(Object lvals);

const Object lisp_end = symbol_to_object("end");
Object do_end(Object lvals);

const Object lisp_nullp = symbol_to_object("null?");
Object do_nullp(Object lvals);

const Object lisp_stringp = symbol_to_object("string?");
Object do_stringp(Object lvals);

const Object lisp_numberp= symbol_to_object("number?");
Object do_numberp(Object lvals);

const Object lisp_symbolp = symbol_to_object("symbol?");
Object do_symbolp(Object lvals);

const Object lisp_listp = symbol_to_object("list?");
Object do_lisp(Object lvals);

const Object lisp_list = symbol_to_object("list");
Object do_list(Object lvals);

const Object lisp_error = symbol_to_object("error");
Object do_error(Object lvals);
