#include "errors.h"
#include <string>

extern void logEventUI(const std::string& event);

const char* getErrorMessage(ErrorCode error) {
    switch (error) {
        case ERR_USER_NOT_FOUND:
            logEventUI(std::string("Error: Usuario no encontrado."));
            return "Usuario no encontrado.";
        case ERR_INVALID_STATUS:
            logEventUI(std::string("Error: Estado inválido."));
            return "Estado inválido.";
        case ERR_EMPTY_MESSAGE:
            logEventUI(std::string("Error: Mensaje vacío."));
            return "Mensaje vacío.";
        case ERR_USER_DISCONNECTED:
            logEventUI(std::string("Error: El usuario está desconectado."));
            return "El usuario está desconectado.";
        case ERR_UNAUTHORIZED_ACTION:
            logEventUI(std::string("Error: Acción no autorizada."));
            return "Acción no autorizada.";
        default:
            logEventUI(std::string("Error desconocido."));
            return "Error desconocido.";
    }
}
