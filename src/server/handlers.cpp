#include "handlers.h"
#include "logger.h"
#include <iostream>

extern void logEventUI(const std::string& event);

void handleNewConnection(const std::string& username) {
    logEvent("Nuevo usuario conectado: " + username);
    logEventUI("Nuevo usuario conectado: " + username);
}

void handleDisconnection(const std::string& username) {
    logEvent("Usuario desconectado: " + username);
    logEventUI("Usuario desconectado: " + username);
}

void handleMessageReceived(const std::string& sender, const std::string& recipient, const std::string& message) {
    logEvent("Mensaje de " + sender + " para " + recipient + ": " + message);
    logEventUI("Mensaje de " + sender + " para " + recipient + ": " + message);
}