#include "argument_parser.h"
#include "string.h"
#include "exceptions.h"
#include <charconv>
#include <iostream>

ArgumentParser::ArgumentParser(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        auto arg = argv[i];

        // helper lambdas
        auto argIs = [&arg](const char *s)
        {
            return strcmp(arg, s) == 0;
        };

        auto nextArg = [&]()
        {
            if (i + 1 == argc)
                throw TooFewArgumentsException();
            return argv[++i];
        };

        // options
        if (argIs("-a") || argIs("--address"))
        {
            _ip = nextArg();
        }
        else if (argIs("-p") || argIs("--port"))
        {
            auto tmp = nextArg();
            from_chars(tmp, tmp + strlen(tmp), _port);
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
            throw InvalidCommandException();
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
