#pragma once

#include "command_base.h"

class LoginCommand : public CommandBase
{
public:
    LoginCommand(ArgumentParser &args);
    virtual string getPayload() override;
    virtual ResponseAnswerAuth *response() override { return &_response; };

protected:
    virtual Response *processResponse(char *buf) override;
    ResponseAnswerAuth _response;
};
