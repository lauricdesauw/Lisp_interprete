#pragma once

#include <vector>

class Collectable;

class Garbage_collector {
 private:
  // Storage vectors
  static std::vector<Collectable *> root;
  static std::vector<Collectable *> all;
  //
  static void clean();
  static void mark();
  static void sweep();
  // Sweeping sub_function
  static std::vector<Collectable *> used_test(std::vector<Collectable *>);

 public:
  static void add_to_root(Collectable *c);
  static void remove_last_from_root();
  static void add_to_all(Collectable *c);
  static void clean_memory();
};
