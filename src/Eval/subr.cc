#include "subr.hh"
#include <cassert>
const bool subrp(Object obj)
{
    check(obj);
    assert(symbolp(obj));
    return ( eq(obj,lisp_plus) || eq(obj,lisp_times) || eq(obj,lisp_minus) || eq(obj,lisp_eq) || eq(obj,lisp_inf) || eq(obj,lisp_concat) );
}

const Object apply_subr(Object sub, Object lvals)
{
    check(sub);
    check(lvals);
    subrp(sub);
    if (eq(sub,lisp_plus))
    {
        do_plus(lvals);
    }
    if (eq(sub,lisp_times))
    {
        do_times(lvals);
    }
    if (eq(sub,lisp_minus))
    {
        do_minus(lvals);
    }
    if (eq(sub,lisp_eq))
    {
        do_eq(lvals);
    }
    if (eq(sub,lisp_inf))
    {
        do_inf(lvals);
    }
    if (eq(sub,lisp_concat))
    {
        do_concat(lvals);
    }
    if (eq(sub,lisp_car))
    {
        do_car(lvals);
    }
    if (eq(sub,lisp_cdr))
    {
        do_cdr(lvals);
    }
    if (eq(sub,lisp_cons))
    {
        do_cons(lvals);
    }
}
