#include "cell.hh"
#include <cassert>

int Cell::number_of_cells_parent = 0;

Cell::Cell()
{
    magic = (uint64_t) this;
    ++ number_of_cells_parent;
}

void Cell::check() const
{
    assert(magic == (uint64_t) this);
}

void Cell::clean()
{
    check();
    magic = 0;
}

Cell::~Cell()
{
    check();
    clean();
}

int Cell::get_number_of_cells_parent()
{
    return number_of_cells_parent;
}
