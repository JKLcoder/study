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
    QDataWidgetMapper *pMapper = new QDataWidgetMapper;
    pMapper->setModel(pModel);
    pMapper->setOrientation(Qt::Horizontal);
    pMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    pMapper->addMapping(ui->lineEdit_0,0);
    pMapper->addMapping(ui->lineEdit_1,1);
    pMapper->addMapping(ui->lineEdit_2,2);

    pMapper->toFirst();
}

DataMapperWid::~DataMapperWid()
{
    delete ui;
}
