#include <iostream>
#include "base64.h"

using namespace std;
string encode(string toEncodeS);
string decode(string toDecodeS);

int main(int argc, char *argv[])
{
    // for (int i = 0; i < argc; i++){
    //     cout << argv[i] << "\n";
    // }
    int a;
    cout << decode(argv[1]) << endl;

    return 0;
}

