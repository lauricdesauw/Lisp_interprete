#include <string>
#include "cell_subset.hh"

/******* Cell_number *******/

Cell_number::Cell_number (int n) : Cell()
{
    contents = n;
}

Cell::type Cell_number::get_type() const
{
    Cell::check();
    return Cell::type::NUMBER;
}

int Cell_number::get_contents () const
{
    Cell::check();
    return contents;
}

/******* Cell_string *******/

Cell_string::Cell_string (std::string s) : Cell()
{
    contents = s;
}

Cell::type Cell_string::get_type () const
{
    Cell::check();
    return Cell::type::STRING;
}

std::string Cell_string::get_contents () const
{
    Cell::check();
    return contents;
}

/******* Cell_symbol *******/

Cell_symbol::Cell_symbol (std::string s) : Cell()
{
    contents = s;
}

Cell::type Cell_symbol::get_type () const
{
    Cell::check();
    return Cell::type::SYMBOL;
}

std::string Cell_symbol::get_contents () const
{
    Cell::check();
    return contents;
}

/******* Cell_pair *******/

Cell_pair::Cell_pair (Cell* car_p, Cell* cdr_p) : Cell()
{
    car = car_p;
    cdr = cdr_p;
}

Cell::type Cell_pair::get_type () const
{
    check();
    return Cell::type::PAIR;
}

Cell* Cell_pair::get_car () const
{
    check();
    return car;
}

Cell* Cell_pair::get_cdr () const
{
    check();
    return cdr;
}
