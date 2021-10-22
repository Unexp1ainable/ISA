#include <iostream>
#include "base64.h"
#include "commands/commands.h"
#include "argument_parser.h"

using namespace std;
string encode(string toEncodeS);
string decode(string toDecodeS);

int main(int argc, char *argv[])
{

    try
    {
        auto args = ArgumentParser(argc, argv);
        CommandBase *command = nullptr;

        // process command
        switch (args.command())
        {
        case Command::REGISTER:
            command = new RegisterCommand(args);
            break;
        case Command::FETCH:
            command = new FetchCommand(args);
            break;
        case Command::LIST:
            command = new ListCommand(args);
            break;
        case Command::LOGIN:
            command = new LoginCommand(args);
            break;
        case Command::LOGOUT:
            command = new LogoutCommand(args);
            break;
        case Command::SEND:
            command = new SendCommand(args);
            break;
        default:
            throw InvalidCommandException();
            break;
        }
        // put command into unique_ptr, so the memory is automatically freed
        unique_ptr<CommandBase, function<void(CommandBase *)>>raii(command, [](CommandBase *c) {delete c;});

        auto response = command->execute();
        auto mess = response->message();

        // add newline if not already there
        if (*(mess.end() - 1) != '\n')
            mess += "\n";
        cout << mess;
    }

    catch (const std::exception &e)
    {
        cout << e.what() << endl;
        return 1;
    }

    return 0;
}
