#include "../include/response_base.h"


Response::Response(const char buffer[BUFFER_LEN])  : retcode(getResponseCode(buffer)), _errMessage()
{
    if (retcode == ResponseCode::ERR){
        _errMessage = nextToken(buffer);
    }
}


string Response::nextToken(const char buffer[BUFFER_LEN]) {
    if (!_endIt)
        _endIt = buffer + strlen(buffer);
    auto start = std::find(buffer, _endIt, '\"');
    if (start == _endIt)
        return "";
    auto end = std::find(start+1, _endIt, '\"');
    if (start == _endIt)
        return "";

    _lastPos = end+1;
    return string(start, end);
}

ResponseCode Response::getResponseCode(const char buffer[BUFFER_LEN]) {
    if (strlen(buffer) < 4) {
        return ResponseCode::UNKNOWN;
    }

    // too lazy to use strcmp or something else
    if (buffer[1] == 'o' && buffer[2] == 'k')
        return ResponseCode::OK;
    else if (buffer[1] == 'e' && buffer[2] == 'r'&& buffer[3] == 'r')
        return ResponseCode::ERR;
    else
        return ResponseCode::UNKNOWN;
}
