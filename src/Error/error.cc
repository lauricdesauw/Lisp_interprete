#include <string>
#include <stdexcept>
#include <iostream>
#include <cassert>

#include "error.hh"
#include "library.hh"

Evaluation_exception::Evaluation_exception(Object _obj,
                                           Env _env,
                                           std::string _message):
    std::runtime_error(_message),
    obj(_obj),
    env(_env),
    message(_message)
{};

void error(Object obj, Env env, std::string s)
{
    throw Evaluation_exception(obj,env,s);
}

void quit()
{
    throw Quit_exception();
}

No_binding_exception::No_binding_exception(std::string _name) :
std::runtime_error(_name), name(_name){}

Number_param_exception::Number_param_exception(std::string _name) :
std::runtime_error(name), name(_name){}
