#ifndef DATAMODEL_H
#define DATAMODEL_H

#include "QObject"
#include "QList"
#include "QStringListModel"
#include <QDoubleValidator>

class DataModel
{
private:
    QStringList values;
    QStringListModel* model;
    QDoubleValidator* validator;
private:
    double getCheckSum();
    bool hasData();
public:
    DataModel();
    ~DataModel();
    void addValue(QString value);
    void deleteValue(int i);
    QByteArray getDatagram();
    QStringListModel* getModel();
    QDoubleValidator* getValidator();
};

#endif // DATAMODEL_H
