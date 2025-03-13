#include "errors.h"

extern void logEventUI(const std::string& event);

const char* getErrorMessage(ErrorCode error) {
    switch (error) {
        case ERR_USER_NOT_FOUND:
            logEventUI("Error: Usuario no encontrado.");
            return "Usuario no encontrado.";
        case ERR_INVALID_STATUS:
            logEventUI("Error: Estado inválido.");
            return "Estado inválido.";
        case ERR_EMPTY_MESSAGE:
            logEventUI("Error: Mensaje vacío.");
            return "Mensaje vacío.";
        case ERR_USER_DISCONNECTED:
            logEventUI("Error: El usuario está desconectado.");
            return "El usuario está desconectado.";
        case ERR_UNAUTHORIZED_ACTION:
            logEventUI("Error: Acción no autorizada.");
            return "Acción no autorizada.";
        default:
            logEventUI("Error desconocido.");
            return "Error desconocido.";
    }
}