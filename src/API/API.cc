#include "API.hh"
#include "cell.hh"
#include "cell_subset.hh"
#include <cassert>

using namespace std;

// Consts

const Object API::object_nil = new Cell_symbol("nil") ;
const Object API::object_t = new Cell_symbol("#t");
const Object API::object_f = new Cell_symbol("#f");

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
    return l == object_t || l == object_f;
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
    return dynamic_cast<Cell_pair*>(l)->Cell_pair::get_car();
}


Object API::cdr(Object l)
{
    check(l);
    assert(l->get_type() == Cell::type::PAIR);
    return dynamic_cast<Cell_pair*>(l)->Cell_pair::get_cdr();
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
    if(a->get_type() != b->get_type()) {return false;}
    if(listp(a))
    {
        return ((dynamic_cast<Cell_pair*>(a)->get_car() ==
                    dynamic_cast<Cell_pair*>(b)->get_car()) &&
               (dynamic_cast<Cell_pair*>(a)->get_cdr() ==
                    dynamic_cast<Cell_pair*>(b)->get_cdr()) );
    }
    if (numberp(a))
    {
        return (((Cell_number*)a)->get_contents() ==
            ((Cell_number*)b)->get_contents());
    }
    if (symbolp(a))
    {
        return (((Cell_symbol*)a)->get_contents() ==
            ((Cell_symbol*)b)->get_contents());
    }
    if (stringp(a))
    {
        return (((Cell_string*)a)->get_contents() ==
            ((Cell_string*)b)->get_contents());
    }
    return false;
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
    if(s == "#t"){return object_t;}
    if(s == "#f"){return object_f;}
    return new Cell_symbol(s);
}

Object API::bool_to_object (bool b)
{
    if (b) { return t(); }
    return f();
}

int API::object_to_number (Object l)
{
    check(l);
    assert(numberp(l));
    return dynamic_cast<Cell_number*>(l)->get_contents();
}

std::string API::object_to_string (Object l)
{
    check(l);
    assert(stringp(l) || symbolp(l));
    if (stringp(l))
    {
        return dynamic_cast<Cell_string*>(l)->get_contents();
    }
    return dynamic_cast<Cell_symbol*>(l)->get_contents();
}

bool API::object_to_bool (Object l)
{
    check(l);
    if (l == object_f || null(l))
    {
        return false;
    }
    return true;
}
