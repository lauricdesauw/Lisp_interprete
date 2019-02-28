#pragma once

#include <string>

class API;

/*****************************/

class Cell;
using Object = Cell *;

class Cell {
    private:
        uint64_t magic;
        void clean();

    protected:
        enum class type { UNDEFINED, NUMBER, STRING, SYMBOL, PAIR };
        Cell();
        virtual ~Cell();
        virtual type get_type() const = 0;
        void check() const;

    friend class API;
    friend class Cell_pair;
};
