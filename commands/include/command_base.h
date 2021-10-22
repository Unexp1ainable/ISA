#pragma once

#include "../../argument_parser.h"
#include "../../exceptions.h"
#include "../../responses/responses.h"

#include <iostream>
#include <memory>
#include <functional>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

using addrinfo_ptr = unique_ptr<addrinfo, function<void(addrinfo *)>>;

/**
 * @brief Base class for all commands
 * 
 */
class CommandBase
{
public:
    /**
     * @brief Construct a new Command Base object
     *
     * @param args Parsed arguments
     */
    CommandBase(ArgumentParser &args);
    virtual ~CommandBase() = default;

    /**
     * @brief Assembles TCP payload
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

    /**
     * @brief Create a socket address from arguments loaded on object construction.
     *
     * @param type Type of address. AF_INET, AF_INET6 or AF_UNSPEC
     * @return SocketAddress Address in an union
     */
    addrinfo_ptr createSocketAddress();

    ArgumentParser _args;
};
