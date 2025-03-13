#include "sockets.h"
#include "logger.h"
#include <iostream>

extern void logEventUI(const std::string& event);
extern void updateConnectedUsers(const std::string& user);

ChatServer::ChatServer() {
    server.init_asio();
    server.set_open_handler(bind(&ChatServer::on_open, this, std::placeholders::_1));
    server.set_close_handler(bind(&ChatServer::on_close, this, std::placeholders::_1));
    server.set_message_handler(bind(&ChatServer::on_message, this, std::placeholders::_1, std::placeholders::_2));
}

void ChatServer::run(uint16_t port) {
    server.listen(port);
    server.start_accept();
    logEvent("Servidor escuchando en el puerto " + std::to_string(port));
    logEventUI("Servidor iniciado en puerto " + std::to_string(port));
    server.run();
}

void ChatServer::on_open(connection_hdl hdl) {
    logEvent("Nueva conexión establecida.");
    logEventUI("Nueva conexión establecida.");
    updateConnectedUsers("Usuario conectado.");
}

void ChatServer::on_close(connection_hdl hdl) {
    logEvent("Cliente desconectado.");
    logEventUI("Cliente desconectado.");
}

void ChatServer::on_message(connection_hdl hdl, websocket_server::message_ptr msg) {
    logEvent("Mensaje recibido: " + msg->get_payload());
    logEventUI("Mensaje recibido: " + msg->get_payload());
}