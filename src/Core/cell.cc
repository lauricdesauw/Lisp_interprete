#include "cell.hh"
#include <cassert>

int Cell::number_of_cells_parent = 0;

Cell::Cell()
{
    magic = (uint64_t) this;
    ++ number_of_cells_parent;
    closure = Env();
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

/********** Static***********/

void Cell::set_closure(Env env){
    closure = env;
}

Env Cell::get_closure(){
    return closure;
}

bool Cell::is_static(){
    return(closure == nullptr);
}

 /********** Stats ***********/

int Cell::get_number_of_cells_parent()
{
    return number_of_cells_parent;
}
