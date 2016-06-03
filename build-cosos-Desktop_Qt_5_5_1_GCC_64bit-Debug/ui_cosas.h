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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cosas
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Cosas)
    {
        if (Cosas->objectName().isEmpty())
            Cosas->setObjectName(QStringLiteral("Cosas"));
        Cosas->resize(400, 300);
        menuBar = new QMenuBar(Cosas);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Cosas->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Cosas);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Cosas->addToolBar(mainToolBar);
        centralWidget = new QWidget(Cosas);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Cosas->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Cosas);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Cosas->setStatusBar(statusBar);

        retranslateUi(Cosas);

        QMetaObject::connectSlotsByName(Cosas);
    } // setupUi

    void retranslateUi(QMainWindow *Cosas)
    {
        Cosas->setWindowTitle(QApplication::translate("Cosas", "Cosas", 0));
    } // retranslateUi

};

namespace Ui {
    class Cosas: public Ui_Cosas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COSAS_H
