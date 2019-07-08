#ifndef SENDERROR_H
#define SENDERROR_H

#include <QString>
#include <exception>
#include <string>

class SendError : public std::exception
{
private:
    QString errorMessage;
public:
    SendError(QString error);
    QString getErrorMessage();
};


#endif // SENDERROR_H

