#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>

#include "error.hh"
#include "library.hh"

/********** Exceptions *********/

Custom_exception::Custom_exception(std::string msg)
    : std::runtime_error(msg), message(msg) {}

std::string Custom_exception::what() { return message; }

Evaluation_exception::Evaluation_exception(std::string _message)
    : Custom_exception(_message) {}

Toplevel_exception::Toplevel_exception(std::string _name)
    : Custom_exception(_name) {}

/********** Throwing functions **********/

void eval_error(std::string s) { throw Evaluation_exception(s); }

void toplevel_error(std::string s) { throw Toplevel_exception(s); }

void quit() { throw Quit_exception(); }
