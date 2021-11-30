/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *labelImage;
    QLabel *label;
    QLineEdit *lineEditNom;
    QLabel *label_2;
    QLineEdit *lineEditAnneeNaissance;
    QLabel *label_3;
    QLineEdit *lineEditEmail;
    QLabel *label_4;
    QLineEdit *lineEditPhoto;
    QPushButton *pushButtonPrecedent;
    QPushButton *pushButtonSuivant;
    QPushButton *pushButtonModifier;
    QPushButton *pushButtonQuitter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(654, 426);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(360, 20, 271, 331));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        labelImage = new QLabel(frame);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));
        labelImage->setGeometry(QRect(13, 6, 251, 311));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 64, 17));
        lineEditNom = new QLineEdit(centralwidget);
        lineEditNom->setObjectName(QString::fromUtf8("lineEditNom"));
        lineEditNom->setGeometry(QRect(20, 40, 301, 25));
        // lineEditNom->setReadOnly(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 90, 161, 17));
        lineEditAnneeNaissance = new QLineEdit(centralwidget);
        lineEditAnneeNaissance->setObjectName(QString::fromUtf8("lineEditAnneeNaissance"));
        lineEditAnneeNaissance->setGeometry(QRect(20, 110, 301, 25));
        // lineEditAnneeNaissance->setReadOnly(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 160, 64, 17));
        lineEditEmail = new QLineEdit(centralwidget);
        lineEditEmail->setObjectName(QString::fromUtf8("lineEditEmail"));
        lineEditEmail->setGeometry(QRect(20, 180, 301, 25));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 230, 64, 17));
        lineEditPhoto = new QLineEdit(centralwidget);
        lineEditPhoto->setObjectName(QString::fromUtf8("lineEditPhoto"));
        lineEditPhoto->setGeometry(QRect(20, 250, 301, 25));
        pushButtonPrecedent = new QPushButton(centralwidget);
        pushButtonPrecedent->setObjectName(QString::fromUtf8("pushButtonPrecedent"));
        pushButtonPrecedent->setGeometry(QRect(20, 320, 83, 25));
        pushButtonSuivant = new QPushButton(centralwidget);
        pushButtonSuivant->setObjectName(QString::fromUtf8("pushButtonSuivant"));
        pushButtonSuivant->setGeometry(QRect(120, 320, 83, 25));
        pushButtonModifier = new QPushButton(centralwidget);
        pushButtonModifier->setObjectName(QString::fromUtf8("pushButtonModifier"));
        pushButtonModifier->setGeometry(QRect(240, 320, 83, 25));
        pushButtonQuitter = new QPushButton(centralwidget);
        pushButtonQuitter->setObjectName(QString::fromUtf8("pushButtonQuitter"));
        pushButtonQuitter->setGeometry(QRect(20, 370, 611, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 654, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "UNIX_Exercice2", nullptr));
        labelImage->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Nom :", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Ann\303\251e de naissance :", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Email :", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Photo :", nullptr));
        pushButtonPrecedent->setText(QApplication::translate("MainWindow", "<<<", nullptr));
        pushButtonSuivant->setText(QApplication::translate("MainWindow", ">>>", nullptr));
        pushButtonModifier->setText(QApplication::translate("MainWindow", "Modifier", nullptr));
        pushButtonQuitter->setText(QApplication::translate("MainWindow", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
