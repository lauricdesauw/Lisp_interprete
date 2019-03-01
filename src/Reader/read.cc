#include <iostream>
#include <stdexcept>

#include "read.hh"
#include "library.hh"
#include "error.hh"

using namespace std;

extern Object get_read_object();
extern int yyparse();
extern FILE* yyin;
extern void yyrestart(FILE* f);

void change_lexer_input(FILE* stream)
{
    yyrestart(stream);
}

FILE* get_lexer_input()
{
    return yyin;
}

Object read_object() {
    if (yyparse() != 0) throw runtime_error("End of input stream");
        Object l = get_read_object();
        cout << "Read: " << l << endl;
    return l;
}
