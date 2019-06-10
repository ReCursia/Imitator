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

float DataModel::getValue(int i)
{
    return values.value(i).toFloat();
}

void DataModel::addValue(QString value)
{
    values.append(QString::number(value.toFloat()));
    model->setStringList(values); //TODO исправить! каждый раз переопредять лист для модели? Возможно некорректно?
}

void DataModel::deleteValue(int i)
{
    values.removeAt(i);
    model->setStringList(values); //TODO исправить! каждый раз переопредять лист для модели? Возможно некорректно?
}

void DataModel::clear()
{
    values.clear();
}

int DataModel::size()
{
    return values.size();
}

QByteArray DataModel::getDatagramm()
{
    //TODO implement
}

float DataModel::getCheckSum()
{
    float sum = 0;
    foreach(QString value,values){
        sum += value.toFloat();
    }
    return sum;
}

QStringListModel *DataModel::getModel()
{
    return model;
}
