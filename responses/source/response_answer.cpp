#include "../include/response_answer.h"

ResponseAnswer::ResponseAnswer(const char buffer[BUFFER_LEN]) : 
Response(buffer), 
answer(nextToken(buffer))
{ }

const string ResponseAnswer::message() const {
    if (retcode == ResponseCode::OK){
    return "SUCCESS: " + answer;
    }
    return "ERROR: " + _errMessage;
}
