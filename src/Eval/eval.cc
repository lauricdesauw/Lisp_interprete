#include <string>
#include <stdexcept>
#include <iostream>
#include <cassert>
#include "eval.hh"
#include "library.hh"
#include "defs.hh"
#include "subr.hh"


Evaluation_exception::Evaluation_exception(Object _obj,
                                           Env _env,
                                           string _message):
    std::runtime_error(_message),
    obj(_obj),
    env(_env),
    message(_message)
{};


Object get_value_env(Object l, Env env)
{
    return l;
}

Object eval (Object l, Env env)
{
    if (null(l) || stringp(l) || numberp(l) || boolp(l))
    {
        return l;
    }
    else if (symbolp(l))
    {
        return get_value_env(l,env);
    }
    else
    {
        assert(listp(l));
        Object f = car(l);
        return (number_to_object(1));
    }
}


Object apply (Object func, Object lvals, Env env)
{
    if(null(func))
    {
        throw Evaluation_exception(func,env,"Cannot apply nil");
    }
    if(func == t())
    {
        throw Evaluation_exception(func,env,"Cannot apply true");
    }
    if(func == f())
    {
        throw Evaluation_exception(func,env,"Cannot apply false");
    }
    if(numberp(func))
    {
        throw Evaluation_exception(func,env,"Cannot apply a number");
    }
    if(stringp(func))
    {
        throw Evaluation_exception(func,env,"Cannot apply a string");
    }
    if (subrp(func))
    {
        return (apply_subr(func,lvals));
    }
    if(symbolp(func))
    {
        return apply(eval(func,env),lvals,env);
    }
    /*else
    {
        assert(pairp(f));
        if(car(f)  = lisp_lambda)
        {
            // The body of the lambda-expression *)
            Object body = caddr f;
            // The list of parameters of the lamba-expression *)
            Object lpars = cadr f;
            Env new_env = extend_largs_env lpars lvals env in
            eval body new_env
        }
        else
        {
            throw new Evaluation_exception(f,env,"Cannot apply a list");
            let new_f = eval f env in
            eval (cons new_f lvals) env )
        }
    }*/
}
