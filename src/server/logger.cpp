#include "logger.h"
#include <fstream>
#include <ctime>
#include <iostream>

extern void logEventUI(const std::string& event);

void logEvent(const std::string& event) {
    std::ofstream logFile("server.log", std::ios_base::app);
    if (!logFile) return;
    
    time_t now = time(0);
    char* dt = ctime(&now);
    logFile << "[" << dt << "] " << event << std::endl;
    std::cout << event << std::endl;

    logEventUI(event);
}