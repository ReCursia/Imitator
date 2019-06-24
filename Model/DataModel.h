#ifndef DATAMODEL_H
#define DATAMODEL_H

#include "QList"
#include "QStringListModel"

class DataModel
{
private:
    QStringList values;
    QStringListModel* model;
private:
    double getCheckSum();
public:
    DataModel();
    ~DataModel();
    void addValue(QString value);
    void deleteValue(int i);
    QByteArray getDatagram();
    QStringListModel* getModel();
};

#endif // DATAMODEL_H
