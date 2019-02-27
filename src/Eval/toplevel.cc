#include "toplevel.hh"
#include "read.hh"
#include "library.hh"
#include <iostream>

Toplevel::Toplevel()
{
    global_env = *(new Env());
}

void Toplevel::go(bool use_prompt)
{

    while(true)
    {
        std::cout << "C++Lisp: ";
        Object curr_obj = read_object();
        print_type(std::cout,curr_obj);
        std::cout << std::endl;
    }
}
