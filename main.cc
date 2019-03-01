#include <cstdio>

#include "toplevel.hh"
#include "error.hh"

using namespace std;

int main(int argc,char* argv[]) {

    Toplevel toplevel;

<<<<<<< HEAD
    try
    {
        switch(argc)
        {
            case 1 :
                toplevel.go(true);
                break;
            case 2 :
                toplevel.handle_load_from_string(argv[1]);
                break;
            default :
                toplevel.go(true);
                break;
        }
    }
    catch (Quit_exception e)
=======
    try {
        toplevel.go(true);
    } catch (Quit_exception e)
>>>>>>> b9aba96351d1250ab799b3c9fc6cfb7c4509c1d6
        {
            cout << endl;
            cout << "May Lisp be with you!" << endl;
        }
}
