#include "monthlyprefixdialog.h"
#include "ui_monthlyprefixdialog.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QIntValidator>

using namespace std;
MonthlyPrefixDialog::MonthlyPrefixDialog(const QString& username,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MonthlyPrefixDialog),
    currentUsername(username)
{
    ui->setupUi(this);

    QIntValidator* validator = new QIntValidator(this);
    ui->lineEdit_monthly_prefix->setValidator(validator);
}

MonthlyPrefixDialog::~MonthlyPrefixDialog()
{
    delete ui;
}



void MonthlyPrefixDialog::on_pushButton_ok_clicked()
{
    QString amount = ui->lineEdit_monthly_prefix->text();
    QString PrefixFilePath = "monthlyPrefix_" + currentUsername + ".txt";
    QFile file(PrefixFilePath);

    if (!file.exists() || file.size() == 0) {
    if(!file.open(QFile::WriteOnly | QFile::Append)){
        QMessageBox::warning(this,"Title","Ledger File not open!");
    }
    QTextStream output(&file);



    if(amount.toDouble() < 0){
        QMessageBox::warning(this,"Title","Amount cannot be Negative!");
        file.flush();
        file.close();
        MonthlyPrefixDialog::close();
    }

    if(amount!=""){

        output<<amount.toDouble() << "\n";

    }

    MonthlyPrefixDialog::close();

    }else{
    QMessageBox::warning(this,"Title","Amount already set!");

    QMessageBox::StandardButton reply = QMessageBox::question(this, "My Title","Do You want to delete previous values?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        if (file.remove()) {
            QMessageBox::information(this, "Title", "Prefix Deleted!");

        } else {
            QMessageBox::warning(this, "Title", "Unable to delete Prefix!");
        }
    }
    }
    file.flush();
    file.close();



}


void MonthlyPrefixDialog::on_pushButton_cancel_clicked()
{
    MonthlyPrefixDialog::close();
}

