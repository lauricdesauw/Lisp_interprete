#include <string>
#include <stdexcept>
#include <iostream>
#include <cassert>



Evaluation_exception::Evaluation_exception(Object _obj,
                                           Env _env,
                                           string _message):
    std::runtime_error(_message),
    obj(_obj),
    env(_env),
    message(_message)
{};


No_binding_exception::No_binding_exception(std::string _name) :
std::runtime_error(_name), name(_name){}

Number_param_exception::Number_param_exception(std::string _name) :
std::runtime_error(name), name(_name){}
