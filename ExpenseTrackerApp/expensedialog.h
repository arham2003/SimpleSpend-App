#ifndef EXPENSEDIALOG_H
#define EXPENSEDIALOG_H

#include <QDialog>

namespace Ui {
class ExpenseDialog;
}

class ExpenseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExpenseDialog(const QString& username,QWidget *parent = nullptr);
    ~ExpenseDialog();

private slots:
    void on_pushButton_ExpenseCancel_clicked();

    void on_pushButton_ExpenseOK_clicked();

public slots:
    void setIncomeRadioButton();
    void setExpenseRadioButton();

private:
    Ui::ExpenseDialog *ui;

private:
    QString currentUsername;
};

#endif // EXPENSEDIALOG_H
