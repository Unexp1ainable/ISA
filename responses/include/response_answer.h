#pragma once

#include "response_base.h"


class ResponseAnswer : public Response
{
public:
    ResponseAnswer(const char buffer[BUFFER_LEN]);
    const string answer;
};
