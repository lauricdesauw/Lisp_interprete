#include "library.hh"
#include "API.hh"
#include <iostream>
#include <cassert>
#include "error.hh"

void check(Object l) {API::check(l);}

Object nil() {return API::nil();}

bool null(Object l) {return API::null(l);}
Object t() {return API::t();}
Object f() {return API::f();}

Object cons(Object a, Object l) {return API::cons(a,l);}
Object car(Object l) {return API::car(l);}
Object cdr(Object l) {return API::cdr(l);}

bool eq(Object a, Object b)
{
    check(a);
    check(b);
    if (numberp(a) && numberp(b))
    {
        return object_to_number(a) == object_to_number(b);
    }
    if ((symbolp(a) && symbolp(b)) || (stringp(a) && stringp(b)))
    {
        return object_to_string(a) == object_to_string(b);
    }
    return a == b;
}

bool numberp(Object l) {return API::numberp(l);}
bool stringp(Object l) {return API::stringp(l);}
bool symbolp(Object l) {return API::symbolp(l);}
bool boolp(Object l) {return API::boolp(l);}
bool listp(Object l) {return API::listp(l);}
bool pairp(Object l) {return API::pairp(l);}

Object number_to_object(int n) {return API::number_to_object(n);}
Object string_to_object(std::string s) {return API::string_to_object(s);}
Object symbol_to_object(std::string s) {return API::symbol_to_object(s);}
Object bool_to_object(bool b) {return API::bool_to_object(b);}

int object_to_number(Object l) {return API::object_to_number(l);}
std::string object_to_string(Object l) {return API::object_to_string(l);}
bool object_to_bool(Object l) {return API::object_to_bool(l);}

Object car(Object l, int n)
{
    assert(n >= 0);
    if (n == 0)
    {
        return car(l);
    }
    else
    {
        return car(API::cdr(l),n-1);
    }
}

Object cdr(Object l, int n)
{
    assert(n >= 0);
    if (n == 0)
    {
        return cdr(l);
    }
    else
    {
        return cdr(API::cdr(l),n-1);
    }
}

Object cadr(Object l)
{
    return car(l,1);
}

Object cddr(Object l)
{
    return cdr(l,1);
}

std::ostream& print_object_cdr(std::ostream& s, Object l)
{
    if (null(l))
    {
        return s;
    }
    print_object_aux(s, API::car(l), !null(API::cdr(l)));
    print_object_cdr(s, API::cdr(l));
    return s;
}

std::ostream& print_object_aux (std::ostream& s, Object l, bool b)
{
    if (numberp(l))
    {
        int n = object_to_number(l);
        s << n ;
    }
    else if (stringp(l) || symbolp(l))
    {
        std::string st = object_to_string(l);
        s << st ;
    }
    else if (boolp(l))
    {
        bool b = object_to_bool(l);
        if (b)
        {
            s << "#t";
        }
        else
        {
            s << "#f";
        }
    }
    else if (listp(l))
    {
        s << "(";
        print_object_cdr(s,l);
        s << ")";
    }
    if (b)
    {
        s << " ";
    }
    return s;
}

std::ostream& print_object(std::ostream& s, Object l)
{
    print_object_aux(s,l,false);
    return s;
}

std::ostream& operator<<(std::ostream& s, Object l)
{
    print_object(s,l);
    return s;
}

std::ostream& print_type(std::ostream& s, Object l)
{
    if (numberp(l))
    {
        s << "It's a number." << std::endl;
    }
    else if (symbolp(l))
    {
        s << "It's a symbol." << std::endl;
    }
    else if (stringp(l))
    {
        s << "It's a string." << std::endl;
    }
    else if (boolp(l))
    {
        s << "It's a bool." << std::endl;
    }
    else if (listp(l))
    {
        s << "It's a list." << std::endl;
    }
    return s;
}
