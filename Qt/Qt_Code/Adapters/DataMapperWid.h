#ifndef DATAMAPPERWID_H
#define DATAMAPPERWID_H

#include <QWidget>

namespace Ui {
class DataMapperWid;
}

class DataMapperWid : public QWidget
{
    Q_OBJECT

public:
    explicit DataMapperWid(QWidget *parent = 0);
    ~DataMapperWid();

private:
    Ui::DataMapperWid *ui;
};

#endif // DATAMAPPERWID_H
