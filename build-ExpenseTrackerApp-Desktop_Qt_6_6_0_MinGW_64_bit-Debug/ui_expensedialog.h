/********************************************************************************
** Form generated from reading UI file 'expensedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPENSEDIALOG_H
#define UI_EXPENSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ExpenseDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QRadioButton *radioButton_income;
    QRadioButton *radioButton_expense;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_amount;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *comboBox_category;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QComboBox *comboBox_mode;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_ExpenseOK;
    QPushButton *pushButton_ExpenseCancel;

    void setupUi(QDialog *ExpenseDialog)
    {
        if (ExpenseDialog->objectName().isEmpty())
            ExpenseDialog->setObjectName("ExpenseDialog");
        ExpenseDialog->resize(646, 410);
        gridLayout = new QGridLayout(ExpenseDialog);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(ExpenseDialog);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        radioButton_income = new QRadioButton(ExpenseDialog);
        radioButton_income->setObjectName("radioButton_income");

        horizontalLayout_2->addWidget(radioButton_income);

        radioButton_expense = new QRadioButton(ExpenseDialog);
        radioButton_expense->setObjectName("radioButton_expense");

        horizontalLayout_2->addWidget(radioButton_expense);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(ExpenseDialog);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        lineEdit_amount = new QLineEdit(ExpenseDialog);
        lineEdit_amount->setObjectName("lineEdit_amount");

        horizontalLayout_3->addWidget(lineEdit_amount);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_5 = new QLabel(ExpenseDialog);
        label_5->setObjectName("label_5");

        horizontalLayout_6->addWidget(label_5);

        dateEdit = new QDateEdit(ExpenseDialog);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setTime(QTime(1, 0, 0));

        horizontalLayout_6->addWidget(dateEdit);


        gridLayout->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(ExpenseDialog);
        label_3->setObjectName("label_3");

        horizontalLayout_4->addWidget(label_3);

        comboBox_category = new QComboBox(ExpenseDialog);
        comboBox_category->setObjectName("comboBox_category");

        horizontalLayout_4->addWidget(comboBox_category);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(ExpenseDialog);
        label_4->setObjectName("label_4");

        horizontalLayout_5->addWidget(label_4);

        comboBox_mode = new QComboBox(ExpenseDialog);
        comboBox_mode->setObjectName("comboBox_mode");

        horizontalLayout_5->addWidget(comboBox_mode);


        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_ExpenseOK = new QPushButton(ExpenseDialog);
        pushButton_ExpenseOK->setObjectName("pushButton_ExpenseOK");

        horizontalLayout->addWidget(pushButton_ExpenseOK);

        pushButton_ExpenseCancel = new QPushButton(ExpenseDialog);
        pushButton_ExpenseCancel->setObjectName("pushButton_ExpenseCancel");

        horizontalLayout->addWidget(pushButton_ExpenseCancel);


        gridLayout->addLayout(horizontalLayout, 5, 1, 1, 1);


        retranslateUi(ExpenseDialog);

        QMetaObject::connectSlotsByName(ExpenseDialog);
    } // setupUi

    void retranslateUi(QDialog *ExpenseDialog)
    {
        ExpenseDialog->setWindowTitle(QCoreApplication::translate("ExpenseDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ExpenseDialog", "Type", nullptr));
        radioButton_income->setText(QCoreApplication::translate("ExpenseDialog", "Income", nullptr));
        radioButton_expense->setText(QCoreApplication::translate("ExpenseDialog", "Expense", nullptr));
        label_2->setText(QCoreApplication::translate("ExpenseDialog", "Amount", nullptr));
        lineEdit_amount->setPlaceholderText(QCoreApplication::translate("ExpenseDialog", "0.00", nullptr));
        label_5->setText(QCoreApplication::translate("ExpenseDialog", "Date", nullptr));
        label_3->setText(QCoreApplication::translate("ExpenseDialog", "Category", nullptr));
        label_4->setText(QCoreApplication::translate("ExpenseDialog", "Mode", nullptr));
        pushButton_ExpenseOK->setText(QCoreApplication::translate("ExpenseDialog", "OK", nullptr));
        pushButton_ExpenseCancel->setText(QCoreApplication::translate("ExpenseDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpenseDialog: public Ui_ExpenseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPENSEDIALOG_H
