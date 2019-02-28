#pragma once

#include "library.hh"

const Object lisp_quit = symbol_to_object("quit");
void do_quit();

const Object lisp_lambda = symbol_to_object("lambda");
Object do_lambda(Object l, Env env);

const Object lisp_quote = symbol_to_object("quote");
Object do_quote(Object l, Env env);

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

const Object lisp_nullp = symbol_to_object("nullp");
Object do_nullp(Object lvals);

const Object lisp_stringp = symbol_to_object("stringp");
Object do_stringp(Object lvals);

const Object lisp_numberp= symbol_to_object("numberp");
Object do_numberp(Object lvals);

const Object lisp_symbolp = symbol_to_object("symbolp");
Object do_symbolp(Object lvals);

const Object lisp_listp = symbol_to_object("listp");
Object do_lisp(Object lvals);

const Object lisp_list = symbol_to_object("list");
Object do_list(Object lvals);

const Object lisp_error = symbol_to_object("error");
Object do_error(Object lvals);

const Object lisp_while = symbol_to_object("while");
Object do_while(Object l, Env env);

const Object lisp_define = symbol_to_object("define");
Object do_define(Object l, Env env);

const Object lisp_setq= symbol_to_object("set!");
Object do_setq(Object l, Env env);

const Object lisp_cond = symbol_to_object("cond");
Object do_cond(Object l, Env env);

const Object lisp_begin = symbol_to_object("begin");
Object do_begin(Object l, Env env);

const Object lisp_printenv = symbol_to_object("printenv");
Object do_printenv(Object l, Env env);

const Object lisp_debug = symbol_to_object("debug");
Object do_debug(Object l, Env env);

const Object lisp_load = symbol_to_object("load");
Object do_load(Object l, Env env);

const Object lisp_callcc = symbol_to_object("call/cc");
Object do_callcc(Object l, Env env);

const Object lisp_eval = symbol_to_object("eval");
Object do_eval(Object l, Env env);

const Object lisp_apply = symbol_to_object("apply");
Object do_apply(Object l, Env env);
