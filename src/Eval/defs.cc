#include "defs.hh"
#include "read.hh"
#include "eval.hh"
#include "error.hh"
#include "library.hh"
#include <iostream>

Object do_plus(Object lvals)
{
    Object a = car(lvals);
    Object b = cadr(lvals);
    return number_to_object( object_to_number(a)
                            + object_to_number(b) );
}

Object do_minus(Object lvals)
{
    Object a = car(lvals);
    Object b = cadr(lvals);
    return number_to_object( object_to_number(a)
                            - object_to_number(b) );
}

Object do_times(Object lvals)
{
    Object a = car(lvals);
    Object b = cadr(lvals);
    return number_to_object( object_to_number(a)
                            * object_to_number(b) );
}

Object do_eq(Object lvals)
{
    Object a = car(lvals);
    Object b = cadr(lvals);
    return bool_to_object( eq(a,b) );
}

Object do_inf(Object lvals)
{
    Object a = car(lvals);
    Object b = cadr(lvals);
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
    return l;
}

Object do_if (Object l, Env env)
{
    if (null(l) || null(cdr(l)))
    {
        error(l,env,"Cannot apply if: missing few arguements");
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
        error(l,env,"Cannot apply if: missing 'else' arguement");
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

/*
Object do_newline(Object lvals)
{
    return
}

Object do_end(Object lvals)
{
    return
}

Object do_nullp(Object lvals)
{
    return
}

Object do_stringp(Object lvals)
{
    return
}

Object do_numberp(Object lvals)
{
    return
}

Object do_listp(Object lvals)
{
    return
}

Object do_list(Object lvals)
{
    return
}

Object do_error(Object lvals)
{
    return
}
*/
