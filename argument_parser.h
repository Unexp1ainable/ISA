#pragma once
#include <string>
#include <vector>

using namespace std;

class ArgumentParser
{
public:
    ArgumentParser() = delete;
    ArgumentParser(int argc, char* argv[]);

    const vector<string> params() const { return _params; }
    const string command() const { return _command; }
    const int count() const { return _params.size(); }
private:
    string _ip = "::1";
    int _port = 32323;
    string _command;
    vector<string> _params;
};
