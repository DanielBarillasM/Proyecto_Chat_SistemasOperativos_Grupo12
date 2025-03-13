#include "security.h"
#include "logger.h"
#include <iostream>
#include <unordered_map>
#include <mutex>

std::mutex securityMutex;
std::unordered_map<std::string, std::string> userTokens;

extern void logEventUI(const std::string& event);

bool authenticateUser(const std::string& username, const std::string& token) {
    std::lock_guard<std::mutex> lock(securityMutex);
    bool success = userTokens.find(username) != userTokens.end() && userTokens[username] == token;
    logEvent(success ? "Autenticación exitosa para " + username : "Fallo de autenticación para " + username);
    logEventUI(success ? "Autenticación exitosa para " + username : "Fallo de autenticación para " + username);
    return success;
}

void registerUserToken(const std::string& username, const std::string& token) {
    std::lock_guard<std::mutex> lock(securityMutex);
    userTokens[username] = token;
    logEvent("Token registrado para usuario: " + username);
    logEventUI("Token registrado para usuario: " + username);
}