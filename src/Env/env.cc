#include "env.hh"
#include "error.hh"

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
    return cons(res,env);
}

Env extend_largs_env(Object lpars, Object lvals, Env env) {
    if (null(lpars))
    {
        if (!null(lvals))
        {
            eval_error("Too many vals");
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
            eval_error("Too many parameters");
        }
        else
        {
            std::string name = object_to_string(car(lpars));
            Env new_env = add_new_binding(name,car(lvals),env);
            return extend_largs_env(cdr(lpars),cdr(lvals),new_env);
        }
    }
}

Object find_value(Object obj, Env env)
{
    assert(symbolp(obj));
    std::string name = object_to_string(obj);
    if (null(env))
    {
        eval_error("'" + name + "' " + "Not found");
    }
    Object head = car(env);
    std::string h_name = object_to_string(car(head));
    if (h_name == name)
    {
        return(car(cdr(head)));
    }
    else
    {
        return(find_value(obj, cdr(env)));
    }
}

std::ostream& print_binding(std::ostream& s, Object obj)
{
    assert(bidingp(obj));
    s << "(" << car(obj) << " = " << cadr(obj) << ")";
    return s;
}

std::ostream& print_env_aux(std::ostream& s, Env env)
{
    if (null(env))
    {
        return s;
    }
    print_binding(s,car(env));
    if (!null(cdr(env))) {
        s << " | ";
    }
    print_env_aux(s,cdr(env));
}

std::ostream& print_env(std::ostream& s, Env env)
{
    s << "[";
    print_env_aux(s,env);
    s << "]";
    return s;
}
