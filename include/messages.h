#ifndef MESSAGES_H
#define MESSAGES_H

#include <string>
#include <vector>
#include <mutex>

struct Message {
    std::string sender;
    std::string receiver;
    std::string content;
    std::string timestamp;
};

class MessageManager {
public:
    void storeMessage(const Message& msg);
    std::vector<Message> getMessagesForUser(const std::string& username);
    std::vector<Message> getBroadcastMessages();

private:
    std::vector<Message> broadcastMessages;
    std::unordered_map<std::string, std::vector<Message>> userMessages;
    std::mutex messageMutex;
};

#endif