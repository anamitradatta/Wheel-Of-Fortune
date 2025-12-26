#include <string>

#ifndef STRINGUTIL_H
#define STRINGUTIL_H
class StringUtil
{
    public:
        static bool isInteger(const std::string& str);
        static int toInteger(const std::string& str);
};
#endif
