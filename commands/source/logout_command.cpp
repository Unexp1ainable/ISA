#include "../include/logout_command.h"

LogoutCommand::LogoutCommand(ArgumentParser& args) : CommandBase(args), _response()
{
    checkNArgs(0);
}

string LogoutCommand::getPayload() {
    string ret;
    ret += "(logout ";
    ret += authToken();
    ret += ")";

    return ret;
}

Response *LogoutCommand::processResponse(char *buf) {
    _response = ResponseAnswer(buf);
    if (_response.retcode == ResponseCode::OK){
        int failure = remove("login-token");
        if (failure){
            throw UserNotLoggedInException();
        }
    }
    return &_response; 
}
