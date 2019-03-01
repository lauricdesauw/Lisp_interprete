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
    if (symbolp(l)) {
         try
         {
              return find_value(l,env);
         } catch(Evaluation_exception& e)
         {
              std::string msg = e.what();
              toplevel_error(object_to_string(l) + " : "+ msg);
         };
    }

    assert(listp(l));
    Object func = car(l);

    if (eq(func,lisp_let)) {return do_let(cdr(l),env);}
    if (eq(func, lisp_lambda)) {return do_lambda(l,env);}
    if (eq(func, lisp_quote)) {return do_quote(cdr(l),env);}
    if (eq(func, lisp_if)) {return do_if(cdr(l),env);}
    if (eq(func, lisp_cond)) {return do_cond(cdr(l),env);}
    if (eq(func,lisp_eval)) {return do_eval(cadr(l),env);}

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
        toplevel_error("Cannot apply nil");
    }
    if(func == t())
    {
        toplevel_error("Cannot apply true");
    }
    if(func == f())
    {
        toplevel_error("Cannot apply false");
    }
    if(numberp(func))
    {
        toplevel_error("Cannot apply a number");
    }
    if(stringp(func))
    {
        toplevel_error("Cannot apply a string");
    }
    if (subrp(func))
    {
        return (apply_subr(func,lvals));
    }
    if(symbolp(func))
    {
        return apply(eval(func,env),lvals,env);
    }
    else
    {
        assert(pairp(func));
        if(eq(car(func),lisp_lambda))
        {
            // The body of the lambda-expression *)
            Object body = car(func,2);
            // The list of parameters of the lamba-expression *)
            Object lpars = cadr(func);
            try
            {
                 Env new_env = extend_largs_env(lpars,lvals,env);
                 return eval(body,new_env);
            } catch(Evaluation_exception& e)
            {
                 std::string msg = e.what();
                 toplevel_error(object_to_string(func) + " : "+ msg);
            };

        }
        else
        {
            toplevel_error("Cannot apply a list");
        }
    }
}
