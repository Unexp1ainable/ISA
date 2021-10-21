#include "../include/login_command.h"
#include "../../base64.h"

LoginCommand::LoginCommand(ArgumentParser &args)  : CommandBase(args), _response()
{
    checkNArgs(2);
}

string LoginCommand::getPayload() {
    string ret;
    ret += "(login \"";
    ret += _args.params()[0];
    ret += "\" \"";
    ret += encode(_args.params()[1]);
    ret += "\")";

    return ret;
}

Response *LoginCommand::processResponse(char *buf) {
    _response = ResponseAnswerAuth(buf);
    return &_response; 
}
