#include "defs.hh"
#include "read.hh"
#include "eval.hh"
#include "error.hh"
#include "library.hh"
#include "env.hh"
#include <iostream>

Object do_plus(Object lvals)
{
    if (null(lvals) || null(cdr(lvals)))
        {error ("Cannot apply +: missing few arguments");}
    Object a = car(lvals);
    Object b = cadr(lvals);
    if (!numberp(a) || !numberp(b))
        {error ("Cannot apply +: not a number");}
    return number_to_object( object_to_number(a)
                            + object_to_number(b) );
}

Object do_minus(Object lvals)
{
    if (null(lvals) || null(cdr(lvals)))
        {error ("Cannot apply -: missing few arguments");}
    Object a = car(lvals);
    Object b = cadr(lvals);
    if (!numberp(a) || !numberp(b))
        {error ("Cannot apply -: not a number");}
    return number_to_object( object_to_number(a)
                            - object_to_number(b) );
}

Object do_times(Object lvals)
{
    if (null(lvals) || null(cdr(lvals)))
        {error ("Cannot apply *: missing few arguments");}
    Object a = car(lvals);
    Object b = cadr(lvals);
    if (!numberp(a) || !numberp(b))
        {error ("Cannot apply *: not a number");}
    return number_to_object( object_to_number(a)
                            * object_to_number(b) );
}

Object do_eq(Object lvals)
{
    if (null(lvals) || null(cdr(lvals)))
        {error ("Cannot apply =: missing few arguments");}
    Object a = car(lvals);
    Object b = cadr(lvals);
    return bool_to_object( eq(a,b) );
}

Object do_inf(Object lvals)
{
    if (null(lvals) || null(cdr(lvals)))
        {error ("Cannot apply +: missing few arguments");}
    Object a = car(lvals);
    Object b = cadr(lvals);
    if (!numberp(a) || !numberp(b))
        {error ("Cannot apply <: not a number");}
    return bool_to_object( object_to_number(a) < object_to_number(b) );
}

Object do_concat(Object lvals)
{
    if (null(lvals))
    {
        return string_to_object("");
    }
    std::string s = object_to_string(car(lvals));
    std::string t = object_to_string(do_concat(cdr(lvals)));

    return string_to_object(s+t);
}

Object do_car(Object lvals)
{
    return car(car(lvals));
}

Object do_cdr(Object lvals)
{
    return cdr(car(lvals));
}

Object do_cons(Object lvals)
{
    return cons(car(lvals),(cadr(lvals)));
}

Object do_read(Object lvals)
{
    return read_object();
}

Object do_display(Object lvals)
{
    Object obj = car(lvals);
    print_object(std::cout,obj);
    std::cout<<std::flush;
    return obj;
}

/*******************************************/

Object do_quote (Object l, Env env)
{
    if (null(l))
    {
        error("Cannot quote");
    }
    return car(l);
}

Object do_if (Object l, Env env)
{
    if (null(l) || null(cdr(l)))
    {
        error("Cannot apply if: missing few arguements");
    }
    Object test = car(l);
    Object true_part = cadr(l);
    Object test_value = eval(test,env);

    if (object_to_bool(test_value))
    {
        return (eval(true_part,env));
    }
    if (null(cdr(l,1)))
    {
        error("Cannot apply if: missing 'else' argument");
    }
    Object false_part = car(l,2);
    return eval(false_part,env);
}

Object do_lambda (Object l, Env env)
{
    return l;
}

Object do_while(Object lvals, Env env)
{
    Object test_part = car(lvals);
    Object body_part = cadr(lvals);

    Object test_value = eval(test_part,env);

    while (object_to_bool(test_value))
    {
        eval(body_part,env);
    }
}

Object do_newline(Object lvals)
{
    std::cout<<std::endl;
    return nil();
}


Object do_nullp(Object lvals)
{
    return bool_to_object(null(car(lvals)));
}

Object do_stringp(Object lvals)
{
    return bool_to_object(stringp(car(lvals)));
}

Object do_numberp(Object lvals)
{
    return bool_to_object(numberp(car(lvals)));
}

Object do_listp(Object lvals)
{
    return bool_to_object(listp(car(lvals)));
}

Env do_define(Object lvals, Env env)
{
     if (null(lvals) || !symbolp(car(lvals)) || null(cdr(lvals)))
     {
          error("Cannot define it: missing few arguments");
     }
     std::string name = object_to_string(car(lvals));
     Object value = eval(cadr(lvals),env);
     std::cout << name << " = " << value << std::endl;
     return add_new_binding(name,value,env);
}

Object do_eval(Object l, Env env)
{
    if (null(l))
    {
        return l;
    }
    if (symbolp(l))
    {
        return eval(eval(l,env),env);
    }
    if (listp(l) && eq(car(l),lisp_quote))
    {
        return eval(cadr(l),env);
    }
    return eval(l,env);
}

/*
Object do_list(Object lvals)
{
    return
}

Object do_end(Object lvals)
{
    return
}

Object do_error(Object lvals)
{
    return
}*/
