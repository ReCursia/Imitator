#ifndef DATAMODEL_H
#define DATAMODEL_H

#include "QObject"
#include "QList"
#include "QStringListModel"
#include <QDoubleValidator>

const int MAX_VALUE = 2000;

class DataModel
{
private:
    QStringList values;
    QStringListModel* model;
    QIntValidator* validator;
private:
    double getCheckSum();
    bool hasData();
public:
    DataModel();
    ~DataModel();
    void addValue(QString value);
    void deleteValue(int i);
    void clear();
    QByteArray getDatagram();
    QStringListModel* getModel();
    QValidator* getValidator();
    void generateRandomData();
};

#endif // DATAMODEL_H
