#pragma once

#include "response_base.h"


class ResponseAnswer : public Response
{
public:
    ResponseAnswer() = default;
    ResponseAnswer(const char buffer[BUFFER_LEN]);
    virtual const string message() const override;

    string answer;
};
