#include "API.hh"
#include "cell.hh"
#include "cell_subset.hh"
#include <cassert>

using namespace std;

bool API::const_objectp(Object l)
{
    return (l == object_nil || l == object_t || l == object_f);
}

void API::check(Object l)
{
    assert(l != 0);
    if(!const_objectp(l))
    {
        l->check();
    }
}

// Constants

Object API::nil()
{
    return object_nil;
}

bool API::null(Object l)
{
    check(l);
    return (l == object_nil);
}

Object API::t()
{
    return API::object_t;
}

Object API::f()
{
    return API::object_f;
}

// Type testers

bool API::numberp(Object l)
{
    check(l);
    if(!is_const_object(l))
    {
        return l->get_type() == Cell::type::NUMBER;
    }
}

bool API::stringp(Object l)
{
    check(l);
    if(!is_const_object(l))
    {
        return l->get_type() == Cell::type::STRING;
    }
}

bool API::symbolp(Object l)
{
    check(l);
    if(!is_const_object(l))
    {
        return l->get_type() == Cell::type::SYMBOL;
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
        return l->get_type() == Cell::type::PAIR;
    }
}

// List Operators

Object API::cons(Object a, Object l)
{
    API::check(a);
    API::check(l);
    assert(listp(l));
    return new Cell_pair(a,l);
}

Object API::car(Object l)
{
    API::check(l);
    assert(l->get_type() == Cell::type::PAIR);
    return ((Cell_pair*)l)->Cell_pair::get_car();
}


Object API::cdr(Object l)
{
    API::check(l);
    assert(l->get_type() == Cell::type::PAIR);
    return ((Cell_pair*)l)->Cell_pair::get_cdr();
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
        return false;
    }
    else
    {
        assert(a->get_type() == b->get_type());
        if(a->get_type() == Cell::type::PAIR)
        {
            return API::eq(((Cell_pair*)a)->get_car(),
                            ((Cell_pair*)b)->get_car()) &&
                        API::eq(((Cell_pair*)a)->get_cdr(),
                                ((Cell_pair*)b)->get_cdr());
        }
        else if (a->get_type() == Cell::type::NUMBER)
        {
            return (((Cell_number*)a)->get_contents() ==
                ((Cell_number*)b)->get_contents());
        }
    }
}

// Object conversion

Object API::number_to_object (int n)
{
    Cell_number::Cell_number(n);
}

Object API::string_to_object (std::string s)
{
    Cell_string::Cell_string(s);
}

Object API::symbol_to_object (std::string s)
{
    Cell_symbol::Cell_symbol(s);
}

Object API::bool_to_object (bool b)
{
    if (b) {t();}
    else {f();}
}

int API::object_to_number (Object l)
{
    API::check(l);
    assert(numberp(l));
    return (((Cell_number*)l)->get_contents());
}

std::string API::object_to_string (Object l)
{
    API::check(l);
    assert(stringp(l));
    return (((Cell_string*)l)->get_contents());
}

bool API::object_to_bool (Object l)
{
    API::check(l);
    assert (l == object_t || l == object_f);
    if (l == object_t) {return true;}
    else {return false;}
}
