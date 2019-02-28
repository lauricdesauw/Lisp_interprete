#pragma once

#include <iostream>
#include <cassert>
#include <stdexcept>
#include <string>

#include "globals.hh"

void error(Object obj, Env env, std::string s);
void quit();

class Custom_exception : public std::runtime_error
{
    private:
        std::string message;
    public:
        Custom_exception(std::string msg);
};

class Evaluation_exception : public Custom_exception
{
    private:
        Object obj;
        Env env;
        std::string message;
    public:
        Evaluation_exception();
        Evaluation_exception(Object _obj, Env _env, std::string _message);
};

class Zipping_exception : public Custom_exception
{
    private:
        std::string message;
        Object lobjs;
    public:
        Zipping_exception(Object _lobjs, std::string _message);
};

class No_binding_exception : public Custom_exception
{
    private:
        std::string name;
    public:
        No_binding_exception(std::string _name);
};

class Number_param_exception : public Custom_exception
{
    private:
        std::string name;
    public:
        Number_param_exception(std::string _name);
};

class Quit_exception : public std::exception
{
    public:
        Quit_exception(){};
};
