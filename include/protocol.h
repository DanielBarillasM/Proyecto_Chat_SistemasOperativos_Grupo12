#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string>

struct Message {
    std::string sender;
    std::string receiver;
    std::string content;
    std::string timestamp;
};

class Protocol {
public:
    static std::string serializeMessage(const Message& msg);
    static Message deserializeMessage(const std::string& data);
};

#endif