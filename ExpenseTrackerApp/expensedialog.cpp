//expensedialog.cpp

#include "expensedialog.h"
#include "ui_expensedialog.h"
#include "mainmenu.h"
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "mainmenu.h"
#include <QIntValidator>

ExpenseDialog::ExpenseDialog(const QString& username, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExpenseDialog),
    currentUsername(username)
{
    ui->setupUi(this);

    QString styleSheet = "ExpenseDialog { background-color: silver;}";
    this->setStyleSheet(styleSheet);

    setWindowTitle("Add Expense or Income");
    QDate date = QDate::currentDate();
    ui->dateEdit->setDate(date);

    QIntValidator* validator = new QIntValidator(this);
    ui->lineEdit_amount->setValidator(validator);

    QString arr[6] = {"Business","Fun","Food","Fuel","Education","Other"};
    QString arr2[3] = {"Cash","Credit Card","Cheque"};
    for(int i =0; i<6; i++){
    ui->comboBox_category->addItem(arr[i]);
    }
    for(int j =0;j<3;j++){
    ui->comboBox_mode->addItem(arr2[j]);
    }

    connect(static_cast<MainMenu*>(parent), &MainMenu::setIncomeRadioButton, this, &ExpenseDialog::setIncomeRadioButton);
    connect(static_cast<MainMenu*>(parent), &MainMenu::setExpenseRadioButton, this, &ExpenseDialog::setExpenseRadioButton);
    connect(ui->pushButton_ExpenseOK,&QPushButton::clicked,static_cast<MainMenu*>(parent),&MainMenu::mainFunc);
}

ExpenseDialog::~ExpenseDialog()
{
    delete ui;
}

void ExpenseDialog::setIncomeRadioButton() {
    ui->radioButton_income->setChecked(true);
}

void ExpenseDialog::setExpenseRadioButton() {
    ui->radioButton_expense->setChecked(true);
}

void ExpenseDialog::on_pushButton_ExpenseCancel_clicked()
{
    close();
    QWidget *parent = this->parentWidget();
    parent->show();
}


void ExpenseDialog::on_pushButton_ExpenseOK_clicked()
{
    QString ledgerFilePath = "ledger_" + currentUsername  + ".txt";
    QFile IncExpFile(ledgerFilePath);

    if(!IncExpFile.open(QFile::WriteOnly | QFile::Append)){
    QMessageBox::warning(this,"Title","Ledger File not open!");
    }
    QTextStream output(&IncExpFile);

    QString amount = ui->lineEdit_amount->text();

    if(amount.toDouble() < 0){
    QMessageBox::warning(this,"Title","Amount cannot be Negative!");
    IncExpFile.flush();
    IncExpFile.close();
    ExpenseDialog::close();
    }

    if(ui->radioButton_income->isChecked()){
    QString type = ui->radioButton_income->text();
    output << type << ",";

        if(amount!=""){

            output<<amount<<",";

        }
        if(ui->comboBox_category->currentText() != ""){
            QString category = ui->comboBox_category->currentText();

            output<<category<<",";
        }
        if(ui->comboBox_mode->currentText() != ""){
            QString mode = ui->comboBox_mode->currentText();

            output<<mode<<",";
        }

        output <<  ui->dateEdit->date().toString("dd-MM-yyyy") << "\n";
    }
    else if(ui->radioButton_expense->isChecked()){
    QString type = ui->radioButton_expense->text();
    output << type << ",";

        if(amount!=""){

            output<<amount<<",";

        }
        if(ui->comboBox_category->currentText() != ""){
            QString category = ui->comboBox_category->currentText();

            output<<category<<",";
        }
        if(ui->comboBox_mode->currentText() != ""){
            QString mode = ui->comboBox_mode->currentText();

            output<<mode<<",";
        }

        output <<  ui->dateEdit->date().toString("dd-MM-yyyy") << "\n";

    }


    if(IncExpFile.isOpen()){
        if(ui->radioButton_income->isChecked()){
            QMessageBox::information(this,"Title","Income Added!");
        }
        else{
            QMessageBox::information(this,"Title","Expense Added!");
        }
    }
    IncExpFile.flush();
    IncExpFile.close();


    ExpenseDialog::close();

}

