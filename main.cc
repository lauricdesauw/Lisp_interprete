#include <cstdio>

#include "error.hh"
#include "read.hh"
#include "toplevel.hh"

using namespace std;

int main(int argc, char *argv[]) {
  Toplevel toplevel;
  try {
    switch (argc) {
      case 1:
        toplevel.go();
        break;
      case 2:
        toplevel.handle_load_from_string(argv[1]);
        change_lexer_input(stdin);
        toplevel.go();
        break;
      default:
        toplevel.go();
        break;
    }
  } catch (Quit_exception e) {
    cout << endl;
    cout << "May Lisp be with you!" << endl;
  } catch (runtime_error e) {
    cout << endl;
    cout << "Runtime critical error : " << e.what() << endl;
  }
}
