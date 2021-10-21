#include "../include/response_answer_auth.h"
#include <iostream>
#include <fstream>

ResponseAnswerAuth::ResponseAnswerAuth(const char buffer[BUFFER_LEN]) :
Response(buffer), 
answer(nextToken(buffer)),
token(nextToken(buffer))
{ 
    auto file = fstream("login-token", ios::out);
    file << "\"" << token << "\"";
    file.close();
}

const string ResponseAnswerAuth::message() const {
    if (retcode == ResponseCode::OK){
    return answer;
    }
    return _errMessage;
}
