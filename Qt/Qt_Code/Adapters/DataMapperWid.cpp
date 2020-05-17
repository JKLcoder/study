#include "DataMapperWid.h"
#include "ui_DataMapperWid.h"
#include "../TableModel/TableModel.h"
#include <QDataWidgetMapper>

DataMapperWid::DataMapperWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataMapperWid)
{
    ui->setupUi(this);

    TableModel *pModel = new TableModel(this);
    pMapper = new QDataWidgetMapper;
    pMapper->setModel(pModel);
    pMapper->setOrientation(Qt::Horizontal);  //映射一列，反之映射一行
    pMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit); //如果是AutoSubmit，那么我们做的任何修改都会立即调用setData同步到数据集中；如果是ManualSubmit，则我们必须调用submit()函数数据才会得到同步


    ui->lineEdit_0->setReadOnly(true);
    pMapper->addMapping(ui->lineEdit_0,0);
    pMapper->addMapping(ui->lineEdit_1,1);
    pMapper->addMapping(ui->lineEdit_2,2);

    pMapper->toFirst();
}

DataMapperWid::~DataMapperWid()
{
    delete ui;
}

void DataMapperWid::on_horizontalSlider_valueChanged(int value)
{
    pMapper->setCurrentIndex(value);
}
