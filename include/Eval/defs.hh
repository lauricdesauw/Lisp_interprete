#pragma once

#include <string>
#include "library.hh"

const std::string lisp_lambda = "lambda";
Object do_lambda(Object l);

const std::string lisp_quote = "quote";
Object do_quote(Object l);

const std::string lisp_if = "if";
Object do_if(Object l, Env env);

const std::string lisp_plus = "+";
Object do_plus(Object lvals);

const std::string lisp_minus = "-";
Object do_minus(Object lvals);

const std::string lisp_times = "*";
Object do_times(Object lvals);

const std::string lisp_eq = "=";
Object do_eq(Object lvals);
