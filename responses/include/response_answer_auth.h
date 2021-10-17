#pragma once

#include "response_base.h"


class ResponseAnswerAuth : public Response
{
public:
    ResponseAnswerAuth(const char buffer[BUFFER_LEN]);
    const string answer;
    const string token;
};
