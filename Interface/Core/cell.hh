#pragma once

#include <string>

class API;

/*****************************/

class Cell;
using Object = Cell *;

class Cell {
    private:
        static const uint64_t magic_number;
        uint64_t magic;
        void clean();
        void check() const;

    protected:
        enum class type { UNDEFINED, NUMBER, STRING, SYMBOL, PAIR };
        Cell();
        virtual ~Cell();
        virtual type get_type() const = 0;

    friend class API;
};
