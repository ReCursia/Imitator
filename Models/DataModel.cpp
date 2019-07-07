#include "DataModel.h"
#include "Exceptions/EmptyData.h"

DataModel::DataModel()
{
    //Validator
    validator = new QDoubleValidator();
    validator->setNotation(QDoubleValidator::StandardNotation);
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

QByteArray DataModel::getDatagram()
{
    if(!hasData()) throw EmptyData();
    QByteArray datagram;
    foreach(QString value,values){
        datagram.append(value).append(' ');
    }
    //TODO добавить тики
    datagram.append(QString::number(getCheckSum()));
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
        sum += value.toDouble();
    }
    return sum;
}

QStringListModel *DataModel::getModel()
{
    return model;
}

QDoubleValidator *DataModel::getValidator()
{
    return validator;
}
