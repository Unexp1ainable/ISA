#include "../include/register_command.h"

RegisterCommand::RegisterCommand(ArgumentParser &args)
{
    checkNArgs(args.count(), 2);

    _login = args.params()[0];
    _password = args.params()[1];
}
