#pragma once

#include "library.hh"

const Object lisp_quit = symbol_to_object("quit");

const Object lisp_lambda = symbol_to_object("lambda");
Object do_lambda(Object l, Env env);

const Object lisp_quote = symbol_to_object("quote");
Object do_quote(Object l, Env env);

const Object lisp_if = symbol_to_object("if");
Object do_if(Object l, Env env);

const std::string lisp_plus = ("+");
Object do_plus(Object lvals);

const std::string lisp_minus = ("-");
Object do_minus(Object lvals);

const std::string lisp_times = ("*");
Object do_times(Object lvals);

const std::string lisp_eq = ("=");
Object do_eq(Object lvals);

const std::string lisp_inf = ("<");
Object do_inf(Object lvals);

const std::string lisp_concat = ("concat");
Object do_concat(Object lvals);

const std::string lisp_car = ("car");
Object do_car(Object lvals);

const std::string lisp_cdr = ("cdr");
Object do_cdr(Object lvals);

const std::string lisp_cons = ("cons");
Object do_cons(Object lvals);

const std::string lisp_read = ("read");
Object do_read(Object lvals);

const std::string lisp_display = ("display");
Object do_display(Object lvals);

const std::string lisp_newline = ("newline");
Object do_newline(Object lvals);

const std::string lisp_end = ("end");
Object do_end(Object lvals);

const std::string lisp_nullp = ("nullp");
Object do_nullp(Object lvals);

const std::string lisp_stringp = ("stringp");
Object do_stringp(Object lvals);

const std::string lisp_numberp= ("numberp");
Object do_numberp(Object lvals);

const std::string lisp_symbolp = ("symbolp");
Object do_symbolp(Object lvals);

const std::string lisp_listp = ("listp");
Object do_lisp(Object lvals);

const std::string lisp_list = ("list");
Object do_list(Object lvals);

const std::string lisp_error = ("error");
Object do_error(Object lvals);

const std::string lisp_while = ("while");
Object do_while(Object l, Env env);

const std::string lisp_define = ("define");
Object do_define(Object l, Env env);

const std::string lisp_setq= ("set!");
Object do_setq(Object l, Env env);

const std::string lisp_cond = ("cond");
Object do_cond(Object l, Env env);

const std::string lisp_begin = ("begin");
Object do_begin(Object l, Env env);

const std::string lisp_printenv = ("printenv");
Object do_printenv(Object l, Env env);

const std::string lisp_debug = ("debug");
Object do_debug(Object l, Env env);

const std::string lisp_load = ("load");
Object do_load(Object l, Env env);

const std::string lisp_callcc = ("call/cc");
Object do_callcc(Object l, Env env);

const std::string lisp_eval = ("eval");
Object do_eval(Object l, Env env);

const std::string lisp_apply = ("apply");
Object do_apply(Object l, Env env);
