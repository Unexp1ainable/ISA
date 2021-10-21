#pragma once

#include "command_base.h"

class SendCommand : public CommandBase
{
public:
    SendCommand(ArgumentParser &args);
    virtual string getPayload() override;
    virtual ResponseAnswer *response() override { return &_response; };

protected:
    virtual Response *processResponse(char *buf) override;
    ResponseAnswer _response;
};
