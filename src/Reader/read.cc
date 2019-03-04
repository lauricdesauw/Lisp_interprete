#include <iostream>
#include <stdexcept>

#include "error.hh"
#include "library.hh"
#include "read.hh"

using namespace std;

extern Object get_read_object();
extern int yyparse();
extern FILE *yyget_in();
extern void yyset_in(FILE *f);
extern void yyrestart(FILE *f);

void change_lexer_input(FILE *stream) {
  if (stream == stdin) {
    yyrestart(stream);
  } else {
    yyset_in(stream);
  }
}

FILE *get_lexer_input() { return yyget_in(); }

Object read_object() {
  if (yyparse() != 0) throw runtime_error("End of input stream");
  Object l = get_read_object();
  cout << "Read: " << l << endl;
  return l;
}
