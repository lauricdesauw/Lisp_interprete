#include "cell.hh"
#include <cassert>

Cell::Cell()
{
    magic = (uint64_t) &this;
}

void Cell::check()
{
    assert(magic == (uint64_t) &this);
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
