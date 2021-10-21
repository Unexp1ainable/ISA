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
    Response() = default;
    Response(const char buffer[BUFFER_LEN]);
    virtual ~Response() = default;
    
    ResponseCode retcode = ResponseCode::UNKNOWN;

    virtual const string message() const = 0;
    
protected:
    /**
     * @brief Every invokation returns next string bounded by ""
     * 
     * @param buffer Response payload
     * @return string Token
     */
    string nextToken(const char buffer[BUFFER_LEN]);

    pair<string, int> nextToken(const char buffer[BUFFER_LEN], int pos);

    /**
     * @brief Returns ResponseCode according to chars in buffer
     * 
     * @param buffer Response payload
     * @return ResponseCode code
     */
    ResponseCode getResponseCode(const char buffer[BUFFER_LEN]);

    const char *_lastPos = nullptr;
    const char *_endIt = nullptr;
    string _errMessage = "";
};
