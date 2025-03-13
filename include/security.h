#ifndef SECURITY_H
#define SECURITY_H

#include <string>
#include <unordered_map>

bool authenticateUser(const std::string& username, const std::string& token);
void registerUserToken(const std::string& username, const std::string& token);

#endif