#include "../include/list_command.h"

ListCommand::ListCommand(ArgumentParser& args) : CommandBase(args), _response()
{
    checkNArgs(0);
}

string ListCommand::getPayload() {
    string ret;
    ret += "(list ";
    ret += authToken();
    ret += ")";

    return ret;
}

Response *ListCommand::processResponse(char *buf) {
    _response = ResponseList(buf);
    return &_response; 
}
