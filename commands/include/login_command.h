#pragma once

#include "command_base.h"

class LoginCommand : public CommandBase {
public:
    LoginCommand(ArgumentParser& args);
    virtual ResponseAnswerAuth* execute() override;
    virtual ResponseAnswerAuth* response() override;
private:
    string _login;
    string _password;
};
