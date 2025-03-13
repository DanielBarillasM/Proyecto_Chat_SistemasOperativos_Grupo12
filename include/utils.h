#ifndef UTILS_H
#define UTILS_H

#include <string>

class Utils {
public:
    static std::string getCurrentTimestamp();
    static std::string trim(const std::string& str);
};

#endif