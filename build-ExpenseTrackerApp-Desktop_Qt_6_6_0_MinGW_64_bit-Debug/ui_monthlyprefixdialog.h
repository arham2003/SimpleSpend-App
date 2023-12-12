/********************************************************************************
** Form generated from reading UI file 'monthlyprefixdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTHLYPREFIXDIALOG_H
#define UI_MONTHLYPREFIXDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MonthlyPrefixDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_monthly_prefix;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *MonthlyPrefixDialog)
    {
        if (MonthlyPrefixDialog->objectName().isEmpty())
            MonthlyPrefixDialog->setObjectName("MonthlyPrefixDialog");
        MonthlyPrefixDialog->resize(344, 231);
        gridLayout = new QGridLayout(MonthlyPrefixDialog);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(MonthlyPrefixDialog);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        horizontalLayout_2->addWidget(label);

        lineEdit_monthly_prefix = new QLineEdit(MonthlyPrefixDialog);
        lineEdit_monthly_prefix->setObjectName("lineEdit_monthly_prefix");

        horizontalLayout_2->addWidget(lineEdit_monthly_prefix);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_ok = new QPushButton(MonthlyPrefixDialog);
        pushButton_ok->setObjectName("pushButton_ok");

        horizontalLayout->addWidget(pushButton_ok);

        pushButton_cancel = new QPushButton(MonthlyPrefixDialog);
        pushButton_cancel->setObjectName("pushButton_cancel");

        horizontalLayout->addWidget(pushButton_cancel);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(MonthlyPrefixDialog);

        QMetaObject::connectSlotsByName(MonthlyPrefixDialog);
    } // setupUi

    void retranslateUi(QDialog *MonthlyPrefixDialog)
    {
        MonthlyPrefixDialog->setWindowTitle(QCoreApplication::translate("MonthlyPrefixDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MonthlyPrefixDialog", "Enter the monthly Expense:", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("MonthlyPrefixDialog", "OK", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("MonthlyPrefixDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MonthlyPrefixDialog: public Ui_MonthlyPrefixDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTHLYPREFIXDIALOG_H
