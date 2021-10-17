#pragma once

#include "command_base.h"


class LogoutCommand : public CommandBase {
public:    
    LogoutCommand(ArgumentParser& args);
    virtual ResponseAnswer* execute() override;
    virtual ResponseAnswer* response() override;
};
