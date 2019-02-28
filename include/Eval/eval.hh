#pragma once

#include "library.hh"

using namespace std;

Object eval(Object l, Env env);
Object apply(Object f, Object lvals, Env env);
