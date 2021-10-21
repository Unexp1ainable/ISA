#include "../include/command_base.h"


CommandBase::CommandBase(ArgumentParser &args) : _args(args)
{
}

CommandBase::SocketAddress CommandBase::createSocketAddress4() {
    CommandBase::SocketAddress addr;

    addr.ipv4.sin_family = AF_INET;
    inet_pton(AF_INET, _args.ip().c_str(), &addr.ipv4.sin_addr.s_addr);
    addr.ipv4.sin_port = htons(_args.port());

    return addr;
}

CommandBase::SocketAddress CommandBase::createSocketAddress6() {
    CommandBase::SocketAddress addr;

    addr.ipv6.sin6_family = AF_INET6;
    inet_pton(AF_INET6, _args.ip().c_str(), &addr.ipv6.sin6_addr);
    addr.ipv6.sin6_port = htons(_args.port());

    return addr;
}

CommandBase::SocketAddress CommandBase::createSocketAddress(int* type) {
    char buf[16];
    if (inet_pton(AF_INET, _args.ip().c_str(), buf))
    {
        *type = AF_INET;
        return createSocketAddress4();
    }
    else if (inet_pton(AF_INET6, _args.ip().c_str(), buf))
    {
        *type = AF_INET6;
        return createSocketAddress6();
    }

    *type = AF_UNSPEC;
    return CommandBase::SocketAddress();
}

Response *CommandBase::execute()
{
    string payload = getPayload();

    auto socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD < 0)
    {
        throw SocketFailureException();
    }

    int connectionType, ret;
    CommandBase::SocketAddress addr = createSocketAddress(&connectionType);;
    char buffer[1024];

    if (connectionType == AF_INET) {
        ret = connect(socketFD, (struct sockaddr *) &(addr.ipv4), sizeof(addr.ipv4));
    } else if (connectionType == AF_INET6) {
         ret = connect(socketFD, (struct sockaddr *) &(addr.ipv6), sizeof(addr.ipv6));
    }

    if (ret < 0) {
        throw SocketFailureException();
    }

    ret = write(socketFD, payload.c_str(), payload.length());

    if (ret == -1) {
        throw SocketFailureException();
    }

    ret = read(socketFD, buffer, BUFFER_LEN);
    
    if (ret == -1) {
        throw SocketFailureException();
    }

    return processResponse(buffer);
}

void CommandBase::checkNArgs(const int expected) const
{
    auto count = _args.count();
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
        throw UserNotLoggedInException();
    }
    string ret;
    getline(file, ret);
    return ret;
}


