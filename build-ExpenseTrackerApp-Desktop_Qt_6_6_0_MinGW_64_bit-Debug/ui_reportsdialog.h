/********************************************************************************
** Form generated from reading UI file 'reportsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTSDIALOG_H
#define UI_REPORTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ReportsDialog
{
public:

    void setupUi(QDialog *ReportsDialog)
    {
        if (ReportsDialog->objectName().isEmpty())
            ReportsDialog->setObjectName("ReportsDialog");
        ReportsDialog->resize(851, 438);

        retranslateUi(ReportsDialog);

        QMetaObject::connectSlotsByName(ReportsDialog);
    } // setupUi

    void retranslateUi(QDialog *ReportsDialog)
    {
        ReportsDialog->setWindowTitle(QCoreApplication::translate("ReportsDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReportsDialog: public Ui_ReportsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTSDIALOG_H
