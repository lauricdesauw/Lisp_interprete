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
            std::cout << "C++Lisp: ";
            Object curr_obj = read_object();
            curr_obj = eval(curr_obj,global_env);
            std::cout << curr_obj << std::endl;
            print_type(std::cout,curr_obj);
            std::cout << std::endl;
        } catch (runtime_error& e)
            {
                cout << e.what() << endl;
                cout << endl;
            }
    }
}

// ----------------------------------------------------------//

bool is_load_directive(Object obj)
{
  if(!pairp(obj)){return false;}
  else if(car(obj) == lisp_load) {return true;} else {return false;}
}

void handle_load_core(std::string file_name, Toplevel toplevel)
{
    cout << "Loading file " << file_name << "...\n";
    try
    {
        toplevel.go(true);
    }
    catch(exception e)
    {
        cout << "File " << file_name << " loaded!\n";
        throw std::runtime_error("");
    }
}
/*
void handle_load(Object obj, Toplevel toplevel)
{
  Object file_object = cadr( obj);
  assert(stringp(file_object));
  std::string file_path = obj_to_string( file_object);
  FILE* = fopen(file_path, "r");
  change_lexer_input()
  handle_load_core file_name toplevel;
  close_in !Globals.current_channel;
  Globals.current_channel := initial_channel;
  Lexer.reset_parser ()
}*/
