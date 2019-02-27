#include "API.hh"

using namespace std;

static void API::check(Object l)
{
    assert(l != 0);
    l->check();
}

// Constants

static Object API::nil()
{
    return API::object_nil;
}

static bool API::null(Object l)
{
    API::check(l);
    return (l == API::object_nil);
}

static Object API::t()
{
    return API::object_t;
}

static API::Object f()
{
    return API::object_f;
}

// List Operators

static Object API::cons(Object a, Object l)
{
    API::check(a);
    API::check(l);
    assert(API::null(l) || l->get_type() == Cell::PAIR);
    return new Cell_pair(*a,*l);
}

static Object API::car(Object l)
{
    API::check(l);
    assert(l->get_type() == Cell::PAIR);
    return l->get_car();
}


static Object API::cdr(Object l)
{
    API::check(l);
    assert(l->get_type() == Cell::PAIR);
    return l->get_cdr();
}

static Object API::number_to_object (int n)
{
    Cell_number::Cell_number (n);
}

static Object API::string_to_object (std::string s)
{
    Cell_string::Cell_string(s);
}

static Object API::symbol_to_object (std::string s)
{
    Cell_symbol::Cell_symbol(s);
}

static Object API::bool_to_object (bool b)
{
    if b {t();}
    else {f();}
}

static int API::object_to_number (Object l)
{
    API::check(l);
    assert(numberp(l));
    return (l.get_contents());
}

static std::string API::object_to_string (Object l)
{
    API::check(l);
    assert(stringp(l));
    return (l.get_contents());
}

static bool API::object_to_bool (Object l)
{
    API::check(l);
    assert (l == object_t | l == object_f);
    if (l == object_t) {return true;}
    else {return false;}
}
