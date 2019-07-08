#include "DataModel.h"
#include "Exceptions/EmptyData.h"
#include <QDebug>

DataModel::DataModel()
{
    //Validator
    validator = new QIntValidator();
    validator->setLocale(QLocale(QLocale::English));
    //Model
    model = new QStringListModel();
    model->setStringList(values);
}

DataModel::~DataModel()
{
    delete model;
    delete validator;
}

void DataModel::addValue(QString value)
{
    values.append(QString::number(value.toDouble()));
    model->setStringList(values);
}

void DataModel::deleteValue(int i)
{
    values.removeAt(i);
    model->setStringList(values);
}

void DataModel::clear()
{
    values.clear();
    model->setStringList(values);
}

QByteArray DataModel::getDatagram()
{
    if(!hasData()) throw EmptyData();
    QByteArray datagram;
    foreach(QString value,values){
        datagram.append(value).append(' ');
    }
    //Adding check sum
    datagram.append(QString::number(getCheckSum())).append(' ');
    return datagram;
}

bool DataModel::hasData()
{
    return !values.isEmpty();
}

double DataModel::getCheckSum()
{
    double sum = 0;
    foreach(QString value,values){
        sum += value.toInt();
    }
    return sum;
}

QStringListModel *DataModel::getModel()
{
    return model;
}

QValidator *DataModel::getValidator()
{
    return validator;
}

void DataModel::generateRandomData()
{
    srand(time(nullptr));
    for(int i = 0; i < MAX_VALUE;i++){
        values.append(QString::number((rand() % 1000)+500));
    }
    model->setStringList(values);
}
