#pragma once

#include "command_base.h"

using namespace std;

class RegisterCommand : public CommandBase
{
public:
    RegisterCommand(ArgumentParser &args);
    virtual string getPayload() override;
    virtual Response *response() override { return &_response; };

protected:
    virtual Response *processResponse(char *buf) override;
    ResponseAnswer _response;
};
