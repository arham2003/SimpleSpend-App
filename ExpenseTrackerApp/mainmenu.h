#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "expensedialog.h"
#include "monthlyprefixdialog.h"
#include "qlabel.h"
#include "transactionsdialog.h"

#include <QStackedWidget>
#include <QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();
    void mainFunc();
public:
    QString CurrentUN;
    // Add a getter for the current username
    QString getCurrentUsername() const { return CurrentUN; }
    double monthlyPrefixAmount=0;



private slots:
    void on_pushButton_addExpense_clicked();

    void on_pushButton_addIncome_clicked();

    void on_actionLogout_triggered();

    void on_actionPKR_triggered();

    void on_actionExit_triggered();

    void on_actionUSD_triggered();

    void on_actionEuro_triggered();

    void on_actionDelete_All_Records_triggered();

    void on_pushButton_monthlyPrefix_clicked();

    void on_actionSet_Monthly_Prefix_triggered();


    void on_actionCalender_triggered();

    void on_pushButton_Transactions_clicked();

    void on_pushButton_Reports_clicked();

private:
    Ui::MainMenu *ui;
    ExpenseDialog *expenseDialog;
    TransactionsDialog *transactionDialog;
    MonthlyPrefixDialog *monthlyPrefix;
    QString currentUser;
    QStringList monthNames;

    void loadPixmap(const QString &imagePath, QLabel *label);

signals:
    void setIncomeRadioButton();
    void setExpenseRadioButton();



};

#endif // MAINMENU_H
