#include "../include/command_base.h"

void CommandBase::checkNArgs(const int count, const int expected) const
{
    if (count < expected)
    {
        throw TooFewArgumentsException();
    }
    else if (count > expected)
    {
        throw TooManyArgumentsException();
    }
}

string CommandBase::authToken()
{
    auto file = ifstream("login-token");
    if (!file.is_open())
    {
        return "";
    }
    string ret;
    getline(file, ret);
    return string(ret.find_first_of("\""), ret.find_last_of("\""));
}
