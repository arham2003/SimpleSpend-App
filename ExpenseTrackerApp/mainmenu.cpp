//mainmenu.cpp
#include <QtCharts/QBarSeries>

#include "mainmenu.h"
#include "mainwindow.h"
#include "reportsdialog.h"
#include "ui_mainmenu.h"
#include <QPixmap>
#include<QMessageBox>
#include <QFile>
#include <QTextStream>
#include <utility>
#include <QFileInfo>
#include <QCalendarWidget>  // Include QCalendarWidget
#include <QVBoxLayout>
#include <QDialog>
#include <QDate>
#include "transactionsdialog.h"
#include <QPropertyAnimation>
using namespace std;

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    Qt::WindowFlags flags = windowFlags();
    setWindowFlags(flags | Qt::WindowMaximizeButtonHint);

    ui->setupUi(this);
    QFont boldFont = font();
    boldFont.setPointSize(10);
    setFont(boldFont);

    QString styleSheet = "MainMenu { background-image: url(:/resources/images/finance black.png);}"
                         "QMenuBar { background-color: silver;}";
    this->setStyleSheet(styleSheet);

    ui->label_income->setAlignment(Qt::AlignCenter);
    ui->label_expense->setAlignment(Qt::AlignCenter);
    ui->label_Reports->setAlignment(Qt::AlignCenter);
    ui->label_Transactions->setAlignment(Qt::AlignCenter);
    setWindowTitle("Main Menu");
    loadPixmap(":/resources/images/income.png", ui->label_income);
    loadPixmap(":/resources/images/Expense.png", ui->label_expense);
    loadPixmap(":/resources/images/report-icon.png", ui->label_Reports);
    loadPixmap(":/resources/images/transactions.png", ui->label_Transactions);


    currentUser = static_cast<MainWindow*>(parentWidget())->getCurrentUsername();
    mainFunc();

}

MainMenu::~MainMenu()
{
    delete ui;
}



void MainMenu::loadPixmap(const QString &imagePath, QLabel *label)
{
    QPixmap pix(imagePath);


    int w = label->width();
    int h = label->height();
    label->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
     label->setAlignment(Qt::AlignCenter);
}

void MainMenu::on_pushButton_addExpense_clicked()
{

    expenseDialog = new ExpenseDialog(currentUser,this);
    emit setExpenseRadioButton();
    expenseDialog->show();
}

void MainMenu::mainFunc(){

    double balance = 0;
    double IncomeSum = 0;
    double ExpenseSum = 0;
    double balance1 = 0;

    QString ledgerFilePath = "ledger_" + currentUser + ".txt";
    QFile IncExpFile(ledgerFilePath);

    if (!IncExpFile.exists()) {
        IncExpFile.open(QFile::WriteOnly | QFile::Text);
        IncExpFile.close();
    }

        if(!IncExpFile.open(QFile::ReadOnly | QFile::Text)){
            QMessageBox::warning(this,"Title","Ledger File not open!");
        }else{

            QTextStream input(&IncExpFile);
            QStringList lines;


            while(!input.atEnd()) {
                QString IncExpense = input.readLine();
                lines.append(IncExpense.split(","));
            }



        for (int i =0 ; i+4< lines.size();i=i+5){
            QString type = lines[i];
            QString amount = lines[i+1];
            QString category = lines[i+2];
            QString mode = lines[i+3];
            QString date = lines[i + 4];

            if(amount.toDouble()<0){
                break;
            }

            if(type == "Income"){
                IncomeSum = IncomeSum + amount.toDouble();
            }
            else if(type == "Expense"){
                ExpenseSum = ExpenseSum + amount.toDouble();
                ExpenseSum = ExpenseSum + monthlyPrefixAmount;

            }

            balance1 = IncomeSum - ExpenseSum;
            balance = balance1;

           }
        IncExpFile.close();
       }



    ui->textEdit_balance->setEnabled(false);
    ui->textEdit_expense->setEnabled(false);
     ui->textEdit_income->setEnabled(false);


    if(ui->actionPKR->isChecked()){
    ui->textEdit_balance->setText("Rs. "+QString::number(balance));
    ui->textEdit_expense->setText("Rs. "+QString::number(ExpenseSum));
    ui->textEdit_income->setText("Rs. "+QString::number(IncomeSum));

    }else if(ui->actionEuro->isChecked()){
    ui->textEdit_balance->setText("€ "+QString::number(balance));
    ui->textEdit_expense->setText("€ "+QString::number(ExpenseSum));
    ui->textEdit_income->setText("€ "+QString::number(IncomeSum));
    }else if(ui->actionUSD->isChecked()){
    ui->textEdit_balance->setText("$ "+QString::number(balance));
    ui->textEdit_expense->setText("$ "+QString::number(ExpenseSum));
    ui->textEdit_income->setText("$ "+QString::number(IncomeSum));
    }
}

void MainMenu::on_pushButton_addIncome_clicked()
{

    expenseDialog = new ExpenseDialog(currentUser, this);
    emit setIncomeRadioButton();
    expenseDialog->show();


}


void MainMenu::on_actionLogout_triggered()
{
    MainMenu::close();
    QWidget *parent = this->parentWidget();
    parent->setWindowOpacity(0.0);
    parent->show();
    QPropertyAnimation* animation = new QPropertyAnimation(parent, "windowOpacity");

    // Set the duration of the animation in milliseconds
    animation->setDuration(500);  // Adjust the duration as needed

    // Set the target opacity (in this case, fully opaque)
    animation->setEndValue(1.0);

    // Start the animation
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}


void MainMenu::on_actionPKR_triggered()
{
    ui->actionPKR->setChecked(true);
    ui->actionEuro->setChecked(false);
    ui->actionUSD->setChecked(false);
    mainFunc();
}


void MainMenu::on_actionExit_triggered()
{
    QApplication::quit();
}


void MainMenu::on_actionUSD_triggered()
{
    ui->actionPKR->setChecked(false);
    ui->actionEuro->setChecked(false);
    ui->actionUSD->setChecked(true);
    mainFunc();
}


void MainMenu::on_actionEuro_triggered()
{
    ui->actionPKR->setChecked(false);
    ui->actionEuro->setChecked(true);
    ui->actionUSD->setChecked(false);
    mainFunc();
}


void MainMenu::on_actionDelete_All_Records_triggered()
{
    CurrentUN = static_cast<MainWindow*>(parentWidget())->getCurrentUsername();

    QString ledgerFilePath = "ledger_" + currentUser + ".txt";
    QFile file(ledgerFilePath);
    if (!file.exists()) {
    QMessageBox::warning(this, "Title", "No Records Found!");
    return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "My Title","Are You Sure?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        if (file.remove()) {
                    QMessageBox::information(this, "Title", "Records Deleted!");
                    mainFunc();  // Update UI after deleting records
        } else {
                    QMessageBox::warning(this, "Title", "Unable to delete records!");
        }
    }
}


void MainMenu::on_pushButton_monthlyPrefix_clicked()
{
    QString PrefixFilePath = "monthlyPrefix_" + currentUser + ".txt";
    QFile file(PrefixFilePath);
    if(file.exists()){
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Title","Prefix File not open!");
    }
    QTextStream input(&file);

    double amount1 = input.readLine().toDouble();

    monthlyPrefixAmount = amount1;

    file.close();
    ui->pushButton_monthlyPrefix->setEnabled(false);
    mainFunc();
    }
    else if(!file.exists()  || file.size() == 0){
        QMessageBox::information(this,"Title","No Prefix Set!");
    }

}


void MainMenu::on_actionSet_Monthly_Prefix_triggered()
{
    monthlyPrefix = new MonthlyPrefixDialog(currentUser, this);
    monthlyPrefix->show();

}


void MainMenu::on_actionCalender_triggered()
{
    // Create a QDialog to host the QCalendarWidget
    QDialog* calendarDialog = new QDialog(this);
    calendarDialog->setWindowTitle("Calendar");

    QCalendarWidget* calendarWidget = new QCalendarWidget(calendarDialog);


    QVBoxLayout* layout = new QVBoxLayout(calendarDialog);
    layout->addWidget(calendarWidget);


    calendarWidget->setSelectedDate(QDate::currentDate());
    calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    // Show the dialog
    calendarDialog->exec();
    delete calendarDialog;
}


void MainMenu::on_pushButton_Transactions_clicked()
{
    TransactionsDialog *transactionsDialog = new TransactionsDialog(currentUser,this);
    transactionsDialog->exec();
}


void MainMenu::on_pushButton_Reports_clicked()
{
    ReportsDialog *reportsDialog = new ReportsDialog(currentUser, this);
    reportsDialog->exec();
}




