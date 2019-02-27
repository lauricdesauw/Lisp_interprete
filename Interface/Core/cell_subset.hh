#pragma once

#include <string>

class API;

/*****************************/
class Cell_number : public Cell {
 private:
  int contents;

 private:
  Cell_number(int n);
  type get_type() const override;
  int get_contents() const;

  friend class API;
};

/*****************************/

class Cell_string : public Cell {
 private:
  std::string contents;

 private:
  Cell_string(std::string s);
  type get_type() const override;
  std::string get_contents() const;

  friend class API;
};

/*****************************/

class Cell_symbol : public Cell {
 private:
  std::string contents;

 private:
  Cell_symbol(std::string s);
  type get_type() const override;
  std::string get_contents() const;

  friend class API;
};

/*****************************/

class Cell_pair : public Cell {
 private:
  Cell *car;
  Cell *cdr;

 private:
  Cell_pair(Cell *_car, Cell *_cdr);
  type get_type() const override;
  Cell *get_car() const;
  Cell *get_cdr() const;

  friend class API;
};
