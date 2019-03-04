#include "cell.hh"
#include <cassert>

int Cell::number_of_cells_parent = 0;

Cell::Cell() : Collectable()
{
    ++ number_of_cells_parent;
}

Cell::~Cell()
{
    check();
    -- number_of_cells_parent;
    magic = 0;
}

int Cell::get_number_of_cells_parent()
{
    return number_of_cells_parent;
}
