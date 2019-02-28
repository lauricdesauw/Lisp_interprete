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
        return do_plus(lvals);
    }
    if (eq(sub,lisp_times))
    {
        return do_times(lvals);
    }
    if (eq(sub,lisp_minus))
    {
        return do_minus(lvals);
    }
    if (eq(sub,lisp_eq))
    {
        return do_eq(lvals);
    }
    if (eq(sub,lisp_inf))
    {
        return do_inf(lvals);
    }
    if (eq(sub,lisp_concat))
    {
        return do_concat(lvals);
    }
    if (eq(sub,lisp_car))
    {
        return do_car(lvals);
    }
    if (eq(sub,lisp_cdr))
    {
        return do_cdr(lvals);
    }
    if (eq(sub,lisp_cons))
    {
        return do_cons(lvals);
    }
}
