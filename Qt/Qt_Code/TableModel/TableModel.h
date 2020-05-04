#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <string>
#include <vector>

using namespace std;

typedef struct{
    int index;
    QString country;
    QString address;
}QtData;

typedef vector<QtData> QtVec;

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    TableModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const;                             //返回列表列数
    int columnCount(const QModelIndex &parent) const;                          //返回列表行数
    QVariant data(const QModelIndex &index, int role) const;                   //返回对应index数据集中的数据
    Qt::ItemFlags flags(const QModelIndex &index) const;                       //返回对应index中的数据是否可编辑
    bool setData(const QModelIndex &index, const QVariant &value, int role);   //设置index中的某个数据，需要和数据集同步
    void insertRow(int row, const QModelIndex &parent);                        //插入列
    void insertColumn(int column, const QModelIndex &parent);                  //插入行
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;  //设置表头

private:
    void InitData();

private:
    QtVec vec;
};

#endif // TABLEMODEL_H
