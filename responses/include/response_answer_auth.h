#pragma once

#include "response_base.h"

class ResponseAnswerAuth : public Response
{
public:
    ResponseAnswerAuth() = default;
    ResponseAnswerAuth(const char buffer[BUFFER_LEN]);
    virtual const string message() const override;
    string answer;
    string token;
};
