/********************************************************************************
** Form generated from reading UI file 'cosas.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COSAS_H
#define UI_COSAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cosas
{
public:
    QWidget *centralWidget;
    QPushButton *boton;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Cosas)
    {
        if (Cosas->objectName().isEmpty())
            Cosas->setObjectName(QStringLiteral("Cosas"));
        Cosas->resize(580, 386);
        centralWidget = new QWidget(Cosas);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        boton = new QPushButton(centralWidget);
        boton->setObjectName(QStringLiteral("boton"));
        boton->setGeometry(QRect(230, 240, 85, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 90, 221, 31));
        Cosas->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Cosas);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 580, 27));
        Cosas->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Cosas);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Cosas->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Cosas);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Cosas->setStatusBar(statusBar);

        retranslateUi(Cosas);

        QMetaObject::connectSlotsByName(Cosas);
    } // setupUi

    void retranslateUi(QMainWindow *Cosas)
    {
        Cosas->setWindowTitle(QApplication::translate("Cosas", "Cosas", 0));
        boton->setText(QApplication::translate("Cosas", "Ok", 0));
        label->setText(QApplication::translate("Cosas", "Ahora no hay nada!!", 0));
    } // retranslateUi

};

namespace Ui {
    class Cosas: public Ui_Cosas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COSAS_H
