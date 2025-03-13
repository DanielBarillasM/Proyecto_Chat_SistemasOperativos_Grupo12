// protocol.cpp - Implementación del protocolo WebSocket
#include "protocol.h"
#include <sstream>

// Serializar mensaje para enviarlo a través de WebSocket
std::string Protocol::serializeMessage(const Message& msg) {
    std::ostringstream oss;
    oss << msg.sender << "|" << msg.receiver << "|" << msg.content << "|" << msg.timestamp;
    return oss.str();
}

// Deserializar mensaje recibido desde WebSocket
Message Protocol::deserializeMessage(const std::string& data) {
    std::istringstream iss(data);
    Message msg;
    std::getline(iss, msg.sender, '|');
    std::getline(iss, msg.receiver, '|');
    std::getline(iss, msg.content, '|');
    std::getline(iss, msg.timestamp, '|');
    return msg;
}