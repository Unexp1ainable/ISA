#pragma once

#include "../../argument_parser.h"
#include "../../exceptions.h"
#include "../../responses/responses.h"

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

class CommandBase
{
public:
    /**
     * @brief Construct a new Command Base object
     * 
     * @param args Parsed arguments
     */
    CommandBase(ArgumentParser &args);

    /**
     * @brief Defines way how the TCP payload is assembled
     * 
     * @return string Request to be sent to ISAMAIL server.
     */
    virtual string getPayload() = 0;

    /**
     * @brief Returns response from the server
     * 
     * @return Response* Response from the server.
     */
    virtual Response *response() = 0;

    /**
     * @brief Attempts to connect to the server, send the request and process the response.
     * 
     * @return Response* Response send from the server.
     */
    Response *execute();

protected:
    /**
     * @brief Processes bytes send from the server
     * 
     * @param buf Server response
     * @return Response* Processed response
     */
    virtual Response *processResponse(char *buf) = 0;

    /**
     * @brief Throws an exception if number of arguments is different than required.
     * 
     * @param expected Expected number of arguments
     */
    void checkNArgs(const int expected) const;

    /**
     * @brief Attempts to load authentication token. Throws UserNotLoggedInException if no token is avaliable.

     * 
     * @return string Auth token
     */
    string authToken();

    union SocketAddress
    {
        sockaddr_in ipv4;
        sockaddr_in6 ipv6;
    };

    /**
     * @brief Create a socket address from arguments loaded on object construction.
     * 
     * @param type Type of address. AF_INET, AF_INET6 or AF_UNSPEC
     * @return SocketAddress Address in an union
     */
    SocketAddress createSocketAddress(int *type);
    SocketAddress createSocketAddress4();
    SocketAddress createSocketAddress6();

    ArgumentParser _args;
};
