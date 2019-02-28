#include <iostream>
#include <stdexcept>

#include "read.hh"
#include "library.hh"

using namespace std;

extern Object get_read_object();
extern int yyparse();
extern void change_input(FILE* stream);

void change_lexer_input(FILE* stream)
{
    change_input(stream);
}

Object read_object() {
    if (yyparse() != 0) throw runtime_error("End of input stream");
        Object l = get_read_object();
        cout << "Read: " << l << endl;
    return l;
}
