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

    QIcon icon(":/resources/images/action-hide-password.png");
    ui->pushButton_togglePass->setIcon(icon);
    ui->pushButton_toggleCfmPass->setIcon(icon);

    createToggleButton(ui->lineEdit_registerPass, ui->pushButton_togglePass);
    createToggleButton(ui->lineEdit_CfmPass, ui->pushButton_toggleCfmPass);
}

SignupDialog::~SignupDialog()
{
    delete ui;
}

void SignupDialog::createToggleButton(QLineEdit *lineEdit, QPushButton *toggleButton)
{
    // Set echo mode to password initially
    lineEdit->setEchoMode(QLineEdit::Password);

    // Connect the toggle button's clicked signal to the slot for toggling visibility
    connect(toggleButton, &QPushButton::clicked, [lineEdit]() {
        // Toggle the echo mode between Normal and Password
        lineEdit->setEchoMode(lineEdit->echoMode() == QLineEdit::Normal ? QLineEdit::Password : QLineEdit::Normal);
    });
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

