#ifndef HANDLERS_H
#define HANDLERS_H

#include <string>

void handleNewConnection(const std::string& username);
void handleDisconnection(const std::string& username);
void handleMessageReceived(const std::string& sender, const std::string& recipient, const std::string& message);

#endif