#include "messages.h"
#include "logger.h"
#include <iostream>
#include <vector>
#include <mutex>

std::mutex messageMutex;
std::vector<Message> messages;

extern void logEventUI(const std::string& event);

void storeMessage(const Message& msg) {
    std::lock_guard<std::mutex> lock(messageMutex);
    messages.push_back(msg);
    logEvent("Mensaje guardado: " + msg.sender + " -> " + msg.receiver);
    logEventUI("Mensaje guardado: " + msg.sender + " -> " + msg.receiver);
}

std::vector<Message> getMessagesForUser(const std::string& username) {
    std::lock_guard<std::mutex> lock(messageMutex);
    std::vector<Message> userMessages;
    for (const auto& msg : messages) {
        if (msg.receiver == username || msg.receiver == "~") {
            userMessages.push_back(msg);
        }
    }
    return userMessages;
}