#include "subr.hh"
#include <cassert>

const bool subrp(Object obj)
{
    check(obj);
    if (!symbolp(obj)) {return false;}
    std::string obj_s = object_to_string(obj);
    return ((obj_s == lisp_plus) ||
            (obj_s == lisp_times) ||
            (obj_s == lisp_minus) ||
            (obj_s == lisp_eq) ||
            (obj_s == lisp_inf) ||
            (obj_s == lisp_concat) ||
            (obj_s == lisp_numberp) ||
            (obj_s == lisp_stringp) ||
            (obj_s == lisp_listp) ||
            (obj_s == lisp_nullp) ||
            (obj_s == lisp_newline) ||
            (obj_s == lisp_car) ||
            (obj_s == lisp_cdr) ||
            (obj_s == lisp_cons));
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
    if (sub_string == lisp_numberp)
    {
        return do_numberp(lvals);
    }
    if (sub_string == lisp_stringp)
    {
        return do_stringp(lvals);
    }
    if (sub_string == lisp_listp)
    {
        return do_listp(lvals);
    }
    if (sub_string == lisp_nullp)
    {
        return do_nullp(lvals);
    }
    if (sub_string == lisp_newline)
    {
        return do_newline(lvals);
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
