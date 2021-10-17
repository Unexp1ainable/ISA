#pragma once

#include "command_base.h"

class ListCommand : public CommandBase {
public:
    ListCommand(ArgumentParser& args);
    virtual ResponseList* execute() override;
    virtual ResponseList* response() override;
};
