#include "defs.hh"
#include "read.hh"
#include "eval.hh"
#include "error.hh"
#include "library.hh"
#include "env.hh"
#include <iostream>

/*------------- Adds to garbage collector root cells----------------------*/
void init_GC()
{
    add_to_GC_root(t());
    add_to_GC_root(f());
    add_to_GC_root(nil());
}

/*-------------------- Other ------------------------------*/

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
        {toplevel_error ("Cannot apply <: missing few arguments");}
    Object a = car(lvals);
    Object b = cadr(lvals);
    if (!numberp(a) || !numberp(b))
        {toplevel_error ("Cannot apply <: not a number");}
    return bool_to_object( object_to_number(a) < object_to_number(b) );
}

/************* String operations **********/

Object do_concat_aux(Object lvals, bool b)
{
    if (null(lvals))
    {
        return string_to_object("");
    }
    if (!stringp(car(lvals)))
    {
        toplevel_error("Cannot apply concat: arguments must be string");
    }
    std::string s = object_to_string(car(lvals));
    if (b)
    {
        s = s.substr(0,s.size() - 1);
    }
    else
    {
        s = s.substr(1,s.size() - 1);
    }
    std::string t = object_to_string(do_concat_aux(cdr(lvals),!b));
    return string_to_object(s+t);
}

Object do_concat(Object lvals)
{
    return do_concat_aux(lvals,true);
}

/************* List operations **********/

Object do_car(Object lvals)
{
    if (null(lvals) || !listp(lvals) || null(car(lvals)))
    {
        toplevel_error("Cannot apply car: must a no-empty list in argument");
    }
    return car(car(lvals));
}

Object do_cdr(Object lvals)
{
    if (null(lvals) || !listp(lvals) || null(car(lvals)))
    {
        toplevel_error("Cannot apply cdr: must a no-empty list in argument");
    }
    return cdr(car(lvals));
}

Object do_cons(Object lvals)
{
    if (null(lvals) || !listp(lvals) || null(car(lvals)) || null(cdr(lvals)))
    {
        toplevel_error("Cannot apply car: must a no-empty list in argument");
    }
    return cons(car(lvals),(cadr(lvals)));
}

/************* Type tests **********/

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

Object do_symbolp(Object lvals)
{
    return bool_to_object(symbolp(car(lvals)));
}

Object do_listp(Object lvals)
{
    return bool_to_object(listp(car(lvals)));
}

/***************** Loops and conditions ************/

Object do_if (Object lvals, Env env)
{
    if (null(lvals) || null(cdr(lvals)))
    {
        toplevel_error("Cannot apply if: missing few arguements");
    }
    Object test = car(lvals);
    Object true_part = cadr(lvals);
    Object test_value = eval(test,env);

    if (object_to_bool(test_value))
    {
        return (eval(true_part,env));
    }
    if (null(cdr(lvals,1)))
    {
        return nil();
    }
    Object false_part = car(lvals,2);
    return eval(false_part,env);
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
    return nil();
}

Object do_cond(Object lvals,Env env)
{
    if(null(lvals))
    {
        return nil();
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

Object do_or (Object lvals, Env env)
{
    if(null(lvals))
    {
        toplevel_error("Cannot apply or : not enough arguments");
    }
    if(null(cdr(lvals)))
    {
        toplevel_error("Cannot apply or : not enough arguments");
    }
    Object first_part = car(lvals);
    Object second_part = cadr(lvals);

    bool first_value = object_to_bool(eval(first_part,env));
    bool second_value = object_to_bool(eval(second_part,env));
    bool value = first_value || second_value;
    return bool_to_object(value);
}

Object do_and (Object lvals, Env env)
{
    if(null(lvals))
    {
        toplevel_error("Cannot apply and : not enough arguments");
    }
    if(null(cdr(lvals)))
    {
        toplevel_error("Cannot apply and : not enough arguments");
    }
    Object first_part = car(lvals);
    Object second_part = cadr(lvals);

    bool first_value = object_to_bool(eval(first_part,env));
    bool second_value = object_to_bool(eval(second_part,env));
    bool value = first_value && second_value;
    return bool_to_object(value);
}

Object do_not (Object lvals, Env env)
{
    if(null(lvals))
    {
        toplevel_error("Cannot apply not : not enough arguments");
    }
    Object first_part = car(lvals);

    bool value = object_to_bool(eval(first_part,env));

    return bool_to_object(!value);
}

/****************** Environnement gestion *********************/

Env do_define(Object lvals, Env env)
{
    if (null(lvals) || null(cdr(lvals)))
    {
        toplevel_error("Cannot define it: missing few arguments");
    }
    if (!symbolp(car(lvals)) && !listp(car(lvals)))
    {
        toplevel_error("Cannot define it: first element must be a symbol or a list");
    }
    Object value;
    std::string name;
    if (listp(car(lvals)))
    {
        if (null(car(lvals)))
        {
            toplevel_error("Cannot define it: first element cannot be nil");
        }
        name = object_to_string(car(car(lvals)));
        Object param = cdr(car(lvals));
        Object func = cdr(lvals);
        value = cons(symbol_to_object(lisp_lambda),cons(param,func));;
    }
    else
    {
        name = object_to_string(car(lvals));
        value = eval(cadr(lvals),env);
    }
    std::cout << name << " = " << value << std::endl;
    return add_new_binding(name,value,env);
}

Env do_definestat(Object lvals, Env env)
{
    if (null(lvals) || null(cdr(lvals)))
    {
        toplevel_error("Cannot define it: missing few arguments");
    }
    if (!symbolp(car(lvals)) && !listp(car(lvals)))
    {
        toplevel_error("Cannot define it: first element must be a symbol or a list");
    }
    Object value;
    std::string name;
    if (listp(car(lvals)))
    {
        if (null(car(lvals)))
        {
            toplevel_error("Cannot define it: first element cannot be nil");
        }
         name = object_to_string(car(car(lvals)));
         Object param = cdr(car(lvals));
         Object func = cdr(lvals);
         value = cons(symbol_to_object(lisp_lambda),cons(param,func));
    }
    else
    {
        name = object_to_string(car(lvals));
        value = eval(cadr(lvals),env);
    }
    std::cout << name << " = " << value << std::endl;
    return add_new_binding_stat(name,value,env);
}

Object do_let (Object lvals, Env env)
{
    if ( null(lvals) || null(cdr(lvals)))
    {
        return nil();
    }
    Object var = car(lvals);
    Object param = nil();
    Object value = nil();
    while (!null(var))
    {
        if (!listp(car(var)))
        {
            toplevel_error("Cannot apply let: arguments must be lists");
        }
        if (!null(car(var)) && null(cdr(car(var))))
        {
            toplevel_error("Cannot apply let: arguments must have 2 elements");
        }
        if (!null(car(var)))
        {
            param = cons(car(car(var)),param);
            if (!symbolp(param))
            {
                toplevel_error("Cannot apply let: names must be symbols");
            }
            value = cons(cadr(car(var)),value);
        }
        var = cdr(var);
    }
    Object func = cons(symbol_to_object(lisp_lambda),cons(param,cdr(lvals)));
    return eval(cons(func,value),env);
}

/**************** Evaluation ********************/

Object do_lambda (Object lvals)
{
    return lvals;
}

Object do_quote (Object lvals)
{
    if (null(lvals))
    {
        toplevel_error("Cannot quote");
    }
    return car(lvals);
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
    if (listp(lvals) && eq(car(lvals),symbol_to_object(lisp_quote)))
    {
        return eval(cadr(lvals),env);
    }
    return eval(lvals,env);
}

/********************* Global gestion ***************/

Object do_display(Object lvals)
{
    Object obj = car(lvals);
    print_object(std::cout,obj);
    std::cout<<std::flush;
    return obj;
}

Object do_read()
{
    return read_object();
}

Object do_newline()
{
    std::cout<<std::endl;
    return nil();
}

/**************** Debug and stats mode  ***********/

bool do_debug(Object l)
{
    if (null(l) || !boolp(car(l)))
    {
        toplevel_error("Cannot use debug mode: not a bool");
    }
    return (object_to_bool(car(l)));
}

bool do_stats(Object l)
{
    if (null(l) || !boolp(car(l)))
    {
        toplevel_error("Cannot use stats mode: not a bool");
    }
    return (object_to_bool(car(l)));
}
