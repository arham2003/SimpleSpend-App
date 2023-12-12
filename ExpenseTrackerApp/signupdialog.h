#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>

namespace Ui {
class SignupDialog;
}

class SignupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignupDialog(QWidget *parent = nullptr);
    ~SignupDialog();

private slots:
    void on_pushButton_accCreate_clicked();

    void on_pushButton_cancelCreate_clicked();

private:
    Ui::SignupDialog *ui;
};

#endif // SIGNUPDIALOG_H
