#pragma once
#include <exception>

using namespace std;

class TooFewArgumentsException : public exception {
public:
    virtual const char* what() const noexcept override { return "Too few arguments."; }
};

class TooManyArgumentsException : public exception {
public:
    virtual const char* what() const noexcept override { return "Too many arguments."; }
};

class SocketFailureException : public exception {
    virtual const char* what() const noexcept override { return "Socket failure."; }
};

class UserNotLoggedInException : public exception {
    virtual const char* what() const noexcept override { return "User is not logged in."; }
};

class CommandRedefinitionException : public exception {
    virtual const char* what() const noexcept override { return "Only one command per process allowed."; }
};

class InvalidCommandException : public exception {
    virtual const char* what() const noexcept override { return "Invalid command."; }
};

