/********************************************************************************
** Form generated from reading UI file 'signupdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPDIALOG_H
#define UI_SIGNUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignupDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_cancelCreate;
    QPushButton *pushButton_accCreate;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_CfmPass;
    QLineEdit *lineEdit_registerName;
    QLineEdit *lineEdit_registerPass;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;

    void setupUi(QDialog *SignupDialog)
    {
        if (SignupDialog->objectName().isEmpty())
            SignupDialog->setObjectName("SignupDialog");
        SignupDialog->resize(456, 343);
        gridLayoutWidget = new QWidget(SignupDialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(220, 230, 178, 56));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_cancelCreate = new QPushButton(gridLayoutWidget);
        pushButton_cancelCreate->setObjectName("pushButton_cancelCreate");

        gridLayout->addWidget(pushButton_cancelCreate, 0, 1, 1, 1);

        pushButton_accCreate = new QPushButton(gridLayoutWidget);
        pushButton_accCreate->setObjectName("pushButton_accCreate");

        gridLayout->addWidget(pushButton_accCreate, 0, 0, 1, 1);

        layoutWidget = new QWidget(SignupDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 30, 361, 181));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_CfmPass = new QLineEdit(layoutWidget);
        lineEdit_CfmPass->setObjectName("lineEdit_CfmPass");
        lineEdit_CfmPass->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(lineEdit_CfmPass, 2, 1, 1, 1);

        lineEdit_registerName = new QLineEdit(layoutWidget);
        lineEdit_registerName->setObjectName("lineEdit_registerName");

        gridLayout_2->addWidget(lineEdit_registerName, 0, 1, 1, 1);

        lineEdit_registerPass = new QLineEdit(layoutWidget);
        lineEdit_registerPass->setObjectName("lineEdit_registerPass");

        gridLayout_2->addWidget(lineEdit_registerPass, 1, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

#if QT_CONFIG(shortcut)
        label_2->setBuddy(lineEdit_registerPass);
        label_3->setBuddy(lineEdit_CfmPass);
        label->setBuddy(lineEdit_registerName);
#endif // QT_CONFIG(shortcut)

        retranslateUi(SignupDialog);

        QMetaObject::connectSlotsByName(SignupDialog);
    } // setupUi

    void retranslateUi(QDialog *SignupDialog)
    {
        SignupDialog->setWindowTitle(QCoreApplication::translate("SignupDialog", "Dialog", nullptr));
        pushButton_cancelCreate->setText(QCoreApplication::translate("SignupDialog", "Cancel", nullptr));
        pushButton_accCreate->setText(QCoreApplication::translate("SignupDialog", "Create Now", nullptr));
        label_2->setText(QCoreApplication::translate("SignupDialog", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("SignupDialog", "Confirm Password", nullptr));
        label->setText(QCoreApplication::translate("SignupDialog", "Username", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignupDialog: public Ui_SignupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPDIALOG_H
