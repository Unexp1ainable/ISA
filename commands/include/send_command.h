#pragma once

#include "command_base.h"

class SendCommand : public CommandBase {
public:    
    SendCommand(ArgumentParser& args);
    virtual ResponseAnswer* execute() override;
    virtual ResponseAnswer* response() override;
};
