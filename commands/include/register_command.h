#pragma once

#include "command_base.h"

class RegisterCommand : public CommandBase {
public:
    RegisterCommand(ArgumentParser& args);
    virtual ResponseAnswer* execute() override;
    virtual ResponseAnswer* response() override;
private:
    string _login;
    string _password;
};
