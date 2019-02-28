#include "defs.hh"
#include "read.hh"
#include "library.hh"

Object do_plus(Object lvals)
{
    return number_to_object( object_to_number(car(lvals))
                            + object_to_number(cadr(lvals)) );
}

Object do_minus(Object lvals)
{
    return number_to_object( object_to_number(car(lvals))
                            - object_to_number(cadr(lvals)) );
}

Object do_times(Object lvals)
{
    return number_to_object( object_to_number(car(lvals))
                            * object_to_number(cadr(lvals)) );
}

Object do_eq(Object lvals)
{
    return number_to_object( eq(car(lvals),cadr(lvals)) );
}

Object do_inf(Object lvals)
{
    return number_to_object( object_to_number(car(lvals)) < object_to_number(cadr(lvals)) );
}

Object do_concat(Object lvals)
{
    if (nullp(lvals)
    {
        return string_to_object("");
    }
    std::string s = object_to_string(car(lvals));
    std::strings t = object_to_string(do_concat(cdr(lvals)));

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
    return cons(car(lvals),(cadr(lvals));
}

Object do_read(Object lvals)
{
    return read_object();
}

Object do_display(Object lvals)
{
    Object onj = car(lvals);
    print_object(obj);
    //flush stdout
    //
    return obj;
}

Object do_newline(Object lvals)
{
    return 
}

Object do_end(Object lvals)
{
    return
}

Object do_nullp(Object lvals)
{
    return
}

Object do_stringp(Object lvals)
{
    return
}

Object do_numberp(Object lvals)
{
    return
}

Object do_listp(Object lvals)
{
    return
}

Object do_list(Object lvals)
{
    return
}

Object do_error(Object lvals)
{
    return
}
