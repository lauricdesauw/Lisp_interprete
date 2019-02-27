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
  enum class sort { UNDEFINED, NUMBER, STRING, SYMBOL, PAIR };
  Cell();
  virtual ~Cell();
  virtual sort get_sort() const = 0;

  friend class API;
};

/*****************************/
class Cell_number : public Cell {
 private:
  int contents;

 private:
  Cell_number(int n);
  sort get_sort() const override;
  int get_contents() const;

  friend class API;
};

/*****************************/

class Cell_string : public Cell {
 private:
  std::string contents;

 private:
  Cell_string(std::string s);
  sort get_sort() const override;
  std::string get_contents() const;

  friend class API;
};

/*****************************/

class Cell_symbol : public Cell {
 private:
  std::string contents;

 private:
  Cell_symbol(std::string s);
  sort get_sort() const override;
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
  sort get_sort() const override;
  Cell *get_car() const;
  Cell *get_cdr() const;

  friend class API;
};
