#pragma once

#include <string>
#include "cell.hh"

class API;

/*****************************/
class Cell_number : public Cell {
    private:
        int contents;

    public:
        Cell_number(int n);
        Cell::type get_type() const override;
        int get_contents() const;

    friend class API;
};

/*****************************/

class Cell_string : public Cell {
    private:
        std::string contents;

    public:
        Cell_string(std::string s);
        Cell::type get_type() const override;
        std::string get_contents() const;

    friend class API;
};

/*****************************/

class Cell_symbol : public Cell {
    private:
        std::string contents;

    public:
        Cell_symbol(std::string s);
        Cell::type get_type() const override;
        std::string get_contents() const;

    friend class API;
};

/*****************************/

class Cell_pair : public Cell {
    private:
        Cell* car;
        Cell* cdr;

    public:
        Cell_pair(Cell* car_p, Cell* cdr_p);
        Cell::type get_type() const override;
        Cell* get_car() const;
        Cell* get_cdr() const;

    friend class API;
};
/*****************************/

class Cell_constant : public Cell {
    private:
        std::string contents;

    public:
        Cell_constant(std::string s);
        Cell::type get_type() const override;
        std::string get_contents() const;

    friend class API;
};

/*****************************/
