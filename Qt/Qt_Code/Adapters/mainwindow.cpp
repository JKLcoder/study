#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "DataMapperWid.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DataMapperWid *pWid = new DataMapperWid(this);
    setCentralWidget(pWid);


}

MainWindow::~MainWindow()
{
    delete ui;
}
