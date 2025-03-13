#include "imgui_ui.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

GLFWwindow* window;

ChatUI::ChatUI() : closeRequested(false), recipient("~") {}

void ChatUI::init() {
    if (!glfwInit()) return;
    
    window = glfwCreateWindow(800, 600, "Chat Cliente", NULL, NULL);
    glfwMakeContextCurrent(window);
    
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");
}

void ChatUI::render() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Ventana de Chat
        ImGui::SetNextWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
        ImGui::Begin("Chat - Cliente");

        ImGui::BeginChild("ChatHistory", ImVec2(0, 350), true, ImGuiWindowFlags_AlwaysVerticalScrollbar);
        for (const auto& msg : chatHistory) {
            ImGui::TextWrapped("%s", msg.c_str());
        }
        ImGui::EndChild();

        ImGui::Separator();

        // Entrada de Mensaje
        ImGui::Text("Enviar a:");
        ImGui::SameLine();
        ImGui::InputText("##Recipient", &recipient[0], recipient.capacity(), ImGuiInputTextFlags_CharsNoBlank);
        
        ImGui::Text("Mensaje:");
        ImGui::SameLine();
        ImGui::InputText("##Message", &messageInput[0], messageInput.capacity(), ImGuiInputTextFlags_EnterReturnsTrue);

        ImGui::SameLine();
        if (ImGui::Button("Enviar")) {
            if (!messageInput.empty()) {
                chatHistory.push_back("Yo -> " + recipient + ": " + messageInput);
                messageInput.clear();
            }
        }

        ImGui::SameLine();
        if (ImGui::Button("Salir")) {
            closeRequested = true;
            break;
        }

        ImGui::End();

        // Ventana de Logs
        ImGui::SetNextWindowSize(ImVec2(800, 200), ImGuiCond_FirstUseEver);
        ImGui::Begin("Eventos del Chat");

        ImGui::Text("Filtrar por:");
        if (ImGui::Button("Todos")) activeFilter = ALL;
        ImGui::SameLine();
        if (ImGui::Button("Mensajes")) activeFilter = MESSAGES;
        ImGui::SameLine();
        if (ImGui::Button("Conexiones")) activeFilter = CONNECTIONS;
        ImGui::SameLine();
        if (ImGui::Button("Errores")) activeFilter = ERRORS;

        ImGui::Separator();
        ImGui::BeginChild("LogHistory", ImVec2(0, 150), true, ImGuiWindowFlags_AlwaysVerticalScrollbar);
        for (const auto& log : logMessages) {
            if (activeFilter == ALL || log.second == activeFilter) {
                ImGui::TextWrapped("%s", log.first.c_str());
            }
        }
        ImGui::EndChild();

        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }
}

void ChatUI::shutdown() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool ChatUI::shouldClose() {
    return closeRequested;
}

std::string ChatUI::getMessageInput() {
    return messageInput;
}

std::string ChatUI::getRecipient() {
    return recipient;
}

void ChatUI::addMessage(const std::string& sender, const std::string& message) {
    chatHistory.push_back(sender + ": " + message);
}

void ChatUI::addLog(const std::string& logMessage, LogFilter type) {
    logMessages.emplace_back(logMessage, type);
}