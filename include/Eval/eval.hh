#pragma once

#include "globals.hh"

Object eval(Object l, Env env);
Object apply(Object f, Object lvals, Env env);
