#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TableModel.h"
#include <QTableView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitUi()
{
    QTableView *view = new QTableView(this);
    TableModel *model = new TableModel(this);
    view->setModel(model);

    setCentralWidget(view);
}
