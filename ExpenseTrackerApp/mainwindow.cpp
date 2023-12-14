//mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString styleSheet = "QMainWindow { background-image: url(:/resources/images/enlarge_krasivo-20.png);}";
    this->setStyleSheet(styleSheet);

    QPixmap pix(":/resources/images/accLogin (2).png");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    ui->label_pic->setAlignment(Qt::AlignCenter);

    QString lineEditStyle = "QLineEdit { border: 2px solid black; border-radius: 5px; padding: 2px; font-weight: bold; }";
    ui->lineEdit_username->setStyleSheet(lineEditStyle);
    ui->lineEdit_password->setStyleSheet(lineEditStyle);

    QString groupBoxStyle = "QGroupBox { border: 2px solid black; border-radius: 5px; font-weight: bold; }";
    ui->groupBox->setStyleSheet(groupBoxStyle);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Login_clicked()
{

    QString username = ui->lineEdit_username->text();
    currentUsername = username;
    QString password = ui->lineEdit_password->text();

    QFile accFile("accounts.txt");

    if(!accFile.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Title","File Not Open!");
    }
    QTextStream input(&accFile);
    QStringList lines;


    while(!input.atEnd()) {
        QString UNandPass = input.readLine();
        lines.append(UNandPass.split(","));
    }

    bool accFound = 0;
    for (int i =0 ; i< lines.size();i++){
        if(username == lines[i] && password==lines[++i]){
            ui->statusbar->showMessage("Checking Credentials...",3000);
            QMessageBox::information(this,"Login","Username and password is correct.");
            this->hide();
            mainMenu = new MainMenu(this);
            mainMenu->show();
            accFound = 1;

        }else{
            ui->statusbar->showMessage("Checking Credentials...",3000);

        }
    }

    if (!accFound) {
        QMessageBox::warning(this, "Login", "Incorrect username and Password!");
    }

}


void MainWindow::on_pushButton_accCreate_clicked()
{
    signupDialog = new SignupDialog(this);
    signupDialog->show();
}

