#include <iostream>
#include <stdexcept>

#include "read.hh"

using namespace std;

extern Object get_read_object();
extern int yyparse();

Object read_object() {
    if (yyparse() != 0) throw runtime_error("End of input stream");
        Object l = get_read_object();
        cout << "Read: " << l << endl;
    return l;
}
