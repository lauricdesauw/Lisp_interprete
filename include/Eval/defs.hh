#pragma once

#include <string>
#include "library.hh"

const std::string lisp_lambda = "lambda";
Object do_lambda(Object l);

const std::string lisp_quote = "quote";
Object do_quote(Object l);

const std::string lisp_if = "if";
bject do_if(Object l, Env env);

const std::string lisp_plus = "+";
Object do_plus(Object lvals);

const std::string lisp_minus = "-";
Object do_minus(Object lvals);

const std::string lisp_times = "*";
Object do_times(Object lvals);

const std::string lisp_eq = "=";
Object do_eq(Object lvals);

const std::string lisp_inf = "<";
Object do_inf(Object lvals);

const std::string lisp_concat = "concat";
Object do_concat(Object lvals);

const std::string lisp_car = "car";
Object do_car(Object lvals);

const std::string lisp_cdr = "cdr";
Object do_cdr(Object lvals);

const std::string lisp_cons = "cons";
Object do_cons(Object lvals);

const std::string lisp_read = "read";
Object do_read(Object lvals);

const std::string lisp_display = "display";
Object do_display(Object lvals);

const std::string lisp_newline = "newline";
Object do_newline(Object lvals);

const std::string lisp_end = "end";
Object do_end(Object lvals);

const std::string lisp_nullp = "null?";
Object do_nullp(Object lvals);

const std::string lisp_stringp = "string?";
Object do_stringp(Object lvals);

const std::string lisp_numberp= "number?";
Object do_numberp(Object lvals);

const std::string lisp_symbolp = "symbol?";
Object do_symbolp(Object lvals);

const std::string lisp_listp = "list?";
Object do_lisp(Object lvals);

const std::string lisp_list = "list";
Object do_list(Object lvals);

const std::string lisp_error = "error";
Object do_error(Object lvals);



