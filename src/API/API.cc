#include "API.hh"
#include <cassert>

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
    assert(l->get_type() == Cell::type::PAIR);
    return l->Cell_pair::get_car();
}


 Object API::cdr(Object l)
{
    API::check(l);
    assert(l->get_type() == Cell::type::PAIR);
    return l->Cell_pair::get_cdr();
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

// Object conversion

static Object API::number_to_object (int n)
{
    Cell_number::Cell_number (n);
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
    return (l->get_contents());
}

 std::string API::object_to_string (Object l)
{
    API::check(l);
    assert(stringp(l));
    return (l->get_contents());
}

 bool API::object_to_bool (Object l)
{
    API::check(l);
    assert (l == object_t || l == object_f);
    if (l == object_t) {return true;}
    else {return false;}
}
