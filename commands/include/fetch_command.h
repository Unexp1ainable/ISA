#pragma once

#include "command_base.h"

class FetchCommand : public CommandBase
{
public:
    FetchCommand(ArgumentParser &args);
    virtual string getPayload() override;
    virtual ResponseFetch *response() override { return &_response; }

protected:
    virtual Response *processResponse(char *buf) override;
    ResponseFetch _response;

};
