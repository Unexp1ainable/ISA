#include "../include/login_command.h"

LoginCommand::LoginCommand(ArgumentParser &args)
{
    checkNArgs(args.count(), 2);

    _login = args.params()[0];
    _password = args.params()[1];
}
