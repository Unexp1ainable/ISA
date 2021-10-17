#pragma once

#include "../../argument_parser.h"
#include "../../exceptions.h"
#include "../../responses/responses.h"

#include <iostream>
#include <fstream>

class CommandBase {
public:
    virtual Response* execute() = 0;
    virtual Response* response() = 0;

protected:
    void checkNArgs(const int count, const int expected) const;
    string authToken();
};
