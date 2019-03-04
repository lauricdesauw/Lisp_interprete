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
    Object function = car(l);
    if(symbolp(function))
    {
        std::string f_str = object_to_string(function);
        if (f_str == lisp_let) {return do_let(cdr(l),env);}
        if (f_str == lisp_lambda) {return do_lambda(l);}
        if (f_str == lisp_quote) {return do_quote(cdr(l));}
        if (f_str == lisp_if) {return do_if(cdr(l),env);}
        if (f_str == lisp_or) {return do_or(cdr(l),env);}
        if (f_str == lisp_and) {return do_and(cdr(l),env);}
        if (f_str == lisp_not) {return do_not(cdr(l),env);}
        if (f_str == lisp_cond) {return do_cond(cdr(l),env);}
        if (f_str == lisp_display) {return do_display(cdr(l));}
        if (f_str == lisp_eval) {return do_eval(cadr(l),env);}
        if (f_str == lisp_define)
        {toplevel_error("'define' must be used at toplevel: use 'let' keyword");}
        if (f_str == lisp_definestat)
        {toplevel_error("'definestat' must be used at toplevel");}
        if (f_str == lisp_debug)
        {toplevel_error("'debug' must be used at toplevel");}
        if (f_str == lisp_stats)
        {toplevel_error("'stats' must be used at toplevel");}
        if (f_str == lisp_printenv)
        {toplevel_error("'printenv' must be used at toplevel");}
    }
    Object eval_parameters = eval_list(cdr(l), env);
    return apply(function,eval_parameters, env);
}

/******************************************************************************/


Object apply (Object func, Object lvals, Env env)
{
    if (symbolp(func) && (object_to_string(func) == lisp_quit))
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
        Object new_func = eval(func,env);
        return apply(new_func,lvals,env);
    }
    assert(pairp(func));
    if(symbolp(car(func)) && (object_to_string(car(func)) == lisp_lambda))
    {
        // The body of the lambda-expression *)
        Object body = car(func,2);
        // The list of parameters of the lamba-expression *)
        Object lpars = cadr(func);
        Env new_env = Env();
        if(is_static(func))
        {
            try
            {
                new_env = extend_largs_env(lpars,lvals,get_closure(func));
            } catch(Evaluation_exception& e)
                {
                 std::string msg = e.what();
                 toplevel_error(object_to_string(func) + " : "+ msg);
                };
        }
        else
        {
            try
            {
                new_env = extend_largs_env(lpars,lvals,env);
            } catch(Evaluation_exception& e)
                {
                 std::string msg = e.what();
                 toplevel_error(object_to_string(func) + " : "+ msg);
                };
        }
        return eval(body,new_env);
    }
    else
    {
        toplevel_error("Cannot apply a list");
    }
    return nil();
}
