#pragma once

#include "command_base.h"

class ListCommand : public CommandBase
{
public:
    ListCommand(ArgumentParser &args);
    virtual string getPayload() override;
    virtual ResponseList *response() override { return &_response; };

protected:
    virtual Response *processResponse(char *buf) override;

    ResponseList _response;
};
