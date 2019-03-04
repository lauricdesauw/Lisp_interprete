#include <string>
#include <iostream>
#include "cell_subset.hh"

/******* Initialization of stats *******/

int Cell_number::number_of_cells = 0;
int Cell_string::number_of_cells = 0;
int Cell_symbol::number_of_cells = 0;
int Cell_pair::number_of_cells = 0;

/******* Cell_number *******/

Cell_number::Cell_number (int n) : Cell()
{
    contents = n;
    ++ number_of_cells;
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

int Cell_number::get_number_of_cells()
{
    return number_of_cells;
}

// Garbage collection

void Cell_number::mark_used()
{
    Collectable::used = true;
}

/******* Cell_string *******/

Cell_string::Cell_string (std::string s) : Cell()
{
    contents = s;
    ++ number_of_cells;
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

int Cell_string::get_number_of_cells()
{
    return number_of_cells;
}

// Garbage collection

void Cell_string::mark_used()
{
    Collectable::used = true;
}

/******* Cell_symbol *******/

Cell_symbol::Cell_symbol (std::string s) : Cell()
{
    contents = s;
    ++ number_of_cells;
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

int Cell_symbol::get_number_of_cells()
{
    return number_of_cells;
}

// Garbage collection

void Cell_symbol::mark_used()
{
    Collectable::used = true;
}

/******* Cell_pair *******/

Cell_pair::Cell_pair (Cell* car_p, Cell* cdr_p) : Cell()
{
    ++ number_of_cells;
    car_p -> check();
    cdr_p -> check();
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

void Cell_pair::set_cdr (Cell* new_cdr) 
{
    cdr = new_cdr;
}

int Cell_pair::get_number_of_cells()
{
    return number_of_cells;
}

// Garbage collection

void Cell_pair::mark_used()
{
    Collectable::used = true;
    car -> mark_used();
    cdr -> mark_used();
}
