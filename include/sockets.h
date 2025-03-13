#ifndef SOCKETS_H
#define SOCKETS_H

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <unordered_map>

typedef websocketpp::server<websocketpp::config::asio> websocket_server;
typedef websocketpp::connection_hdl connection_hdl;

class ChatServer {
public:
    ChatServer();
    void run(uint16_t port);
    void on_open(connection_hdl hdl);
    void on_close(connection_hdl hdl);
    void on_message(connection_hdl hdl, websocket_server::message_ptr msg);

private:
    websocket_server server;
    std::unordered_map<connection_hdl, std::string, std::hash<connection_hdl>> clients;
};

#endif