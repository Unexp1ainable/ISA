#include "argument_parser.h"
#include "string.h"
#include "exceptions.h"
#include <charconv>
#include <iostream>
#include <regex>

ArgumentParser::ArgumentParser(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        auto arg = argv[i];

        // ----- helper lambdas -----
        // performs char* to char* comparison, compares given string with arg
        auto argIs = [&arg](const char *s)
        {
            return strcmp(arg, s) == 0;
        };

        // attempts to return the next argument, if there is no more avaliable, throws exception
        // also escapes LF
        auto nextArg = [&]()
        {
            if (i + 1 == argc)
                throw TooFewArgumentsException();
            string ret = argv[++i];
            ret = regex_replace(ret, regex("\n"), "\\n");
            return ret;
        };

        // options
        if (argIs("-a") || argIs("--address"))
        {
            _ip = nextArg();
        }
        else if (argIs("-p") || argIs("--port"))
        {
            auto tmp = nextArg();
            from_chars(tmp.begin().base(), tmp.end().base(), _port);
        }
        else if (argIs("-h") || argIs("--help"))
        {
            cout << _help << endl;
            exit(0);
        }
        // commands
        else if (argIs("register"))
        {
            setCommand(Command::REGISTER);
            _params.push_back(nextArg());
            _params.push_back(nextArg());
        }
        else if (argIs("login"))
        {
            setCommand(Command::LOGIN);
            _params.push_back(nextArg());
            _params.push_back(nextArg());
        }
        else if (argIs("list"))
        {
            setCommand(Command::LIST);
        }
        else if (argIs("send"))
        {
            setCommand(Command::SEND);
            _params.push_back(nextArg());
            _params.push_back(nextArg());
            _params.push_back(nextArg());
        }
        else if (argIs("fetch"))
        {
            setCommand(Command::FETCH);
            _params.push_back(nextArg());
        }
        else if (argIs("logout"))
        {
            setCommand(Command::LOGOUT);
        }
        else
        {
            if (_command == Command::UNKNOWN)
                throw InvalidCommandException();
            throw TooManyArgumentsException();
        }
    }
}

void ArgumentParser::setCommand(Command s)
{
    if (_command == Command::UNKNOWN)
    {
        _command = s;
        return;
    }
    throw CommandRedefinitionException();
}
