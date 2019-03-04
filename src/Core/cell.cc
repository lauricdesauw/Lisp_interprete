#include "cell.hh"
#include <cassert>

int Cell::number_of_cells_parent = 0;

Cell::Cell() : Collectable()
{
    ++ number_of_cells_parent;
    closure = Env();
}

Cell::~Cell()
{
    check();
    magic = 0;
}

/********** Static***********/

void Cell::set_closure(Env env){
    closure = env;
}

Env Cell::get_closure(){
    return closure;
}

bool Cell::is_static(){
    return(closure != nullptr);
}

 /********** Stats ***********/

int Cell::get_number_of_cells_parent()
{
    return number_of_cells_parent;
}
