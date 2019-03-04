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

void API::print_stats()
{
    cout << "Statistiques de création de cellulles. \n" <<
            "(Instances de cette classe/Total des  instances)" << endl;
    cout << "Cell_number : " << Cell_number::get_number_of_cells() <<
            "/" << Cell::get_number_of_cells_parent() << endl;
    cout << "Cell_symbol : " << Cell_symbol::get_number_of_cells() <<
            "/" << Cell::get_number_of_cells_parent() << endl;
    cout << "Cell_string : " << Cell_string::get_number_of_cells() <<
            "/" << Cell::get_number_of_cells_parent() << endl;
    cout << "Cell_pair : " << Cell_pair::get_number_of_cells() <<
            "/" << Cell::get_number_of_cells_parent() << endl;
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

bool API::pairp(Object l)
{
    check(l);
    return l->get_type() == Cell::type::PAIR;

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
    Cell_pair* pair = dynamic_cast<Cell_pair*>(l);
    if(pair == nullptr){return nil();}
    else {return pair->Cell_pair::get_car();}

}


Object API::cdr(Object l)
{
    check(l);
    assert(l->get_type() == Cell::type::PAIR);
    Cell_pair* pair = dynamic_cast<Cell_pair*>(l);
    if(pair == nullptr){return nil();}
    else{return pair->Cell_pair::get_cdr();}
}


void API::rplacd(Object l, Object new_value)
{
    Cell_pair* pair = dynamic_cast<Cell_pair*>(l);
    Cell_pair* pair_cdr = dynamic_cast<Cell_pair*>(new_value);
    if(pair != nullptr && pair_cdr != nullptr)
    {
        return pair->Cell_pair::set_cdr(pair_cdr);
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
    Cell_number* number = dynamic_cast<Cell_number*>(l);
    assert(number != nullptr);
    return number->get_contents();
}

std::string API::object_to_string (Object l)
{
    check(l);
    assert(stringp(l) || symbolp(l));
    if (stringp(l))
    {
        Cell_string* str = dynamic_cast<Cell_string*>(l);
        assert(str != nullptr);
        return str->get_contents();
    }
    Cell_symbol* symbol = dynamic_cast<Cell_symbol*>(l);
    assert(symbol != nullptr);
    return symbol->get_contents();
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

bool API::is_static(Object l){
    return l->is_static();
}

Env API::get_closure(Object l){
    return l->get_closure();
}

void API::set_closure(Object l, Env env) {
    l->set_closure(env);
}
