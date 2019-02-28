#include <string>
#include <iostream>
#include "eval.hh"
#include "library.hh"

Object get_value_env(Object l, Env env)
{
    
}

Object eval (Object l, Env env)
{
    if (null(l) || stringp(l) || numberp(l))
    {
        return l;
    }
    else if (symbolp(l))
    {
        std::string s = object_to_string(l);
        if (s == "#t")
        {
            return t();
        }
        else if (s == "#f")
        {
            return f();
        }
        else if (s == "nil")
        {
            return nil();
        }
        return get_value_env(l,env);
    }
    else {return nil();}
}
