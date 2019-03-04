#pragma once

#include <cassert>
#include "garbage_collector.hh"

class Collectable {
 protected:
  bool used;
  uint64_t magic;
  virtual void mark_used() = 0;
  void clean_used() { used = false; };
  void check() const {
    if (magic != (uint64_t)this) {
      throw std::exception();
    };
  }

 public:
  Collectable() : used(false), magic((uint64_t)this) {
    Garbage_collector::add_to_all(this);
  };
  virtual ~Collectable(){};

  friend class Garbage_collector;
};
