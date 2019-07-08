#include "SendError.h"

SendError::SendError(QString error)
{
    errorMessage = error;
}

QString SendError::getErrorMessage()
{
    return errorMessage;
}
