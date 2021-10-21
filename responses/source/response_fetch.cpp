#include "../include/response_fetch.h"

ResponseFetch::ResponseFetch(const char buffer[BUFFER_LEN]) : 
Response(buffer),
sender(nextToken(buffer)),
subject(nextToken(buffer)),
body(nextToken(buffer))
{ }

const string ResponseFetch::message() const {
    string ret{};
    if (retcode == ResponseCode::OK)
    {
        ret += "SUCCESS:\n\n";
        ret += "From: " + sender + "\n";
        ret += "Subject: " + subject + "\n\n";
        ret += body;
    }
    else
    {
        ret += "ERROR: ";
        ret += _errMessage;
    }
    return ret;
}
