#ifndef USERS_H
#define USERS_H

#include <string>
#include <unordered_map>
#include <mutex>

enum UserStatus { ACTIVE, BUSY, INACTIVE, DISCONNECTED };

struct User {
    std::string username;
    std::string ip;
    UserStatus status;
};

class UserManager {
public:
    bool registerUser(const std::string& username, const std::string& ip);
    void removeUser(const std::string& username);
    bool userExists(const std::string& username);
    User getUserInfo(const std::string& username);
    std::string listUsers();
    void changeUserStatus(const std::string& username, UserStatus newStatus);

private:
    std::unordered_map<std::string, User> users;
    std::mutex userMutex;
};

#endif