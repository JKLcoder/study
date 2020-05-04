/********************************************************************************
** Form generated from reading UI file 'DataMapperWid.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAMAPPERWID_H
#define UI_DATAMAPPERWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataMapperWid
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_0;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_2;
    QSlider *horizontalSlider;
    QFrame *line;
    QLineEdit *lineEdit_4;

    void setupUi(QWidget *DataMapperWid)
    {
        if (DataMapperWid->objectName().isEmpty())
            DataMapperWid->setObjectName(QStringLiteral("DataMapperWid"));
        DataMapperWid->resize(400, 506);
        gridLayout = new QGridLayout(DataMapperWid);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        lineEdit_0 = new QLineEdit(DataMapperWid);
        lineEdit_0->setObjectName(QStringLiteral("lineEdit_0"));

        gridLayout->addWidget(lineEdit_0, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        lineEdit_1 = new QLineEdit(DataMapperWid);
        lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));

        gridLayout->addWidget(lineEdit_1, 1, 1, 1, 1);

        lineEdit_2 = new QLineEdit(DataMapperWid);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 2, 1, 1, 1);

        horizontalSlider = new QSlider(DataMapperWid);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximum(4);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 3, 1, 1, 1);

        line = new QFrame(DataMapperWid);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 4, 0, 1, 3);

        lineEdit_4 = new QLineEdit(DataMapperWid);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 5, 1, 1, 1);


        retranslateUi(DataMapperWid);

        QMetaObject::connectSlotsByName(DataMapperWid);
    } // setupUi

    void retranslateUi(QWidget *DataMapperWid)
    {
        DataMapperWid->setWindowTitle(QApplication::translate("DataMapperWid", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class DataMapperWid: public Ui_DataMapperWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAMAPPERWID_H
