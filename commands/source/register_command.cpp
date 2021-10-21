#include "../include/register_command.h"
#include "../../base64.h"

RegisterCommand::RegisterCommand(ArgumentParser &args) : CommandBase(args), _response()
{
    checkNArgs(2);
}

string RegisterCommand::getPayload() {
    string ret;
    ret += "(register \"";
    ret += _args.params()[0];
    ret += "\" \"";
    ret += encode(_args.params()[1]);
    ret += "\")";

    return ret;
}

Response *RegisterCommand::processResponse(char *buf) {
    _response = ResponseAnswer(buf);
    return &_response; 
}
