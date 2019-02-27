#include "toplevel.hh"
#include "read.hh"
#include "library.hh"
#include <iostream>

Toplevel::Toplevel()
{
    global_env = *(new Env());
}

std::ostream& print_type(std::ostream& s, Object l)
{
    if (numberp(l))
    {
        s << "It's a number." << std::endl;
    }
    else if (symbolp(l))
    {
        s << "It's a symbol." << std::endl;
    }
    else if (stringp(l))
    {
        s << "It's a string." << std::endl;
    }
    else if (boolp(l))
    {
        s << "It's a bool." << std::endl;
    }
    else if (listp(l))
    {
        s << "It's a list." << std::endl;
    }
    return s;
}

void Toplevel::go(bool use_prompt)
{

    while(true)
    {
        std::cout << "C++Lisp: ";
        Object curr_obj = read_object();
        print_type(std::cout,curr_obj);
        std::cout << curr_obj;
        std::cout << std::endl;
    }
}
