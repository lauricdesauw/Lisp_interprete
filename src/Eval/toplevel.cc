#include "toplevel.hh"
#include "read.hh"
#include "library.hh"

Toplevel::Toplevel()
{
    global_env = *(new Env());
}

void Toplevel::go(bool use_prompt)
{

    while(true)
    {
        std::cout << "C++Lisp :";
        Object curr_obj = read_object();
        print_object(std::cout, curr_obj);
    }
}


