#include "DataModel.h"


DataModel::DataModel()
{
    model = new QStringListModel();
    model->setStringList(values);
}

DataModel::~DataModel()
{
    delete model;
}

void DataModel::addValue(QString value)
{
    values.append(QString::number(value.toDouble()));
    model->setStringList(values); //TODO исправить! каждый раз переопредять лист для модели? Возможно некорректно?
}

void DataModel::deleteValue(int i)
{
    values.removeAt(i);
    model->setStringList(values); //TODO исправить! каждый раз переопредять лист для модели? Возможно некорректно?
}

QByteArray DataModel::getDatagram()
{
    QByteArray datagram;
    foreach(QString value,values){
        datagram.append(value).append(' ');
    }
    datagram.append(QString::number(getCheckSum()));
    return datagram;
}

double DataModel::getCheckSum()
{
    double sum = 0;
    foreach(QString value,values){
        sum += value.toDouble();
    }
    return sum;
}

QStringListModel *DataModel::getModel()
{
    return model;
}
