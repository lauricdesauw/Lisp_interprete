#include <cstdio>

#include "toplevel.hh"
#include "eval.hh"
#include "error.hh"

using namespace std;

int main(int argc,char* argv[]) {

    Toplevel toplevel;

    switch(argc)
    {
        case 0 :
            break;
        case 1 :
            handle_load(string_to_object())
    }

    try {
        toplevel.go(true);
    } catch (Quit_exception e)
        {
            cout << endl;
            cout << "May Lisp be with you!" << endl;
        }
}
