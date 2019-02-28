#include "subr.hh"
#include <cassert>

const bool subrp(Object obj)
{
    check(obj);
    assert(symbolp(obj));
    std::string obj_s = object_to_string(obj);
    return ((obj_s == lisp_plus) ||
            (obj_s == lisp_times) ||
            (obj_s == lisp_minus) ||
            (obj_s == lisp_eq) ||
            (obj_s == lisp_inf) ||
            (obj_s == lisp_concat));
}

const Object apply_subr(Object sub, Object lvals)
{
    check(sub);
    check(lvals);
    std::string sub_string = object_to_string(sub);
    if (sub_string == lisp_plus)
    {
        return do_plus(lvals);
    }
    if (sub_string == lisp_times)
    {
        return do_times(lvals);
    }
    if (sub_string == lisp_minus)
    {
        return do_minus(lvals);
    }
    if (sub_string == lisp_eq)
    {
        return do_eq(lvals);
    }
    if (sub_string == lisp_inf)
    {
        return do_inf(lvals);
    }
    if (sub_string == lisp_concat)
    {
        return do_concat(lvals);
    }
    if (sub_string == lisp_car)
    {
        return do_car(lvals);
    }
    if (sub_string == lisp_cdr)
    {
        return do_cdr(lvals);
    }
    if (sub_string == lisp_cons)
    {
        return do_cons(lvals);
    }
}
