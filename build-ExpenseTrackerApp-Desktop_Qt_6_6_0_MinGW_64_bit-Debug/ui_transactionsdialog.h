/********************************************************************************
** Form generated from reading UI file 'transactionsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSACTIONSDIALOG_H
#define UI_TRANSACTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_TransactionsDialog
{
public:

    void setupUi(QDialog *TransactionsDialog)
    {
        if (TransactionsDialog->objectName().isEmpty())
            TransactionsDialog->setObjectName("TransactionsDialog");
        TransactionsDialog->resize(680, 427);

        retranslateUi(TransactionsDialog);

        QMetaObject::connectSlotsByName(TransactionsDialog);
    } // setupUi

    void retranslateUi(QDialog *TransactionsDialog)
    {
        TransactionsDialog->setWindowTitle(QCoreApplication::translate("TransactionsDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransactionsDialog: public Ui_TransactionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSACTIONSDIALOG_H
