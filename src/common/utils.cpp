// utils.cpp - Funciones auxiliares (parsing, timestamp)
#include "utils.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

// Obtener el timestamp actual en formato legible
std::string Utils::getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto nowTimeT = std::chrono::system_clock::to_time_t(now);
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&nowTimeT), "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

// Limpiar un string de espacios en blanco al inicio y al final
std::string Utils::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}