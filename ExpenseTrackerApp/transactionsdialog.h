#ifndef TRANSACTIONSDIALOG_H
#define TRANSACTIONSDIALOG_H

#include "qdatetime.h"
#include <QDialog>
#include <QListWidget>
#include <QComboBox>
#include <QLabel>

namespace Ui {
class TransactionsDialog;
}

class TransactionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransactionsDialog(const QString &username, QWidget *parent = nullptr);
    ~TransactionsDialog();

private slots:
    void on_comboBox_activated(int index);

private:
    Ui::TransactionsDialog *ui;

private:
    QListWidget *transactionsListWidget;
    QComboBox *sortComboBox;
    QLabel *labelHighestMonthlySpending;
    QLabel *labelHighestYearlySpending;
    QLabel *totalSpendingsLabel;
   // QTextEdit *textEdit_transactionShow;

    QString currentUsername;

    struct TransactionNode {
        QString type;
        double amount;
        QString category;
        QString mode;
        QDate date;
        TransactionNode *next;
        TransactionNode *prev;
    };

    TransactionNode *head;

    void swapNodes(TransactionNode *node1, TransactionNode *node2);
    void loadTransactions();
    void sortTransactions();
    void updateTransactionTextEdit();
    TransactionNode* mergeSort(TransactionNode* head, const QString& sortBy, std::function<bool(const QDate&, const QDate&)> compare);
    TransactionNode* findMiddle(TransactionNode* head);
    TransactionNode* merge(TransactionNode* left, TransactionNode* right, const QString& sortBy, std::function<bool(const QDate&, const QDate&)> compare);

    double calculateHighestMonthlySpending();
    double calculateHighestYearlySpending();
    void updateTotalSpendingsLabel();
    void displayTransactions();

private:
    double highestMonthlySpending;
    double highestYearlySpending;
};

#endif // TRANSACTIONSDIALOG_H
