#pragma once

#include "library.hh"

/************* Arithmetic operations **********/

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

/************** String operations ***********/

const std::string lisp_concat = ("concat");
Object do_concat(Object lvals);

/************** List operations ************/

const std::string lisp_car = ("car");
Object do_car(Object lvals);

const std::string lisp_cdr = ("cdr");
Object do_cdr(Object lvals);

const std::string lisp_cons = ("cons");
Object do_cons(Object lvals);

/************** Type tests **************/

const std::string lisp_nullp = ("nullp");
Object do_nullp(Object lvals);

const std::string lisp_stringp = ("stringp");
Object do_stringp(Object lvals);

const std::string lisp_numberp= ("numberp");
Object do_numberp(Object lvals);

const std::string lisp_symbolp = ("symbolp");
Object do_symbolp(Object lvals);

const std::string lisp_listp = ("listp");
Object do_listp(Object lvals);

/***************** Loops and conditions ************/

const Object lisp_if = symbol_to_object("if");
Object do_if(Object l, Env env);

const std::string lisp_while = ("while");
Object do_while(Object l, Env env);

const Object lisp_cond = symbol_to_object("cond");
Object do_cond(Object l, Env env);

const Object lisp_or = symbol_to_object("or");
Object do_or(Object lvals, Env env);

const Object lisp_and = symbol_to_object("and");
Object do_and(Object lvals, Env env);

const Object lisp_not = symbol_to_object("not");
Object do_not(Object lvals, Env env);

/****************** Environnement gestion *********************/

const Object lisp_define = symbol_to_object("define");
Env do_define(Object l, Env env);

const Object lisp_definestat = symbol_to_object("definestat");
Env do_definestat(Object l, Env env);

const Object lisp_let = symbol_to_object("let");
Object do_let(Object l, Env env);

/**************** Evaluation ********************/

const Object lisp_lambda = symbol_to_object("lambda");
Object do_lambda(Object l);

const Object lisp_quote = symbol_to_object("quote");
Object do_quote(Object l);

const Object lisp_eval = symbol_to_object("eval");
Object do_eval(Object l, Env env);

/********************* Global gestion ***************/

const std::string lisp_load = ("load");

const Object lisp_quit = symbol_to_object("quit");

const Object lisp_printenv = symbol_to_object("printenv");

const Object lisp_display = symbol_to_object("display");
Object do_display(Object lvals);

const std::string lisp_read = ("read");
Object do_read();

const std::string lisp_newline = ("newline");
Object do_newline();

/**************** Debug and stats mode  ***********/

const Object lisp_debug = symbol_to_object("debug");
bool do_debug(Object l);

const Object lisp_stats = symbol_to_object("stats");
bool do_stats(Object l);
