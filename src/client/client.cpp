#include "network.h"
#include "imgui_ui.h"
#include "logger.h"
#include <iostream>
#include <thread>

int main() {
    std::string serverUri = "ws://localhost:9002";
    std::string username;

    std::cout << "Ingrese su nombre de usuario: ";
    std::cin >> username;

    ChatClient client;
    ChatUI ui;

    std::thread networkThread([&]() {
        client.connect(serverUri, username);
    });

    ui.init();
    ui.addLog("Conectando al servidor...", CONNECTIONS);

    while (!ui.shouldClose()) {
        ui.render();

        std::string recipient = ui.getRecipient();
        std::string message = ui.getMessageInput();
        
        if (!message.empty()) {
            client.sendMessage(recipient, message);
            ui.addLog("Mensaje enviado a " + recipient, MESSAGES);
        }
    }

    ui.shutdown();
    networkThread.join();

    return 0;
}
