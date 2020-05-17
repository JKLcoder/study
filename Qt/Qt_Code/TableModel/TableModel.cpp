#include <QDebug>
#include "TableModel.h"

TableModel::TableModel(QObject *parent)
{
    InitData();
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    return vec.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if(role != Qt::DisplayRole && role != Qt::EditRole|| !index.isValid())  //eg.也可以设置Qt::FontRole,即字体
        return QVariant();
    QtData data = vec[index.row()];

    switch (index.column()) {
    case 0:
        return data.index;
        break;
    case 1:
        return data.country;
        break;
    case 2:
        return data.address;
        break;
    }
    return QVariant();
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable| Qt::ItemIsDragEnabled | QAbstractTableModel::flags(index); //必须要有后面的，否则默认的flags就无效了
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

    QtData data = vec[index.row()];
    int column = index.column();

    switch (column) {
    case 0:
        data.index = value.toInt();
        break;
    case 1:
        data.country = value.toString();
        break;
    case 2:
        data.address = value.toString();
        break;
    }

    vec[index.row()] = data;

    emit dataChanged(index,index);  //发出该信号用于刷新模型
    return true;
}

void TableModel::insertRow(int row, const QModelIndex &parent)
{

}

void TableModel::insertColumn(int column, const QModelIndex &parent)
{

}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();

    if(orientation == Qt::Horizontal)
    {
        switch (section) {
        case 0:
            return QString("Index");
            break;
        case 1:
            return QString("Country");
            break;
        case 2:
            return QString("Address");
            break;
        }
    }
    return QVariant();
}

void TableModel::InitData()
{
    QtData data;
    data.index = 1;data.country = "Qt Norway";   data.address = "Oslo";          vec.push_back(data);
    data.index = 2;data.country = "Qt Australia";data.address = "Brisbane";      vec.push_back(data);
    data.index = 3;data.country = "Qt USA";      data.address = "Silicon Valley";vec.push_back(data);
    data.index = 4;data.country = "Qt China";    data.address = "Beijing";       vec.push_back(data);
    data.index = 5;data.country = "Qt Germany";  data.address = "Berlin";        vec.push_back(data);
}

