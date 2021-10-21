#include "../include/send_command.h"

SendCommand::SendCommand(ArgumentParser& args) : CommandBase(args), _response()
{
    checkNArgs(3);
}

string SendCommand::getPayload() {
    string ret;
    ret += "(send ";
    ret += authToken();
    ret += " \"";
    ret += _args.params()[0];
    ret += "\" \"";
    ret += _args.params()[1];
    ret += "\" \"";
    ret += _args.params()[2];
    ret += "\")";

    return ret;
}

Response *SendCommand::processResponse(char *buf) {
    _response = ResponseAnswer(buf);
    return &_response; 
}
