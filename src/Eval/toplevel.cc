#include "toplevel.hh"

Toplevel::go(bool use_prompt)
{

    while(true)
    {
        std::cout << "C++Lisp :";
        Object curr_obj = read_object();
        print_object(std::cout, curr_obj);
    }
}
