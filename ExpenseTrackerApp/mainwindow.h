#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "signupdialog.h"
#include "mainmenu.h"
#include "expensedialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_accCreate_clicked();

private:
    Ui::MainWindow *ui;
    SignupDialog *signupDialog;
    MainMenu *mainMenu;
    ExpenseDialog *expenseDialog;

private:
    QString currentUsername;

public:
    QString getCurrentUsername() const { return currentUsername; }
};
#endif // MAINWINDOW_H
