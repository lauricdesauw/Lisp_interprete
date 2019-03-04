#pragma once

#include <string>

#include "collectable.hh"
#include "globals.hh"

class API;

class Cell;
using Object = Cell *;

class Cell : public Collectable {
 private:
  static int number_of_cells_parent;
  Env closure;

 protected:
  enum class type { UNDEFINED, NUMBER, STRING, SYMBOL, PAIR };
  Cell();
  virtual type get_type() const = 0;
  // Garbage collection and check
  virtual void mark_used() = 0;
  void check() const { Collectable::check(); };

 public:
  // Stats
  static int get_number_of_cells_parent();
  // Destructor for garbage collection purpose
  ~Cell();
  // Static environment functions
  void set_closure(Env env);
  Env get_closure();
  bool is_static();

  friend class API;
  friend class Cell_pair;
};
