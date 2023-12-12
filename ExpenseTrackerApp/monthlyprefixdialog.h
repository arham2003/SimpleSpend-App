#ifndef MONTHLYPREFIXDIALOG_H
#define MONTHLYPREFIXDIALOG_H

#include <QDialog>

namespace Ui {
class MonthlyPrefixDialog;
}

class MonthlyPrefixDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MonthlyPrefixDialog(const QString& username,QWidget *parent = nullptr);
    ~MonthlyPrefixDialog();

private slots:

    void on_pushButton_ok_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::MonthlyPrefixDialog *ui;
    QString currentUsername;


};

#endif // MONTHLYPREFIXDIALOG_H
