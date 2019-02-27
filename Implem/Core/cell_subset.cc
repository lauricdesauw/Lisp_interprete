#include <string>
#include "cell_subset.hh"

/******* Cell_number *******/

Cell_number::Cell_number (int n)
{
    Cell();
    contents = n;
}

type Cell_number::get_type ()
{
    check();
    return Cell::NUMBER;
}

int Cell_number::get_contents ()
{
    check();
    return contents;
}

/******* Cell_string *******/

Cell_string::Cell_string (std::string s)
{
    Cell();
    contents = s;
}

type Cell_string::get_type ()
{
    check();
    return Cell::STRING;
}

std::string Cell_string::get_contents ()
{
    check();
    return contents;
}

/******* Cell_symbol *******/

Cell_symbol::Cell_symbol (std::string s)
{
    Cell();
    contents = s;
}

type Cell_symbol::get_type ()
{
    check();
    return Cell::SYMBOL;
}

std::string Cell_symbol::get_contents ()
{
    check();
    return contents;
}

/******* Cell_pair *******/

Cell_pair::Cell_pair (Cell* car_p, Cell* cdr_p)
{
    Cell();
    car = car_p;
    cdr = cdr_p;
}

type Cell_pair::get_type ()
{
    check();
    return Cell::PAIR;
}

Cell* Cell_pair::get_car ()
{
    check();
    return car;
}

Cell* Cell_pair::get_cdr ()
{
    check();
    return cdr;
}
