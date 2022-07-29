#include "exception.h"

Exception::Exception()
{

}

void Exception::InvalidNameException(const std::string& userName){
    if(!((userName.length() >= 6) && (userName.length() <= 15))){
        throw "Username should be between 6-15 characters.\n";
    }else{
        for(const char &x : userName){
            if(!(((x >= 'a') && (x <= 'z')) || ((x >= 'A') && (x <= 'Z')) || ((x >= '0') && (x <= '9'))) || x == '_'
                    || x == '-' || x == '.'){
                throw "Username should be alphanumberic (a-Z, 0-9). "
                "You may include underscore (_), hyphen(-) and dot(.). "
                "It has to start and end with an alphabet or a number, and contain at least one alphabet\n";
            }
        }
    }
}
