#include <iostream>
#include <cassert>
#include <string>

#include "toplevel.hh"
#include "read.hh"
#include "eval.hh"
#include "library.hh"
#include "defs.hh"
#include "error.hh"
#include "globals.hh"
#include "env.hh"

Toplevel::Toplevel() : global_env(nil()), DEBUG_MODE(false), STAT_MODE(false)
{}

void Toplevel::go()
{
    while(true)
    {
        try
        {
            std::cout << std::endl << "Merveille des merveilles: " ;
            Object curr_obj = read_object();
            if(Toplevel::is_load_directive(curr_obj))
            {
                handle_load(curr_obj);
            }
            else if (listp(curr_obj) && !null(curr_obj)
                                    && eq(car(curr_obj),lisp_define))
            {
                Object a = cdr(curr_obj);
                global_env = do_define(a,global_env);
            }
            else if (listp(curr_obj) && !null(curr_obj)
                                    && eq(car(curr_obj),lisp_definestat))
            {
                Object a = cdr(curr_obj);
                global_env = do_definestat(a,global_env);
            }
            else if (listp(curr_obj) && !null(curr_obj)
                                    && eq(car(curr_obj),lisp_debug))
            {
                 DEBUG_MODE = do_debug(cdr(curr_obj));
            }
            else if (listp(curr_obj) && !null(curr_obj)
                                    && eq(car(curr_obj),lisp_stats))
            {
                 STAT_MODE = do_stats(cdr(curr_obj));
            }
            else if (listp(curr_obj) && !null(curr_obj)
                                    && eq(car(curr_obj),lisp_printenv))
            {
                print_env(std::cout,global_env);
            }
            else
            {
                curr_obj = eval(curr_obj,global_env);
                std::cout << curr_obj << std::endl;
            }
            std::cout << std::endl << "Miracle des miracles !"
                << std::endl << std::endl;

            if(STAT_MODE){print_stats();}
       } catch (Toplevel_exception& e)
            {
                cout << e.what() << endl;
                cout << endl;
            }
    }
}

/******************************************************************************/

bool Toplevel::is_load_directive(Object obj)
{
    if(!pairp(obj)){return false;}
    else if (!symbolp(car(obj))) {return false;}
    else if(object_to_string(car(obj)) == lisp_load) {return true;}
    else {return false;}
}

void Toplevel::handle_load_core(std::string file_name)
{
    cout << "Loading file " << file_name << "...\n";
    try
    {
        go();
    }
    catch(runtime_error e)
    {
        cout << "File " << file_name << " loaded!\n";
    }
}

void Toplevel::handle_load(Object obj)
{
    Object file_object = cadr( obj);
    assert(stringp(file_object));
    std::string file_path = object_to_string( file_object);
    file_path = file_path.substr(1,file_path.length()-2);
    FILE* new_stream = fopen((file_path).c_str(),"r");
    if(new_stream == nullptr){throw Toplevel_exception("File does not exists");}
    else
    {
        FILE* current_input = get_lexer_input();
        change_lexer_input(new_stream);
        handle_load_core( file_path);
        fclose(new_stream);
        change_lexer_input(current_input);
    }
}

void Toplevel::handle_load_from_string(std::string path)
{
    Object path_o = string_to_object("\"" + path +"\"");
    Object load_o = symbol_to_object("load");
    handle_load(cons(load_o,cons(path_o,nil())));
}
