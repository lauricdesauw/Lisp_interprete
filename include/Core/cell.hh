#pragma once

#include <string>
#include "collectable.hh"

class API;

/*****************************/

class Cell;
using Object = Cell *;

class Cell : public Collectable
{
    private:
        static int number_of_cells_parent;

    protected:
        enum class type { UNDEFINED, NUMBER, STRING, SYMBOL, PAIR };
        Cell();
        virtual type get_type() const = 0;
        // Garbage collection
        virtual void mark_used() = 0;
        void check() const {Collectable::check();};

    public :
        static int get_number_of_cells_parent();
        ~Cell();
        virtual void print() override {};

    friend class API;
    friend class Cell_pair;
};
