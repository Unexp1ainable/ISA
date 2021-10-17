#pragma once
#include <exception>

using namespace std;

class TooFewArgumentsException : public exception {
public:
    TooFewArgumentsException();
    virtual const char* what() const noexcept override { return "Too few arguments."; }
};

class TooManyArgumentsException : public exception {
public:
    TooManyArgumentsException();
    virtual const char* what() const noexcept override { return "Too many arguments."; }
};
