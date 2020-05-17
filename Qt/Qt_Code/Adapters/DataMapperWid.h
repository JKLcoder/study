#ifndef DATAMAPPERWID_H
#define DATAMAPPERWID_H

#include <QWidget>

namespace Ui {
class DataMapperWid;
}

class QDataWidgetMapper;
class DataMapperWid : public QWidget
{
    Q_OBJECT

public:
    explicit DataMapperWid(QWidget *parent = 0);
    ~DataMapperWid();

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::DataMapperWid *ui;
    QDataWidgetMapper *pMapper;
};

#endif // DATAMAPPERWID_H
