#include <cstdio>

#include "toplevel.hh"
#include "eval.hh"
#include "error.hh"

using namespace std;

int main(int argc,char* argv[]) {



    Toplevel toplevel;
    try {
        toplevel.go(true);
    } catch (Quit_exception e)
        {
            cout << endl;
            cout << "May Lisp be with you!" << endl;
        }
}
