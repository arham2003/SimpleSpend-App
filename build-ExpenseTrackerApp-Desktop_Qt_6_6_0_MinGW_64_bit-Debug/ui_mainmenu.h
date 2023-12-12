/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QAction *actionLogout;
    QAction *actionPKR;
    QAction *actionUSD;
    QAction *actionEuro;
    QAction *actionExit;
    QAction *actionDelete_All_Records;
    QAction *actionSet_Monthly_Prefix;
    QAction *actionCalender;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit_balance;
    QTextEdit *textEdit_expense;
    QLabel *label_7;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QTextEdit *textEdit_income;
    QPushButton *pushButton_monthlyPrefix;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_income;
    QPushButton *pushButton_addIncome;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_expense;
    QPushButton *pushButton_addExpense;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_Transactions;
    QPushButton *pushButton_Transactions;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_Reports;
    QPushButton *pushButton_Reports;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QMenu *menuCurrency;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName("MainMenu");
        MainMenu->resize(754, 533);
        actionLogout = new QAction(MainMenu);
        actionLogout->setObjectName("actionLogout");
        actionPKR = new QAction(MainMenu);
        actionPKR->setObjectName("actionPKR");
        actionPKR->setCheckable(true);
        actionPKR->setChecked(true);
        actionUSD = new QAction(MainMenu);
        actionUSD->setObjectName("actionUSD");
        actionUSD->setCheckable(true);
        actionEuro = new QAction(MainMenu);
        actionEuro->setObjectName("actionEuro");
        actionEuro->setCheckable(true);
        actionExit = new QAction(MainMenu);
        actionExit->setObjectName("actionExit");
        actionDelete_All_Records = new QAction(MainMenu);
        actionDelete_All_Records->setObjectName("actionDelete_All_Records");
        actionSet_Monthly_Prefix = new QAction(MainMenu);
        actionSet_Monthly_Prefix->setObjectName("actionSet_Monthly_Prefix");
        actionCalender = new QAction(MainMenu);
        actionCalender->setObjectName("actionCalender");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/images/Flat-Calendar.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCalender->setIcon(icon);
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 20, 451, 101));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textEdit_balance = new QTextEdit(layoutWidget);
        textEdit_balance->setObjectName("textEdit_balance");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit_balance->sizePolicy().hasHeightForWidth());
        textEdit_balance->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(12);
        font.setBold(true);
        textEdit_balance->setFont(font);
        textEdit_balance->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        textEdit_balance->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"background-color:rgb(212, 229, 255);\n"
"color:black;"));

        gridLayout->addWidget(textEdit_balance, 1, 2, 1, 1);

        textEdit_expense = new QTextEdit(layoutWidget);
        textEdit_expense->setObjectName("textEdit_expense");
        sizePolicy.setHeightForWidth(textEdit_expense->sizePolicy().hasHeightForWidth());
        textEdit_expense->setSizePolicy(sizePolicy);
        textEdit_expense->setFont(font);
        textEdit_expense->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        textEdit_expense->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"background-color:rgb(212, 229, 255);\n"
"color:black;"));

        gridLayout->addWidget(textEdit_expense, 2, 2, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font1.setPointSize(10);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font2.setPointSize(10);
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        textEdit_income = new QTextEdit(layoutWidget);
        textEdit_income->setObjectName("textEdit_income");
        sizePolicy.setHeightForWidth(textEdit_income->sizePolicy().hasHeightForWidth());
        textEdit_income->setSizePolicy(sizePolicy);
        textEdit_income->setFont(font);
        textEdit_income->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        textEdit_income->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"background-color:rgb(212, 229, 255);\n"
"color:black;"));

        gridLayout->addWidget(textEdit_income, 0, 2, 1, 1);

        pushButton_monthlyPrefix = new QPushButton(centralwidget);
        pushButton_monthlyPrefix->setObjectName("pushButton_monthlyPrefix");
        pushButton_monthlyPrefix->setGeometry(QRect(540, 50, 131, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font3.setPointSize(10);
        font3.setUnderline(true);
        pushButton_monthlyPrefix->setFont(font3);
        pushButton_monthlyPrefix->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_monthlyPrefix->setFlat(true);
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(30, 170, 311, 261));
        verticalLayout_5 = new QVBoxLayout(layoutWidget1);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_income = new QLabel(layoutWidget1);
        label_income->setObjectName("label_income");
        QFont font4;
        font4.setPointSize(12);
        label_income->setFont(font4);
        label_income->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_income);

        pushButton_addIncome = new QPushButton(layoutWidget1);
        pushButton_addIncome->setObjectName("pushButton_addIncome");
        pushButton_addIncome->setStyleSheet(QString::fromUtf8("color:white;\n"
"font:bold;\n"
"font-size:14px;\n"
"background-color:rgb(102, 135, 255);"));

        verticalLayout->addWidget(pushButton_addIncome);


        verticalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_expense = new QLabel(layoutWidget1);
        label_expense->setObjectName("label_expense");
        label_expense->setFont(font4);
        label_expense->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_expense);

        pushButton_addExpense = new QPushButton(layoutWidget1);
        pushButton_addExpense->setObjectName("pushButton_addExpense");
        pushButton_addExpense->setStyleSheet(QString::fromUtf8("color:white;\n"
"font:bold;\n"
"font-size:14px;\n"
"background-color:rgb(102, 135, 255);"));

        verticalLayout_2->addWidget(pushButton_addExpense);


        verticalLayout_5->addLayout(verticalLayout_2);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(360, 170, 341, 261));
        verticalLayout_6 = new QVBoxLayout(layoutWidget2);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_Transactions = new QLabel(layoutWidget2);
        label_Transactions->setObjectName("label_Transactions");
        label_Transactions->setFont(font4);
        label_Transactions->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_Transactions);

        pushButton_Transactions = new QPushButton(layoutWidget2);
        pushButton_Transactions->setObjectName("pushButton_Transactions");
        pushButton_Transactions->setStyleSheet(QString::fromUtf8("color:white;\n"
"font:bold;\n"
"font-size:14px;\n"
"background-color:rgb(102, 135, 255);"));

        verticalLayout_3->addWidget(pushButton_Transactions);


        verticalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_Reports = new QLabel(layoutWidget2);
        label_Reports->setObjectName("label_Reports");
        label_Reports->setFont(font4);
        label_Reports->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_Reports);

        pushButton_Reports = new QPushButton(layoutWidget2);
        pushButton_Reports->setObjectName("pushButton_Reports");
        pushButton_Reports->setStyleSheet(QString::fromUtf8("color:white;\n"
"font:bold;\n"
"font-size:14px;\n"
"background-color:rgb(102, 135, 255);"));

        verticalLayout_4->addWidget(pushButton_Reports);


        verticalLayout_6->addLayout(verticalLayout_4);

        MainMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainMenu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 754, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName("menuSettings");
        menuCurrency = new QMenu(menuSettings);
        menuCurrency->setObjectName("menuCurrency");
        MainMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(MainMenu);
        statusbar->setObjectName("statusbar");
        MainMenu->setStatusBar(statusbar);
        toolBar = new QToolBar(MainMenu);
        toolBar->setObjectName("toolBar");
        toolBar->setLayoutDirection(Qt::RightToLeft);
        MainMenu->addToolBar(Qt::TopToolBarArea, toolBar);
#if QT_CONFIG(shortcut)
        label_income->setBuddy(pushButton_addIncome);
        label_expense->setBuddy(pushButton_addExpense);
        label_Transactions->setBuddy(pushButton_Transactions);
        label_Reports->setBuddy(pushButton_Reports);
#endif // QT_CONFIG(shortcut)

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menuFile->addAction(actionDelete_All_Records);
        menuFile->addSeparator();
        menuFile->addAction(actionLogout);
        menuFile->addAction(actionExit);
        menuSettings->addAction(menuCurrency->menuAction());
        menuSettings->addAction(actionSet_Monthly_Prefix);
        menuCurrency->addAction(actionPKR);
        menuCurrency->addAction(actionUSD);
        menuCurrency->addAction(actionEuro);
        toolBar->addAction(actionCalender);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "MainWindow", nullptr));
        actionLogout->setText(QCoreApplication::translate("MainMenu", "Logout", nullptr));
        actionPKR->setText(QCoreApplication::translate("MainMenu", "PKR Rs.", nullptr));
        actionUSD->setText(QCoreApplication::translate("MainMenu", "USD $", nullptr));
        actionEuro->setText(QCoreApplication::translate("MainMenu", "Euro \342\202\254", nullptr));
        actionExit->setText(QCoreApplication::translate("MainMenu", "Exit", nullptr));
        actionDelete_All_Records->setText(QCoreApplication::translate("MainMenu", "Delete All Records...", nullptr));
        actionSet_Monthly_Prefix->setText(QCoreApplication::translate("MainMenu", "Set Monthly Prefix", nullptr));
        actionCalender->setText(QCoreApplication::translate("MainMenu", "Calender", nullptr));
        label_7->setText(QCoreApplication::translate("MainMenu", "Income", nullptr));
        label_6->setText(QCoreApplication::translate("MainMenu", "Expense", nullptr));
        label_5->setText(QCoreApplication::translate("MainMenu", "Balance", nullptr));
        pushButton_monthlyPrefix->setText(QCoreApplication::translate("MainMenu", "Add Monthly Prefix", nullptr));
        label_income->setText(QString());
        pushButton_addIncome->setText(QCoreApplication::translate("MainMenu", "Add Income", nullptr));
        label_expense->setText(QString());
        pushButton_addExpense->setText(QCoreApplication::translate("MainMenu", "Add Expenses", nullptr));
        label_Transactions->setText(QString());
        pushButton_Transactions->setText(QCoreApplication::translate("MainMenu", "All Transactions", nullptr));
        label_Reports->setText(QString());
        pushButton_Reports->setText(QCoreApplication::translate("MainMenu", "Reports", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainMenu", "File", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainMenu", "Settings", nullptr));
        menuCurrency->setTitle(QCoreApplication::translate("MainMenu", "Currency", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainMenu", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
