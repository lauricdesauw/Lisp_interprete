#include <string>
#include <stdexcept>
#include <iostream>
#include <cassert>
#include "eval.hh"
#include "library.hh"
#include "subr.hh"
#include "defs.hh"
#include "error.hh"
#include "env.hh"

Object eval_list (Object l, Env env)
{
    if (null(l)) {return l;}

    Object el = eval(car(l),env);
    return cons(el,eval_list(cdr(l),env));
}

Object eval (Object l, Env env)
{
    if (null(l) || stringp(l) || numberp(l) || boolp(l))
    {
        return l;
    }
    if (symbolp(l)) {return find_value(l,env);}

    assert(listp(l));
    Object func = car(l);

    if (eq(func, lisp_lambda)) {return l;}
    if (eq(func, lisp_quote)) {return do_quote(cdr(l),env);}
    if (eq(func, lisp_if)) {return do_if(cdr(l),env);}
    if (eq(func, lisp_printenv)) {return do_printenv(cdr(l),env);}
    Object eval_parameters = eval_list(cdr(l), env);
    return apply(func,eval_parameters, env);
}

Object apply (Object func, Object lvals, Env env)
{
    if (eq(func,lisp_quit))
    {
        quit();
    }
    if(null(func))
    {
        error(func,env,"Cannot apply nil");
    }
    if(func == t())
    {
        error(func,env,"Cannot apply true");
    }
    if(func == f())
    {
        error(func,env,"Cannot apply false");
    }
    if(numberp(func))
    {
        error(func,env,"Cannot apply a number");
    }
    if(stringp(func))
    {
        error(func,env,"Cannot apply a string");
    }
    if (subrp(func))
    {
        return (apply_subr(func,lvals));
    }
    if(symbolp(func))
    {
        return apply(eval(func,env),lvals,env);
    }
/*    else
    {
        assert(pairp(f));
        if(car(f)  = lisp_lambda)
        {
            // The body of the lambda-expression *)
            Object body = car(func,2);
            // The list of parameters of the lamba-expression *)
            Object lpars = cadr(func);
            Env new_env = extend_largs_env( lpars, lvals, env);
            eval( body, new_env);
        }
        else
        {
            throw new Evaluation_exception(f,env,"Cannot apply a list");
            /*new_f = eval f env
            eval (cons new_f lvals) env )*//*
        }
    }*/
}
