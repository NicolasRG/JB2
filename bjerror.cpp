#include <string>


class Error{
    public:
    Error(std::string msg = "Default Error Message", std::string tpe = "Default Error Type" ){
        message = msg;
        type = tpe;
    }
    std::string type;
    std::string message;
};