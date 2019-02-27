#include <cstdio>

#include "toplevel.hh"

using namespace std;

int main() {
  Toplevel toplevel;

  try {
    toplevel.go(true);
  } catch (runtime_error& e) {
    clog << e.what() << endl;
    clog << "May Lisp be with you!" << endl;
  }
}
