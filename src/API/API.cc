#include "API.hh"

using namespace std;

bool is_const_object(Object l)
{
    return (l == API::object_nil || l == API::object_t || l == API::object_f);
}

void API::check(Object l)
{
    assert(l != 0);
    if(!is_const_object(l))
    {
        l->check();
    }
}

// Constants

 Object API::nil()
{
    return API::object_nil;
}

 bool API::null(Object l)
{
    API::check(l);
    return (l == API::object_nil);
}

 Object API::t()
{
    return API::object_t;
}

 API::Object f()
{
    return API::object_f;
}

// Type testers

 bool API::numberp(Object l)
{
    check(l);
    if(!is_const_object(l))
    {
        return l->get_type() == Cell::NUMBER;
    }
}

 bool API::stringp(Object l)
{
    check(l);
    if(!is_const_object(l))
    {
        return l->get_type() == Cell::STRING;
    }
}

 bool API::symbolp(Object l)
{
    check(l);
    if(!is_const_object(l))
    {
        return l->get_type() == Cell::SYMBOL;
    }
}

 bool API::listp(Object l)
{
    check(l);
    if(null(l))
    {
        return true;
    }
    if(!is_const_object(l))
    {
        return l->get_type() == Cell::PAIR;
    }
}

// List Operators

 Object API::cons(Object a, Object l)
{
    API::check(a);
    API::check(l);
    assert(listp(l));
    return new Cell_pair(*a,*l);
}

 Object API::car(Object l)
{
    API::check(l);
    assert(l->get_type() == Cell::PAIR);
    return l->get_car();
}


 Object API::cdr(Object l)
{
    API::check(l);
    assert(l->get_type() == Cell::PAIR);
    return l->get_cdr();
}

 bool API::eq(Object a, Object b)
{
    API::check(a);
    API::check(b);
    if(is_const_object(a) || is_const_object(b))
    {
        if(API::null(a) && API::null(b))
        {
            return true;
        }
        if(a == API::object_t && b == API::object_t)
        {
            return true;
        }
        if(a == API::object_f && b == API::object_f)
        {
            return true;
        }
        return false
    }
    else
    {
        assert(a->get_type() == b->get_type());
        if(l->get_type() == Cell::PAIR)
        {
            return API::eq(a->get_car(),b->get_car()) && API::eq(a->get_cdr(),b->get_cdr());
        }
        else
        {
            return (a->get_contents() == b->get_contents());
        }
    }
}
