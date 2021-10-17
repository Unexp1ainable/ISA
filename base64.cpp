
#include "base64.h"

// Why did I do this to myself? I have no idea.
string encode(string toEncodeS)
{
    static const char *lTable = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    reverse(toEncodeS.begin(), toEncodeS.end());
    const char *toEncode = toEncodeS.c_str();
    auto len = toEncodeS.length();
    auto iterations = len / 3;
    auto fin = len % 3;
    string encoded;
    for (int i = 0; i < iterations; i++)
    {
        auto tmp = *reinterpret_cast<const uint32_t *>(toEncode + len - 3 - i * 3);
        encoded += lTable[(tmp & (63u << 18)) >> 18];
        encoded += lTable[(tmp & (63u << 12)) >> 12];
        encoded += lTable[(tmp & (63u << 6)) >> 6];
        encoded += lTable[tmp & 63u];
    }

    auto tmp = *reinterpret_cast<const uint32_t *>(toEncode);
    switch (fin)
    {
    case 1:
        encoded += lTable[(tmp & (63u << 2)) >> 2];
        encoded += lTable[(tmp & (3u)) << 4];
        encoded += "==";
        break;

    case 2:
        encoded += lTable[(tmp & (63u << 10)) >> 10];
        encoded += lTable[(tmp & (63u << 4)) >> 4];
        encoded += lTable[(tmp & (15u)) << 2];
        encoded += "=";
        break;

    default:
        break;
    }

    return encoded;
}

string decode(string toDecodeS)
{
    static const string lTable = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    const char *toDecode = toDecodeS.c_str();
    auto len = toDecodeS.length();
    string decoded;
    for (int i = 0; i < len; i+=4)
    {

        uint32_t bits = 0;
        for (int j = 0; j < 4; j++)
        {
            auto f = lTable.find(toDecode[i+j]);
            bits |= f == string::npos ? 0 : f;
            bits <<= j != 3 ? 6 : 0;
        }
        char a = bits & 0xff;
        char b = (bits & (0xffu << 8)) >> 8;
        char c = (bits & (0xffu << 16)) >> 16;
        decoded += c;
        decoded += b;
        decoded += a;
    }
    return decoded;
}
