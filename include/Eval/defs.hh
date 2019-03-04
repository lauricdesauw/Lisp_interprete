#pragma once

#include "library.hh"

/********* Adds to garbage collector root cells ***********/

void init_GC();

/************* Arithmetic operations ***********/

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

/************** String operations ***********/

const std::string lisp_concat = ("concat");
Object do_concat(Object lvals);


/************** List operations ************/

const std::string lisp_car = ("car");
Object do_car(Object lvals);

const std::string lisp_cdr = "cdr";
Object do_cdr(Object lvals);

const std::string lisp_cons = "cons";
Object do_cons(Object lvals);

/********* Type tests ***********/

const std::string lisp_nullp = "nullp";
Object do_nullp(Object lvals);

const std::string lisp_stringp = "stringp";
Object do_stringp(Object lvals);

const std::string lisp_numberp = "numberp";
Object do_numberp(Object lvals);

const std::string lisp_symbolp = "symbolp";
Object do_symbolp(Object lvals);

const std::string lisp_listp = "listp";
Object do_listp(Object lvals);

/***************** Loops and conditions ************/

const std::string lisp_if = "if";
Object do_if(Object l, Env env);

const std::string lisp_while = "while";
Object do_while(Object l, Env env);

const std::string lisp_cond = "cond";
Object do_cond(Object l, Env env);

const std::string lisp_or = "or";
Object do_or(Object lvals, Env env);

const std::string lisp_and = "and";
Object do_and(Object lvals, Env env);

const std::string lisp_not = "not";
Object do_not(Object lvals, Env env);

/****************** Environnement gestion *********************/

const std::string lisp_define = "define";
Env do_define(Object l, Env env);

const std::string lisp_definestat = "definestat";
Env do_definestat(Object l, Env env);

const std::string lisp_let = "let";
Object do_let(Object l, Env env);

const std::string lisp_setq = "set!";
Object do_setq(Object l, Env env);

/**************** Evaluation ********************/

const std::string lisp_lambda = "lambda";
Object do_lambda(Object l);

const std::string lisp_quote = "quote";
Object do_quote(Object l);

const std::string lisp_eval = "eval";
Object do_eval(Object l, Env env);

/********************* Global gestion ***************/

const std::string lisp_display = "display";
Object do_display(Object lvals);

const std::string lisp_read = "read";
Object do_read(Object lvals);

const std::string lisp_newline = "newline";
Object do_newline();

const std::string lisp_printenv = "printenv";

const std::string lisp_quit = "quit";

const std::string lisp_load = "load";

/**************** Debug and stats mode  ***********/


const std::string lisp_debug = "debug";
bool do_debug(Object l);

const std::string lisp_stats = "stats";
bool do_stats(Object l);
