#pragma once

#include "../../common.h"
#include <algorithm>
#include <charconv>
#include <string>
#include <vector>
#include "string.h"

using namespace std;

enum class ResponseCode
{
    OK,
    ERR,
    UNKNOWN
};

class Response
{
public:
    Response() = delete;
    Response(const char buffer[BUFFER_LEN]);
    virtual ~Response();
    
    const ResponseCode retcode;

    string errMessage();
    
protected:
    /**
     * @brief Every invokation returns next string bounded by ""
     * 
     * @param buffer Response payload
     * @return string Token
     */
    string nextToken(const char buffer[BUFFER_LEN]);

    /**
     * @brief Returns ResponseCode according to chars in buffer
     * 
     * @param buffer Response payload
     * @return ResponseCode code
     */
    ResponseCode getResponseCode(const char buffer[BUFFER_LEN]);

    const char *_lastPos = 0;
    const char *_endIt = nullptr;

private:
    string _errMessage;
};
