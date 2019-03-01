#pragma once

#include <string>

class API;

/*****************************/

class Cell;
using Object = Cell *;

class Cell {
    private:
        uint64_t magic;
        static int number_of_cells_parent;
        void clean();

    protected:
        enum class type { UNDEFINED, NUMBER, STRING, SYMBOL, PAIR };
        Cell();
        virtual ~Cell();
        virtual type get_type() const = 0;
        void check() const;
        int get_number_of_cells_parent();

    friend class API;
    friend class Cell_pair;
};
