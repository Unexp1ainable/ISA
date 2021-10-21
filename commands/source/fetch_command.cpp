#include "../include/fetch_command.h"

FetchCommand::FetchCommand(ArgumentParser& args) : CommandBase(args), _response()
{
    checkNArgs(1);
}

string FetchCommand::getPayload() {
    string ret;
    ret += "(fetch ";
    ret += authToken();
    ret += " ";
    ret += _args.params()[0];
    ret += ")";

    return ret;
}

Response *FetchCommand::processResponse(char *buf) {
    _response = ResponseFetch(buf);
    return &_response;
}
