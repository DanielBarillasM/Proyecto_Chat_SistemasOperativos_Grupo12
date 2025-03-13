#include "network.h"
#include "logger.h"
#include <iostream>

ChatClient::ChatClient() {
    client.init_asio();
    client.set_open_handler(bind(&ChatClient::on_open, this, std::placeholders::_1));
    client.set_close_handler(bind(&ChatClient::on_close, this, std::placeholders::_1));
    client.set_message_handler(bind(&ChatClient::on_message, this, std::placeholders::_1, std::placeholders::_2));
}

void ChatClient::connect(const std::string& uri, const std::string& username) {
    websocketpp::lib::error_code ec;
    auto con = client.get_connection(uri + "?name=" + username, ec);

    if (ec) {
        std::cerr << "Error al conectar: " << ec.message() << std::endl;
        return;
    }

    connection = con->get_handle();
    client.connect(con);
    client.run();
}

void ChatClient::sendMessage(const std::string& recipient, const std::string& msg) {
    std::string formattedMessage = "msg:" + recipient + "->" + msg;
    client.send(connection, formattedMessage, websocketpp::frame::opcode::text);
}

void ChatClient::on_message(connection_hdl hdl, websocket_client::message_ptr msg) {
    std::cout << "Mensaje recibido: " << msg->get_payload() << std::endl;
    logEvent("Mensaje recibido: " + msg->get_payload());
}
