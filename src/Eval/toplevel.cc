#include "toplevel.hh"
#include "read.hh"
#include "eval.hh"
#include "library.hh"
#include "defs.hh"
#include <iostream>

Toplevel::Toplevel()
{
    global_env = *(new Env());
}

void Toplevel::go(bool use_prompt)
{

    while(true)
    {
        try
        {
            check(global_env);
            std::cout << "C++Lisp: ";
            Object curr_obj = read_object();
            if (listp(curr_obj) || !null(curr_obj) || eq(car(curr_obj),lisp_define))
            {
                Object a = cdr(curr_obj);
                global_env = do_define(a,global_env);
            }
            else
            {
                curr_obj = eval(curr_obj,global_env);
                std::cout << curr_obj << std::endl;
                print_type(std::cout,curr_obj);
            }
            std::cout << std::endl;
        } catch (runtime_error& e)
            {
                cout << e.what() << endl;
                cout << endl;
            }
    }
}
