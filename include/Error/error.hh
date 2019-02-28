#pragma once

#include <iostream>
#include <cassert>
#include <stdexcept>
#include <exception>
#include <string>

#include "library.hh"

class Evaluation_exception : public std::runtime_error
{
    private:
        Object obj;
        Env env;
        std::string message;

    public:
        Evaluation_exception();
        Evaluation_exception(Object _obj, Env _env, std::string _message);//: std::runtime_error(_message),obj(_obj),env(_env),message(_message){};
};
void error(Object obj, Env env, std::string s);

class Zipping_exception : public std::runtime_error
{
    private:
        std::string message;
        Object lobjs;

    public:
        Zipping_exception(Object _lobjs, std::string _message);
};

class Quit_exception : public exception
{
    public:
        Quit_exception(){};
};
void quit();

class No_binding_exception : public std::runtime_error
{
    private:
        std::string name;

    public:
        No_binding_exception(std::string _name);
};
