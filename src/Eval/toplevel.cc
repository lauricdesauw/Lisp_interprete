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

is_load_directive(Object obj)
{
  if(!pairp(obj)){return false;}
  else if(car(obj) == lisp_load) {return true;} else {return false;}
}

let handle_load_core(file_name toplevel =
  print_string ("Loading file " ^ file_name ^ "...\n");
  (try toplevel () with End_of_file -> ());
  print_string ("File " ^ file_name ^ " loaded!\n")
;;

let handle_load obj toplevel =
  let file_object = cadr obj in
  let file_value = eval_direct file_object !Globals.global_env_ref in
  let file_name = obj_to_string file_value in
  let initial_channel = !Globals.current_channel in
  Globals.current_channel := open_in file_name;
  Lexer.reset_parser ();
  handle_load_core file_name toplevel;
  close_in !Globals.current_channel;
  Globals.current_channel := initial_channel;
  Lexer.reset_parser ()
;;
