#include "signupdialog.h"
#include "ui_signupdialog.h"
#include<QMessageBox>
#include<QTextStream>
#include<QFile>
SignupDialog::SignupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignupDialog)
{
    ui->setupUi(this);
    setWindowTitle("Create Your Account");
}

SignupDialog::~SignupDialog()
{
    delete ui;
}

void SignupDialog::on_pushButton_accCreate_clicked()
{




    QString username = ui->lineEdit_registerName->text();
    QString password = ui->lineEdit_registerPass->text();
    QString Cfmpassword = ui->lineEdit_CfmPass->text();

    if(username!="" && password==Cfmpassword){

        QFile accFile("accounts.txt");

        if(!accFile.open(QFile::WriteOnly | QFile::Append)){
            QMessageBox::warning(this,"Title","Account File not open!");
        }
        QTextStream output(&accFile);
        QString rusername = ui->lineEdit_registerName->text();
        QString rpass = ui->lineEdit_registerPass->text();

        output<< rusername << "," << rpass << "\n";
        accFile.flush();
        accFile.close();

        QMessageBox::information(this,"Title","Account Created!");
        SignupDialog::close();
    }
}


void SignupDialog::on_pushButton_cancelCreate_clicked()
{
    close();
}

