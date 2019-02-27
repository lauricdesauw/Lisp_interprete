#include "API.hh"
#include <cassert>

using namespace std;

 void API::check(Object l)
{
    assert(l != 0);
    l->check();
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

// List Operators

 Object API::cons(Object a, Object l)
{
    API::check(a);
    API::check(l);
    assert(API::null(l) || l->get_type() == Cell::type::PAIR);
    return new Cell_pair(a,l);
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

 Object API::number_to_object (int n)
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
