#pragma once

#include "response_base.h"


class ResponseFetch : public Response
{
public:
    ResponseFetch() : sender(), subject(), body() {}
    ResponseFetch(const char buffer[BUFFER_LEN]);
    virtual const string message() const override;
    string sender;
    string subject;
    string body;
};
