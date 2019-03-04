#pragma once

#include <iostream>
#include <cassert>
#include <stdexcept>
#include <string>

#include "globals.hh"

/********** Exceptions *********/

class Custom_exception : public std::runtime_error
{
    private:
        std::string message;
    public:
        Custom_exception(std::string msg);
        std::string what(); // no need to override, it's an overloard of
                            // virtual const char* what() const throw();
};

class Evaluation_exception : public Custom_exception
{

    public:
        Evaluation_exception();
        Evaluation_exception(std::string _message);
};

class Toplevel_exception : public Custom_exception
{
   public:
        Toplevel_exception(std::string _message);
};

class Quit_exception : public std::exception
{
    public:
        Quit_exception(){};
};

/********** Throwing functions **********/

void eval_error(std::string s);

void toplevel_error(std::string s);

void quit();
