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
        {toplevel_error ("Cannot apply +: missing few arguments");}
    Object a = car(lvals);
    Object b = cadr(lvals);
    if (!numberp(a) || !numberp(b))
        {toplevel_error ("Cannot apply +: not a number");}
    return number_to_object( object_to_number(a)
                            + object_to_number(b) );
}

Object do_minus(Object lvals)
{
    if (null(lvals) || null(cdr(lvals)))
        {toplevel_error ("Cannot apply -: missing few arguments");}
    Object a = car(lvals);
    Object b = cadr(lvals);
    if (!numberp(a) || !numberp(b))
        {toplevel_error ("Cannot apply -: not a number");}
    return number_to_object( object_to_number(a)
                            - object_to_number(b) );
}

Object do_times(Object lvals)
{
    if (null(lvals) || null(cdr(lvals)))
        {toplevel_error ("Cannot apply *: missing few arguments");}
    Object a = car(lvals);
    Object b = cadr(lvals);
    if (!numberp(a) || !numberp(b))
        {toplevel_error ("Cannot apply *: not a number");}
    return number_to_object( object_to_number(a)
                            * object_to_number(b) );
}

Object do_eq(Object lvals)
{
    if (null(lvals) || null(cdr(lvals)))
        {toplevel_error ("Cannot apply =: missing few arguments");}
    Object a = car(lvals);
    Object b = cadr(lvals);
    return bool_to_object( eq(a,b) );
}

Object do_inf(Object lvals)
{
    if (null(lvals) || null(cdr(lvals)))
        {toplevel_error ("Cannot apply +: missing few arguments");}
    Object a = car(lvals);
    Object b = cadr(lvals);
    if (!numberp(a) || !numberp(b))
        {toplevel_error ("Cannot apply <: not a number");}
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
        toplevel_error("Cannot quote");
    }
    return car(l);
}

Object do_if (Object l, Env env)
{
    if (null(l) || null(cdr(l)))
    {
        toplevel_error("Cannot apply if: missing few arguements");
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
        toplevel_error("Cannot apply if: missing 'else' argument");
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
          toplevel_error("Cannot define it: missing few arguments");
     }
     Object value;
     if ( !null(cdr(lvals,1)) && listp(cadr(lvals)) && listp(car(lvals,2)))
     {
        Object param = cadr(lvals);
        Object func = cdr(lvals,1);
        value = cons(lisp_lambda,cons(param,func));;
     }
     else
     {
         value = eval(cadr(lvals),env);
     }
     std::string name = object_to_string(car(lvals));
     std::cout << name << " = " << value << std::endl;
     return add_new_binding(name,value,env);
}

Object do_eval(Object lvals, Env env)
{
    if (null(lvals))
    {
        return lvals;
    }
    if (symbolp(lvals))
    {
        return eval(eval(lvals,env),env);
    }
    if (listp(lvals) && eq(car(lvals),lisp_quote))
    {
        return eval(cadr(lvals),env);
    }
    return eval(lvals,env);
}

Object do_cond(Object lvals, Env env)
{
     if(null(lvals))
     {
          toplevel_error("Cannot apply cond : no valid predicate");
     }

     Object pred_part = car(lvals);

     if(null(pred_part) || null(cdr(pred_part)))
     {
          toplevel_error("Cannot apply cond : unvalid predicate");
     }

     Object cond_part = car(pred_part);
     Object body_part = cadr(pred_part);

     Object test_value = eval(cond_part,env);

     if(object_to_bool(test_value))
     {
          return eval(body_part,env);
     }
     return do_cond(cdr(lvals),env);
}
