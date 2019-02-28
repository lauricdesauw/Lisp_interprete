#include "env.hh"

Env make_env()
{
    Env new_env = Env();
    return new_env;
}

bool bidingp(Object obj)
{
    bool b0 = listp(obj);
    bool b1 = stringp(car(obj));
    bool b2 = null(cddr(obj));
    return (b0 && b1 && b2);
}

Env add_new_binding(std::string name, Object value, Env env)
{
    check(value);
    Object s = string_to_object(name);
    Object res = cons (s,cons(value,nil()));
    assert(bidingp(res));
    return cons(env,res);
}

Env extend_largs_env(Object lpars, Object lvals, Env env) {
    if (null(lpars))
    {
        if (!null(lvals))
        {
            throw Number_param_exception("Too many vals");
        }
        else
        {
            return env;
        }
    }
    else
    {
        if (null(lvals))
        {
            throw Number_param_exception("Too many parameters");
        }
        else
        {
            std::string name = object_to_string(car(lpars));
            Env new_env = add_new_binding(name,car(lvals),env);
            return extend_largs_env(cdr(lpars),cdr(lvals),env);
        }
    }
}

Object find_value(std::string name, Env env)
{
    Object head = car(env);
    std::string h_name = object_to_string(car(head));
    if (null(env))
    {
        throw No_binding_exception("'" + name + "'" + "Not found");
    }
    if (h_name == name)
    {
        return(cdr(head));
    }
    else
    {
        return(find_value(name, cdr(env)));
    }
}

std::ostream& print_binding(std::ostream& s, Object obj)
{
    assert(bidingp(obj));
    s << "| ( " << car(obj) << " = " << cdr(obj) << " ) ";
    return s;
}

std::ostream& print_env(std::ostream& s, Env env)
{
    if (null(env))
    {
    return s;
    }
    print_binding(s,car(env));
    print_env(s,cdr(env));
}
