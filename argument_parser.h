#pragma once
#include <string>
#include <vector>
#include "common.h"

using namespace std;

class ArgumentParser
{
public:
    ArgumentParser() = delete;
    ArgumentParser(int argc, char* argv[]);

    const vector<string> params() const { return _params; }
    Command command() const { return _command; }
    const int count() const { return _params.size(); }
    const string ip() const { return _ip; }
    const int port() const { return _port; }
private:
    void setCommand(Command s);
    string _ip = "::1";
    int _port = 32323;
    Command _command = Command::UNKNOWN;
    vector<string> _params;

    const char* _help = 
R"(usage: client [ <option> ... ] <command> [<args>] ...

<option> is one of

  -a <addr>, --address <addr>
     Server hostname or address to connect to
  -p <port>, --port <port>
     Server port to connect to
  --help, -h
     Show this help
  --
     Do not treat any remaining argument as a switch (at this level)

 Multiple single-letter switches can be combined after
 one `-`. For example, `-h-` is the same as `-h --`.
 Supported commands:
   register <username> <password>
   login <username> <password>
   list
   send <recipient> <subject> <body>
   fetch <id>
   logout)";
};
