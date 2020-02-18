/********************************************************************************
** Form generated from reading UI file 'bmpfiles.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BMPFILES_H
#define UI_BMPFILES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BMPFiles
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *BMPFiles)
    {
        if (BMPFiles->objectName().isEmpty())
            BMPFiles->setObjectName(QString::fromUtf8("BMPFiles"));
        BMPFiles->resize(800, 800);
        BMPFiles->setMinimumSize(QSize(500, 500));
        BMPFiles->setMaximumSize(QSize(900, 900));
        centralWidget = new QWidget(BMPFiles);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(200, 200));
        graphicsView->setMaximumSize(QSize(800, 800));

        horizontalLayout->addWidget(graphicsView);

        BMPFiles->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(BMPFiles);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        BMPFiles->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(BMPFiles);

        QMetaObject::connectSlotsByName(BMPFiles);
    } // setupUi

    void retranslateUi(QMainWindow *BMPFiles)
    {
        BMPFiles->setWindowTitle(QApplication::translate("BMPFiles", "BMPFiles", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BMPFiles: public Ui_BMPFiles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BMPFILES_H
