#pragma once

#include "../../common.h"
#include <algorithm>
#include <charconv>
#include <string>
#include <vector>
#include "string.h"

using namespace std;

/**
 * @brief Return code of the server response
 * 
 */
enum class ResponseCode
{
    OK,
    ERR,
    UNKNOWN
};

/**
 * @brief Base class for all responses
 * 
 */
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

    /**
     * @brief Find string bounded by "" in the buffer, starting at pos
     * 
     * @param buffer Where to look for token
     * @param pos Where to start searching
     * @return pair<string, int> Found token and its length
     */
    pair<string, int> nextToken(const char buffer[BUFFER_LEN], int pos);

    /**
     * @brief Returns ResponseCode according to chars in buffer
     * 
     * @param buffer Response payload
     * @return ResponseCode code
     */
    ResponseCode getResponseCode(const char buffer[BUFFER_LEN]);

    // internal counters used by nextToken()
    const char *_lastPos = nullptr;
    const char *_endIt = nullptr;

    // error message from the server
    string _errMessage = "";
};
