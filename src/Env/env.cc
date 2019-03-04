#include "env.hh"
#include "error.hh"

/********** Test functions **********/

bool bindingp(Object obj)
{
    if (!pairp(obj)) {return false;}
    if (!stringp(car(obj))) {return false;}
    if (null(cdr(obj))) {return false;}
    if (!null(cddr(obj))) {return false;}
    else {return true;}
}

/********** Update Environnement ***********/

Object binding_value(Object obj)
{
    return cadr(obj);
}

std::string binding_name(Object obj)
{
    return object_to_string(car(obj));
}


Env make_env()
{
    Env new_env = Env();
    return new_env;
}


Env add_new_binding(std::string name, Object value, Env env)
{
    check(value);
    Object s = string_to_object(name);
    Object res = cons (s,cons(value,nil()));
    assert(bindingp(res));
    return cons(res,env);
}

Env add_new_binding_stat(std::string name, Object value, Env env)
{
    check(value);
    Object s = string_to_object(name);
    set_closure(value,env);
    Object res = cons (s,cons(value,nil()));
    assert(bindingp(res));
    return cons(res,env);
}


Env extend_largs_env(Object lpars, Object lvals, Env env)
{
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
    return nil();
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
    std::string h_name = binding_name(head);
    if (h_name == name)
    {
        return(car(cdr(head)));
    }
    else
    {
        return(find_value(obj, cdr(env)));
    }
}

/********** Display functions ***********/

std::ostream& print_binding(std::ostream& s, Object obj)
{
    assert(bindingp(obj));
    Object val = binding_value(obj);
    s << "(" << binding_name(obj) << " = " << val;
    if(!is_static(val)) {
        s << " : closure";
        print_env(s,get_closure(val));
    }
    s << ")";
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
    return s;
}

std::ostream& print_env(std::ostream& s, Env env)
{
    s << "[";
    print_env_aux(s,env);
    s << "]";
    return s;
}
