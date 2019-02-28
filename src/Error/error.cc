#include <string>
#include <stdexcept>
#include <iostream>
#include <cassert>

#include "error.hh"
#include "library.hh"

void error(Object obj, Env env, std::string s)
{
    throw Evaluation_exception(obj,env,s);
}

void quit()
{
    throw Quit_exception();
}

Custom_exception::Custom_exception(msg) :
    public std::runtime_error(msg)
    message(msg)
{};

Evaluation_exception::Evaluation_exception(Object _obj,
                                           Env _env,
                                           std::string _message):
    Custom_exception(_message),
    obj(_obj),
    env(_env),
    message(_message)
{};

No_binding_exception::No_binding_exception(std::string _name) :
    Custom_exception(_name),
    name(_name)
{};

Number_param_exception::Number_param_exception(std::string _name) :
    Custom_exception(name),
    name(_name)
{};
