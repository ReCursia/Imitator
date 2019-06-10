#ifndef DATAMODEL_H
#define DATAMODEL_H

#include "QList"
#include "QStringListModel"
class DataModel
{
private:
    QStringList values;
    QStringListModel* model;
public:

    DataModel();
    ~DataModel();
    float getValue(int i);
    void addValue(QString value);
    void deleteValue(int i);
    void clear();
    int size();
    QByteArray getDatagramm();
    float getCheckSum();
    QStringListModel* getModel();
};

#endif // DATAMODEL_H
