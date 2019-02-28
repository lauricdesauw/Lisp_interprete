#include <string>
#include <iostream>
#include <cassert>
#include "eval.hh"
#include "library.hh"
#include "defs.hh"

Object get_value_env(Object l, Env env)
{

}

Object eval (Object l, Env env)
{
    if (null(l) || stringp(l) || numberp(l) || boolp(l))
    {
        return l;
    }
    else if (symbolp(l))
    {
        return get_value_env(l,env);
    }
    else
    {
        assert(listp(l));
        Object f = car(l);
        return (nil());
    }
}
