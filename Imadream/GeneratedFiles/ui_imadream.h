/********************************************************************************
** Form generated from reading UI file 'imadream.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMADREAM_H
#define UI_IMADREAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "ximage.h"

QT_BEGIN_NAMESPACE

class Ui_ImadreamClass
{
public:
    QAction *action_open;
    QAction *action_save;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *pushButton_pen;
    QPushButton *pushButton_eraser;
    QPushButton *pushButton_palette;
    QSlider *Slider_pensize;
    QScrollArea *scrollArea_image;
    Ximage *imageWindow;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImadreamClass)
    {
        if (ImadreamClass->objectName().isEmpty())
            ImadreamClass->setObjectName(QStringLiteral("ImadreamClass"));
        ImadreamClass->resize(1307, 743);
        action_open = new QAction(ImadreamClass);
        action_open->setObjectName(QStringLiteral("action_open"));
        action_save = new QAction(ImadreamClass);
        action_save->setObjectName(QStringLiteral("action_save"));
        centralWidget = new QWidget(ImadreamClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 120, 241));
        pushButton_pen = new QPushButton(groupBox);
        pushButton_pen->setObjectName(QStringLiteral("pushButton_pen"));
        pushButton_pen->setGeometry(QRect(20, 40, 75, 23));
        pushButton_pen->setCheckable(true);
        pushButton_pen->setChecked(true);
        pushButton_eraser = new QPushButton(groupBox);
        pushButton_eraser->setObjectName(QStringLiteral("pushButton_eraser"));
        pushButton_eraser->setGeometry(QRect(20, 80, 75, 23));
        pushButton_eraser->setCheckable(true);
        pushButton_palette = new QPushButton(groupBox);
        pushButton_palette->setObjectName(QStringLiteral("pushButton_palette"));
        pushButton_palette->setGeometry(QRect(20, 120, 31, 23));
        pushButton_palette->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        Slider_pensize = new QSlider(groupBox);
        Slider_pensize->setObjectName(QStringLiteral("Slider_pensize"));
        Slider_pensize->setGeometry(QRect(10, 180, 91, 22));
        Slider_pensize->setOrientation(Qt::Horizontal);
        scrollArea_image = new QScrollArea(centralWidget);
        scrollArea_image->setObjectName(QStringLiteral("scrollArea_image"));
        scrollArea_image->setGeometry(QRect(170, 30, 1101, 661));
        scrollArea_image->setWidgetResizable(false);
        imageWindow = new Ximage();
        imageWindow->setObjectName(QStringLiteral("imageWindow"));
        imageWindow->setGeometry(QRect(0, 0, 1099, 659));
        scrollArea_image->setWidget(imageWindow);
        ImadreamClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImadreamClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1307, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        ImadreamClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(ImadreamClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ImadreamClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_open);
        menu->addAction(action_save);

        retranslateUi(ImadreamClass);
        QObject::connect(pushButton_palette, SIGNAL(clicked()), ImadreamClass, SLOT(setColor()));
        QObject::connect(pushButton_pen, SIGNAL(clicked()), ImadreamClass, SLOT(setPen()));
        QObject::connect(pushButton_eraser, SIGNAL(clicked()), ImadreamClass, SLOT(setEraser()));
        QObject::connect(Slider_pensize, SIGNAL(valueChanged(int)), ImadreamClass, SLOT(setBrushSize()));

        QMetaObject::connectSlotsByName(ImadreamClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImadreamClass)
    {
        ImadreamClass->setWindowTitle(QApplication::translate("ImadreamClass", "Imadream", nullptr));
        action_open->setText(QApplication::translate("ImadreamClass", "\346\211\223\345\274\200", nullptr));
#ifndef QT_NO_SHORTCUT
        action_open->setShortcut(QApplication::translate("ImadreamClass", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        action_save->setText(QApplication::translate("ImadreamClass", "\344\277\235\345\255\230", nullptr));
#ifndef QT_NO_SHORTCUT
        action_save->setShortcut(QApplication::translate("ImadreamClass", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        groupBox->setTitle(QApplication::translate("ImadreamClass", "\345\267\245\345\205\267\346\240\217", nullptr));
        pushButton_pen->setText(QApplication::translate("ImadreamClass", "\347\224\273\347\254\224", nullptr));
        pushButton_eraser->setText(QApplication::translate("ImadreamClass", "\346\251\241\347\232\256", nullptr));
        pushButton_palette->setText(QApplication::translate("ImadreamClass", "color", nullptr));
        menu->setTitle(QApplication::translate("ImadreamClass", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImadreamClass: public Ui_ImadreamClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMADREAM_H
