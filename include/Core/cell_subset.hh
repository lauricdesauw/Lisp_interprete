#pragma once

#include <string>
#include "cell.hh"

class API;

/*********** Cells for ints ************/
class Cell_number : public Cell {
 private:
  int contents;
  static int number_of_cells;

 public:
  Cell_number(int n);
  // Data getters
  Cell::type get_type() const override;
  int get_contents() const;
  // Stats
  static int get_number_of_cells();
  // Garbage collection
  void mark_used() override;

  friend class API;
};

/************ Cells for strings ***********/

class Cell_string : public Cell {
 private:
  std::string contents;
  static int number_of_cells;

 public:
  Cell_string(std::string s);
  // Data getters
  Cell::type get_type() const override;
  std::string get_contents() const;
  // Stats
  static int get_number_of_cells();
  // Garbage collection
  void mark_used() override;

  friend class API;
};

/************ Cells for symbols ************/

class Cell_symbol : public Cell {
 private:
  std::string contents;
  static int number_of_cells;

 public:
  Cell_symbol(std::string s);
  // Data getters
  Cell::type get_type() const override;
  std::string get_contents() const;
  // Stats
  static int get_number_of_cells();
  // Garbage collection
  void mark_used() override;

  friend class API;
};

/*********** Cells for lists ************/

class Cell_pair : public Cell {
 private:
  Cell *car;
  Cell *cdr;
  static int number_of_cells;

 public:
  Cell_pair(Cell *car_p, Cell *cdr_p);
  // Data getters
  Cell::type get_type() const override;
  Cell *get_car() const;
  Cell *get_cdr() const;
  // Static environment setter
  void set_cdr(Cell *new_cdr);
  // Stats
  static int get_number_of_cells();
  // Garbage collection
  void mark_used() override;

  friend class API;
};
