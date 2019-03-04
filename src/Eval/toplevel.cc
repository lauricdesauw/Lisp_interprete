#include <cassert>
#include <iostream>
#include <string>

#include "defs.hh"
#include "env.hh"
#include "error.hh"
#include "eval.hh"
#include "garbage_collector.hh"
#include "library.hh"
#include "read.hh"
#include "toplevel.hh"

Toplevel::Toplevel() : global_env(nil()), STAT_MODE(false) {
  init_GC();
  add_to_GC_root(global_env);
}

void Toplevel::go() {
  while (true) {
    try {
      std::cout << std::endl << "C++Lisp: ";
      Object curr_obj = read_object();
      if (Toplevel::is_load_directive(curr_obj)) {
        handle_load(curr_obj);
      } else if (listp(curr_obj) && !null(curr_obj) && symbolp(car(curr_obj)) &&
                 (object_to_string(car(curr_obj)) == lisp_define)) {
        Object body = cdr(curr_obj);
        global_env = do_define(body, global_env);
      } else if (listp(curr_obj) && !null(curr_obj) && symbolp(car(curr_obj)) &&
                 (object_to_string(car(curr_obj)) == lisp_definestat)) {
        Object body = cdr(curr_obj);
        global_env = do_definestat(body, global_env);
      } else if (listp(curr_obj) && !null(curr_obj) && symbolp(car(curr_obj)) &&
                 (object_to_string(car(curr_obj)) == lisp_setb)) {
        Object body = cdr(curr_obj);
        do_setb(body, global_env);
      } else if (listp(curr_obj) && !null(curr_obj) && symbolp(car(curr_obj)) &&
                 (object_to_string(car(curr_obj)) == lisp_stats)) {
        STAT_MODE = do_stats(cdr(curr_obj));
      } else if (listp(curr_obj) && !null(curr_obj) && symbolp(car(curr_obj)) &&
                 (object_to_string(car(curr_obj)) == lisp_printenv)) {
        print_env(std::cout, global_env);
      } else {
        std::cout << eval(curr_obj, global_env) << std::endl;
      }

      if (STAT_MODE) {
        print_stats();
      }
      Garbage_collector::remove_last_from_root();
      add_to_GC_root(global_env);
      Garbage_collector::clean_memory();
    } catch (Toplevel_exception &e) {
      std::cout << e.what() << std::endl << std::endl;
    }
  }
}

/************ Load Functions *************/

bool Toplevel::is_load_directive(Object obj) {
  if (!pairp(obj)) {
    return false;
  } else if (!symbolp(car(obj))) {
    return false;
  } else if (object_to_string(car(obj)) == lisp_load) {
    return true;
  } else {
    return false;
  }
}

void Toplevel::handle_load_core(std::string file_name) {
  std::cout << "Loading file " << file_name << "..." << std::endl;
  try {
    go();
  } catch (std::runtime_error e) {
    std::cout << "File " << file_name << " loaded!" << std::endl;
  }
}

void Toplevel::handle_load(Object obj) {
  Object file_object = cadr(obj);
  if (!stringp(file_object)) {
    throw Toplevel_exception("Argument must be a string");
  };
  // Creating new file input stream
  std::string file_path = object_to_string(file_object);
  file_path = file_path.substr(1, file_path.length() - 2);
  FILE *new_stream = fopen((file_path).c_str(), "r");
  if (new_stream == nullptr) {
    throw Toplevel_exception("File does not exists");
  } else {
    FILE *current_input = get_lexer_input();
    change_lexer_input(new_stream);
    handle_load_core(file_path);
    fclose(new_stream);
    change_lexer_input(current_input);
  }
}

void Toplevel::handle_load_from_string(std::string path) {
  Object path_o = string_to_object("\"" + path + "\"");
  Object load_o = symbol_to_object("load");
  handle_load(cons(load_o, cons(path_o, nil())));
}
