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
