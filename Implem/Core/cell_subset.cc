#include <string>
#include "cell_subset.hh"

/******* Cell_number *******/

Cell_number::Cell_number (int n)
{
    Cell::Cell();
    contents = n;
}

type Cell_number::get_type ()
{
    return Cell::NUMBER;
}

int Cell_number::get_contents ()
{
    return contents;
}

/******* Cell_string *******/

Cell_string::Cell_string (std::string s)
{
    Cell::Cell();
    contents = s;
}

type Cell_string::get_type ()
{
    return Cell::STRING;
}

std::string Cell_string::get_contents ()
{
    return contents;
}

/******* Cell_symbol *******/

Cell_symbol::Cell_symbol (std::string s)
{
    Cell::Cell();
    contents = s;
}

type Cell_symbol::get_type ()
{
    return Cell::SYMBOL;
}

std::string Cell_symbol::get_contents ()
{
    return contents;
}

/******* Cell_pair *******/

Cell_pair::Cell_pair (Cell* _car, Cell* _cdr)
{
    Cell::Cell();
    car = _car;
    cdr = _cdr;
}

type Cell_pair::get_type ()
{
    return Cell::PAIR;
}

Cell* Cell_pair::get_car ()
{
    return car;
}

Cell* Cell_pair::get_cdr ()
{
    return cdr;
}
