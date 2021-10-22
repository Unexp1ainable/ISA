#include "../include/command_base.h"

CommandBase::CommandBase(ArgumentParser &args) : _args(args)
{
}

addrinfo_ptr CommandBase::createSocketAddress()
{
    struct addrinfo hints;
    struct addrinfo *result;

    // prepare hints for address retrieving
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC; 
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    hints.ai_protocol = 0;

    int s = getaddrinfo(_args.ip().c_str(), to_string(_args.port()).c_str(), &hints, &result);
    if (s != 0)
    {
        throw InvalidAddressException();
    }
    return addrinfo_ptr(result, [](addrinfo *a){ freeaddrinfo(a);});
}

Response *CommandBase::execute()
{
    char buffer[1024];
    string payload = getPayload();

    int ret;
    addrinfo_ptr addr = createSocketAddress();

    auto socketFD = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
    if (socketFD < 0)
    {
        throw SocketFailureException();
    }
    // raii socket closing
    unique_ptr<int, function<int(int *)>>__a(&socketFD, [](int *fd)
                                          { return close(*fd); });
                                          
    ret = connect(socketFD, addr->ai_addr, addr->ai_addrlen);
    if (ret < 0)
        throw SocketFailureException();

    ret = write(socketFD, payload.c_str(), payload.length());
    if (ret == -1)
        throw SocketFailureException();

    ret = read(socketFD, buffer, BUFFER_LEN);
    if (ret == -1)
        throw SocketFailureException();

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
    auto file = ifstream("login-token", ios::in);
    if (!file.is_open())
    {
        throw UserNotLoggedInException();
    }
    string ret;
    getline(file, ret);
    file.close();
    return ret;
}
