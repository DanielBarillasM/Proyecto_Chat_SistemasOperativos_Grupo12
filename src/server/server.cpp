#include "sockets.h"
#include "logger.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <vector>
#include <string>

GLFWwindow* window;
std::vector<std::string> logMessages;
std::vector<std::string> connectedUsers;

void logEventUI(const std::string& event) {
    logMessages.push_back(event);
}

void updateConnectedUsers(const std::string& user) {
    connectedUsers.push_back(user);
}

void renderUI() {
    if (!glfwInit()) return;

    window = glfwCreateWindow(800, 600, "Servidor de Chat", NULL, NULL);
    glfwMakeContextCurrent(window);
    
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        
        // Ventana de Logs
        ImGui::Begin("Logs del Servidor");
        for (const auto& log : logMessages) {
            ImGui::TextWrapped("%s", log.c_str());
        }
        ImGui::End();

        // Ventana de Usuarios Conectados
        ImGui::Begin("Usuarios Conectados");
        for (const auto& user : connectedUsers) {
            ImGui::TextWrapped("• %s", user.c_str());
        }
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
}

int main() {
    ChatServer server;
    std::thread serverThread([&server]() { server.run(9002); });

    renderUI();

    serverThread.join();
    return 0;
}