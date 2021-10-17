#pragma once

#include "response_base.h"


class ResponseFetch : public Response
{
public:
    ResponseFetch(const char buffer[BUFFER_LEN]);
    const string sender;
    const string subject;
    const string message;
};
