#include <string>
#include <iostream>
#include "eval.hh"
#include "library.hh"


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
        return l;
    }
    else {return nil();}
}
