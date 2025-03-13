#include "users.h"
#include "logger.h"
#include <iostream>
#include <mutex>

std::mutex userMutex;
std::unordered_map<std::string, User> users;

extern void logEventUI(const std::string& event);
extern void updateConnectedUsers(const std::string& user);

bool registerUser(const std::string& username, const std::string& ip) {
    std::lock_guard<std::mutex> lock(userMutex);
    if (users.find(username) != users.end()) return false;
    users[username] = { username, ip, ACTIVE };
    logEvent("Usuario registrado: " + username);
    logEventUI("Usuario registrado: " + username);
    updateConnectedUsers(username);
    return true;
}

void removeUser(const std::string& username) {
    std::lock_guard<std::mutex> lock(userMutex);
    users.erase(username);
    logEvent("Usuario eliminado: " + username);
    logEventUI("Usuario eliminado: " + username);
}