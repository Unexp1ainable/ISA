#pragma once

#include "response_base.h"

/**
 * @brief Answer from the server
 * 
 */
class ResponseAnswer : public Response
{
public:
    ResponseAnswer() = default;
    ResponseAnswer(const char buffer[BUFFER_LEN]);
    virtual const string message() const override;

    string answer;
};
