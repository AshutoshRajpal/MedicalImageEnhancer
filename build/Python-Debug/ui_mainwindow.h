/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *pushButton_Reset;
    QLabel *label_2;
    QGraphicsView *graphicsView;
    QGridLayout *gridLayout_2;
    QCustomPlot *widget;
    QLabel *label_3;
    QScrollBar *horizontalScrollBar_Min;
    QLabel *label_4;
    QScrollBar *horizontalScrollBar_Max;
    QLabel *label_5;
    QScrollBar *horizontalScrollBar_Bri;
    QLabel *label_6;
    QScrollBar *horizontalScrollBar_Con;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        pushButton_Reset = new QPushButton(centralwidget);
        pushButton_Reset->setObjectName("pushButton_Reset");

        gridLayout->addWidget(pushButton_Reset, 1, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 2, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 0, 0, 1, 3);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName("widget");

        gridLayout_2->addWidget(widget, 0, 0, 1, 2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        horizontalScrollBar_Min = new QScrollBar(centralwidget);
        horizontalScrollBar_Min->setObjectName("horizontalScrollBar_Min");
        horizontalScrollBar_Min->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalScrollBar_Min, 1, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        horizontalScrollBar_Max = new QScrollBar(centralwidget);
        horizontalScrollBar_Max->setObjectName("horizontalScrollBar_Max");
        horizontalScrollBar_Max->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalScrollBar_Max, 2, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 3, 0, 1, 1);

        horizontalScrollBar_Bri = new QScrollBar(centralwidget);
        horizontalScrollBar_Bri->setObjectName("horizontalScrollBar_Bri");
        horizontalScrollBar_Bri->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalScrollBar_Bri, 3, 1, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 4, 0, 1, 1);

        horizontalScrollBar_Con = new QScrollBar(centralwidget);
        horizontalScrollBar_Con->setObjectName("horizontalScrollBar_Con");
        horizontalScrollBar_Con->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalScrollBar_Con, 4, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        pushButton_Reset->setText(QCoreApplication::translate("MainWindow", "Load Image", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Minimum", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Maximum", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Contrast", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
