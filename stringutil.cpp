#include <algorithm>
#include <limits>
#include <stdexcept>

#include "stringutil.h"

bool StringUtil::isInteger(const std::string& str)
{
    if (str.empty()) return false;
    return std::all_of(str.begin(), str.end(),
                       [](unsigned char c) { return std::isdigit(c); });
}

int StringUtil::toInteger(const std::string& str)
{
    if (!isInteger(str))
    {
        throw std::invalid_argument("string is not a valid non-negative integer");
    }

    unsigned long long acc = 0;
    const unsigned long long maxInt = static_cast<unsigned long long>(std::numeric_limits<int>::max());

    for (unsigned char c : str)
    {
        acc = acc * 10 + (c - '0');
        if (acc > maxInt)
        {
            throw std::out_of_range("integer overflow");
        }
    }

    return static_cast<int>(acc);
}