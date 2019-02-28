#pragma once

#include <iostream>
#include <cassert>
#include <stdexcept>
#include <exception>
#include <string>


class Evaluation_exception : public runtime_error
{
    private:
        Object obj;
        Env env;
        string message;

    public:
        Evaluation_exception();
        Evaluation_exception(Object _obj, Env _env, string _message);//: std::runtime_error(_message),obj(_obj),env(_env),message(_message){};
};

class Zipping_exception : public std::runtime_error
{
    private:
        string message;
        Object lobjs;

    public:
        Zipping_exception(Object _lobjs, string _message);
};

class Quit_exception : public exception
{
    public:
        Quit_exception(){};
};

class No_binding_exception : public std::runtime_error
{
    private:
        std::string name;

    public:
        No_binding_exception(std::string _name);
};

class Number_param_exception : public std::runtime_error {
    private:
        std::string name; //nb = 0 if there are too many param and 1 if there are too many variables
    public:
        Number_param_exception(std::string _name);
};
