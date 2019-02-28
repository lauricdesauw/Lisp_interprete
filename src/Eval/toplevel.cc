#include "toplevel.hh"
#include "read.hh"
#include "eval.hh"
#include "library.hh"
#include "defs.hh"
#include <iostream>
#include <cassert>

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
            std::cout << "C++Lisp: ";
            Object curr_obj = read_object();
            /*if(is_load_directive(curr_obj))
            {
                handle_load(curr_obj, this);
            }
            else
            {*/
                curr_obj = eval(curr_obj,global_env);
                std::cout << curr_obj << std::endl;
                print_type(std::cout,curr_obj);
                std::cout << std::endl;
            //}
        } catch (runtime_error& e)
            {
                cout << e.what() << endl;
                cout << endl;
            }
    }
}

// ----------------------------------------------------------//
/*
bool is_load_directive(Object obj)
{
  if(!pairp(obj)){return false;}
  else if(car(obj) == lisp_load) {return true;} else {return false;}
}

void handle_load_core(std::string file_name, Toplevel* toplevel)
{
    cout << "Loading file " << file_name << "...\n";
    try
    {
        toplevel->go(true);
    }
    catch(exception e)
    {
        cout << "File " << file_name << " loaded!\n";
        throw std::runtime_error("");
    }
}

void handle_load(Object obj, Toplevel* toplevel)
{
  Object file_object = cadr( obj);
  assert(stringp(file_object));
  std::string file_path = object_to_string( file_object);
  FILE* new_stream = fopen("~/Desktop/test.lisp","r");
  change_lexer_input(new_stream);
  handle_load_core( file_path, toplevel);
  fclose(new_stream);
  change_lexer_input(stdin);
  toplevel->go(true);
}
*/
