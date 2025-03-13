#ifndef ERRORS_H
#define ERRORS_H

enum ErrorCode {
    ERR_USER_NOT_FOUND = 1,
    ERR_INVALID_STATUS = 2,
    ERR_EMPTY_MESSAGE = 3,
    ERR_USER_DISCONNECTED = 4,
    ERR_UNAUTHORIZED_ACTION = 5
};

const char* getErrorMessage(ErrorCode error);

#endif