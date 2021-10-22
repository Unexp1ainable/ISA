#pragma once

#include <string.h>
#include <algorithm>
#include <memory>
#include <functional>
#include <bitset>

using namespace std;
/**
 * @brief Encodes string into base64
 * 
 * @param toEncodeS string to encode
 * @return string encoded string
 */
string encode(string toEncodeS);

/**
 * @brief Decodes string from base64
 * 
 * @param toDecodeS string to decode
 * @return string decoded string
 */
string decode(string toDecodeS);
