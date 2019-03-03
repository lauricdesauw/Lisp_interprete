#pragma once

#include <string>
#include "globals.hh"

class API;

/*****************************/

class Cell {
    private:
        uint64_t magic;
        static int number_of_cells_parent;
        Env closure;
        void clean();

    protected:
        enum class type { UNDEFINED, NUMBER, STRING, SYMBOL, PAIR };
        Cell();
        virtual ~Cell();
        virtual type get_type() const = 0;
        void check() const;

    public :
        static int get_number_of_cells_parent();
        void set_closure(Env env);
        Env get_closure();
        bool is_static();

    friend class API;
    friend class Cell_pair;
};
