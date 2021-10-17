#pragma once

#include "command_base.h"

class FetchCommand : public CommandBase {
public:    
    FetchCommand(ArgumentParser& args);
    virtual ResponseFetch* execute() override;
    virtual ResponseFetch* response() override;
};
