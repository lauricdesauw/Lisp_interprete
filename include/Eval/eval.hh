#pragma once

#include <stdexcept>
#include <exception>
#include "library.hh"

using namespace std;

Object eval(Object l, Env env);
Object apply(Object f, Object lvals, Env env);

class Evaluation_exception : public runtime_error
{
    private:
        Object obj;
        Env env;
        string message;

    public:
        Evaluation_exception();
        Evaluation_exception(Object _obj, Env _env, string _message) ;//: std::runtime_error(_message),obj(_obj),env(_env),message(_message){};
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
