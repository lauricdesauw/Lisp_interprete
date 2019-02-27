#include "API.hh"
#include "cell.hh"
#include "cell_subset.hh"
#include <cassert>

using namespace std;

// Consts

const Object API::object_nil = *(new Object());
const Object API::object_t = *(new Object());
const Object API::object_f = *(new Object());

// Else

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
    return object_t;
}

Object API::f()
{
    return object_f;
}

// Type testers

bool API::numberp(Object l)
{
    check(l);
    if(!const_objectp(l))
    {
        return l->get_type() == Cell::type::NUMBER;
    }
    return false;
}

bool API::stringp(Object l)
{
    check(l);
    if(!const_objectp(l))
    {
        return l->get_type() == Cell::type::STRING;
    }
    return false;
}

bool API::symbolp(Object l)
{
    check(l);
    if(!const_objectp(l))
    {
        return l->get_type() == Cell::type::SYMBOL;
    }
    return false;
}

bool API::boolp(Object l)
{
    return const_objectp(l) && (l != object_nil);
}

bool API::listp(Object l)
{
    check(l);
    if(null(l))
    {
        return true;
    }
    if(!const_objectp(l))
    {
        return l->get_type() == Cell::type::PAIR;
    }
    return false;
}

// List Operators

Object API::cons(Object a, Object l)
{
    check(a);
    check(l);
    assert(listp(l));
    return new Cell_pair(a,l);
}

Object API::car(Object l)
{
    check(l);
    assert(l->get_type() == Cell::type::PAIR);
    return ((Cell_pair*)l)->Cell_pair::get_car();
}


Object API::cdr(Object l)
{
    check(l);
    assert(l->get_type() == Cell::type::PAIR);
    return ((Cell_pair*)l)->Cell_pair::get_cdr();
}

bool API::eq(Object a, Object b)
{
    check(a);
    check(b);
    if(const_objectp(a) || const_objectp(b))
    {
        if(null(a) && null(b))
        {
            return true;
        }
        if(a == object_t && b == object_t)
        {
            return true;
        }
        if(a == object_f && b == object_f)
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
            return eq(((Cell_pair*)a)->get_car(),
                            ((Cell_pair*)b)->get_car()) &&
                        eq(((Cell_pair*)a)->get_cdr(),
                                ((Cell_pair*)b)->get_cdr());
        }
        else if (a->get_type() == Cell::type::NUMBER)
        {
            return (((Cell_number*)a)->get_contents() ==
                ((Cell_number*)b)->get_contents());
        }
        else if (a->get_type() == Cell::type::SYMBOL)
        {
            return (((Cell_symbol*)a)->get_contents() ==
                ((Cell_symbol*)b)->get_contents());
        }
        else if (a->get_type() == Cell::type::STRING)
        {
            return (((Cell_string*)a)->get_contents() ==
                ((Cell_string*)b)->get_contents());
        }
        else
        {
            return false;
        }
    }
}

// Object conversion

Object API::number_to_object (int n)
{
    return new Cell_number(n);
}

Object API::string_to_object (std::string s)
{
    return new Cell_string(s);
}

Object API::symbol_to_object (std::string s)
{
    return new Cell_symbol(s);
}

Object API::bool_to_object (bool b)
{
    if (b)
    {
        return t();
    }
    else
    {
        return f();
    }
}

int API::object_to_number (Object l)
{
    check(l);
    assert(numberp(l));
    return (((Cell_number*)l)->get_contents());
}

std::string API::object_to_string (Object l)
{
    check(l);
    assert(stringp(l) | symbolp(l));
    return (((Cell_string*)l)->get_contents());
}

bool API::object_to_bool (Object l)
{
    check(l);
    assert (l == object_t || l == object_f);
    if (l == object_t)
    {
        return true;
    }
    else
    {
        return false;
    }
}
