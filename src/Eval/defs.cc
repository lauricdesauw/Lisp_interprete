#include "defs.hh"

Object do_if(Object l, Env env){}

Object do_plus(Object lvals)
{
    return( object_to_number(car(lvals)) + object_to_number(cadr(lvals)) );
}

Object do_minus(Object lvals)
{
    return( object_to_number(car(lvals)) - object_to_number(cadr(lvals)) );
}

Object do_times(Object lvals)
{
    return( object_to_number(car(lvals)) * object_to_number(cadr(lvals)) );
}

Object do_eq(Object lvals)
{
    return( eq(car(lvals),cadr(lvals)) );
}
