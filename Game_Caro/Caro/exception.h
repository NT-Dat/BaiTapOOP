#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>

class Exception
{
public:
    Exception();
    static void InvalidNameException(const std::string& userName);
};

#endif // EXCEPTION_H
