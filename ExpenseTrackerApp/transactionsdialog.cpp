#include "transactionsdialog.h"
#include "ui_transactionsdialog.h"
#include <QVBoxLayout>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDate>
#include <QMap>

TransactionsDialog::TransactionsDialog(const QString &username, QWidget *parent)
    : QDialog(parent), ui(new Ui::TransactionsDialog), currentUsername(username), head(nullptr),
        highestMonthlySpending(0.0), highestYearlySpending(0.0)
{
    ui->setupUi(this);

    setWindowTitle("Transactions");

    QString styleSheet = "QDialog { background-color: silver;}";
    this->setStyleSheet(styleSheet);

    transactionsListWidget = new QListWidget(this);
    labelHighestMonthlySpending = new QLabel(this);
    labelHighestYearlySpending = new QLabel(this);
    totalSpendingsLabel = new QLabel(this);

    sortComboBox = new QComboBox(this);
    sortComboBox->addItem("Sort by Date");
    sortComboBox->addItem("Sort by Amount");
    sortComboBox->addItem("Sort by Category");



//    textEdit_transactionShow = new QTextEdit(this);
//    textEdit_transactionShow->setReadOnly(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(sortComboBox);
    layout->addWidget(transactionsListWidget);
    layout->addWidget(labelHighestMonthlySpending);
    layout->addWidget(labelHighestYearlySpending);
    layout->addWidget(totalSpendingsLabel);
    //layout->addWidget(textEdit_transactionShow);

    connect(sortComboBox, QOverload<int>::of(&QComboBox::activated), this, &TransactionsDialog::on_comboBox_activated);
    loadTransactions();
    sortTransactions();
    displayTransactions();
    calculateHighestMonthlySpending();
    calculateHighestYearlySpending();
    updateTotalSpendingsLabel();
}

TransactionsDialog::~TransactionsDialog()
{
    while (head != nullptr)
    {
        TransactionNode *temp = head;
        head = head->next;
        delete temp;
    }
    delete ui;
}

void TransactionsDialog::on_comboBox_activated(int index)
{
    sortTransactions();
    displayTransactions();
    double highestMonthlySpending = calculateHighestMonthlySpending();
    double highestYearlySpending = calculateHighestYearlySpending();

    labelHighestMonthlySpending->setText(QString("Highest Monthly Spending (Current Month): %1").arg(highestMonthlySpending));
    labelHighestYearlySpending->setText(QString("Highest Yearly Spending(Current Year): %1").arg(highestYearlySpending));

}

/*void TransactionsDialog::updateTransactionTextEdit()
{
    QString text;
    TransactionNode *current = head;
    while (current != nullptr)
    {
        text += QString("%1, %2, %3, %4, %5\n")
                    .arg(current->type)
                    .arg(current->amount)
                    .arg(current->category)
                    .arg(current->mode)
                    .arg(current->date.toString("dd-MM-yyyy"));

        current = current->next;
    }

    textEdit_transactionShow->setPlainText(text);
}*/

void TransactionsDialog::loadTransactions()
{
    QString ledgerFilePath = "ledger_" + currentUsername + ".txt";
    QFile IncExpFile(ledgerFilePath);

    if (!IncExpFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Title", "Ledger File not open!");
        return;
    }

    QTextStream input(&IncExpFile);

    while (!input.atEnd())
    {
        TransactionNode *newTransaction = new TransactionNode;
        QStringList fields = input.readLine().split(",");

        newTransaction->type = fields[0];
        newTransaction->amount = fields[1].toDouble();
        newTransaction->category = fields[2];
        newTransaction->mode = fields[3];
        newTransaction->date = QDate::fromString(fields[4], "dd-MM-yyyy");
        newTransaction->next = nullptr;

        // Insert new transaction at the beginning of the linked list
        newTransaction->next = head;
        head = newTransaction;
    }

    IncExpFile.close();
}

void TransactionsDialog::sortTransactions()
{
    switch (sortComboBox->currentIndex())
    {
    case 1: // Sort by Amount (High to Low)
        // Sorting by amount using Bubble Sort
        {
            std::vector<TransactionNode *> transactionVector;
            TransactionNode *current = head;
            while (current != nullptr)
            {
                transactionVector.push_back(current);
                current = current->next;
            }

            //            std::sort(transactionVector.begin(), transactionVector.end(), [](TransactionNode *a, TransactionNode *b) {
            //                return a->amount < b->amount;
            //            });
            //Bubble Sort
            int n = transactionVector.size();
            bool swapped;

            do {
                swapped = false;

                for (int i = 1; i < n; ++i) {
                    if (transactionVector[i - 1]->amount > transactionVector[i]->amount) {
                        std::swap(transactionVector[i - 1], transactionVector[i]);
                        swapped = true;
                    }
                }
                n--;
            } while (swapped);


            head = nullptr;
            for (TransactionNode *node : transactionVector)
            {
                node->next = head;
                head = node;
            }
        }
        break;

    case 2: // Sort by Category (Ascending Alphabetically A to Z)
        // Sorting by category using std::sort
        {
            std::vector<TransactionNode *> categoryVector;
            TransactionNode *current = head;
            while (current != nullptr)
            {

                categoryVector.push_back(current);
                current = current->next;
            }

            /*std::sort(categoryVector.begin(), categoryVector.end(), [](TransactionNode *a, TransactionNode *b) {
                return a->category < b->category;
            });*/

            //Updated by Aarib here, can it be seen?
            //Selection Sort
            int n = categoryVector.size();
            for (int i = 0; i < n - 1; ++i) {
                int minIndex = i;
                for (int j = i + 1; j < n; ++j) {
                    if (categoryVector[j]->category > categoryVector[minIndex]->category) {
                        minIndex = j;
                    }
                }
                std::swap(categoryVector[i], categoryVector[minIndex]);
            }

            head = nullptr;
            for (TransactionNode *node : categoryVector)
            {
                node->next = head;
                head = node;
            }
        }
        break;

        // Add other cases as needed
    default:
        // Default case: Sort by Date
        if (head != nullptr)
        {
            head = mergeSort(head, "date", std::greater<QDate>());
        }
        break;
    }
}

double TransactionsDialog::calculateHighestMonthlySpending()
{
    QMap<QString, double> monthlySpendings;
    int currentYear = QDate::currentDate().year();
    int currentMonth = QDate::currentDate().month();

    // Traverse the linked list to calculate highest monthly spending
    TransactionNode *current = head;
    highestMonthlySpending = 0.0; // Initialize to 0 before finding the maximum

    while (current != nullptr)
    {
        int key = current->date.year();
        int key2 = current->date.month();
        if (current->type == "Expense" && current->date.isValid() && key == currentYear && key2 == currentMonth)
        {
            QString currentMonthKey = current->date.toString("MM-yyyy");
            double expenseAmount = current->amount;

            double currentMonthlySpending = monthlySpendings.value(currentMonthKey, 0.0);
            currentMonthlySpending = expenseAmount;

            monthlySpendings.insert(currentMonthKey, currentMonthlySpending);

            if (currentMonthlySpending > highestMonthlySpending)
            {
                highestMonthlySpending = currentMonthlySpending;
            }
        }

        current = current->next;
    }

    return highestMonthlySpending;

}

void TransactionsDialog::updateTotalSpendingsLabel()
{
    double totalSpendings = 0.0;

    // Traverse the linked list to calculate total spendings from expenses in the current year
    TransactionNode *current = head;
    int currentYear = QDate::currentDate().year();

    while (current != nullptr)
    {
        if (current->type == "Expense")
        {
            int year = current->date.year();

            if (year == currentYear)
            {
                totalSpendings += current->amount;
            }
        }

        current = current->next;
    }

    totalSpendingsLabel->setText("Total Spendings (Current Year): " + QString::number(totalSpendings));
}

double TransactionsDialog::calculateHighestYearlySpending()
{
    QMap<int, double> yearlySpendings;

    int currentYear = QDate::currentDate().year(); // Get the current year
    double highestYearlySpending = 0.0;           // Initialize to 0 before finding the maximum

    // Traverse the linked list to calculate highest yearly spending
    TransactionNode *current = head;

    while (current != nullptr)
    {
        if (current->type == "Expense")
        {
            int key = current->date.year();
            double expenseAmount = current->amount;

            if (key == currentYear)
            {
                double currentYearlySpending = yearlySpendings.value(key, 0.0);
                currentYearlySpending = expenseAmount;

                yearlySpendings.insert(key, currentYearlySpending);

                if (currentYearlySpending > highestYearlySpending)
                {
                    highestYearlySpending = currentYearlySpending;
                }
            }
        }

        current = current->next;
    }

    return highestYearlySpending;
}

TransactionsDialog::TransactionNode* TransactionsDialog::mergeSort(TransactionNode* head, const QString& sortBy, std::function<bool(const QDate&, const QDate&)> compare)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    TransactionNode* middle = findMiddle(head);
    TransactionNode* nextToMiddle = middle->next;

    middle->next = nullptr;

    TransactionNode* left = mergeSort(head, sortBy, compare);
    TransactionNode* right = mergeSort(nextToMiddle, sortBy, compare);

    return merge(left, right, sortBy, compare);
}

TransactionsDialog::TransactionNode* TransactionsDialog::findMiddle(TransactionNode* head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    TransactionNode* slow = head;
    TransactionNode* fast = head->next;

    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}


TransactionsDialog::TransactionNode* TransactionsDialog::merge(TransactionNode* left, TransactionNode* right, const QString& sortBy, std::function<bool(const QDate&, const QDate&)> compare)
{
    TransactionNode* result = nullptr;

    if (left == nullptr)
    {
        return right;
    }
    if (right == nullptr)
    {
        return left;
    }

    if (compare(left->date, right->date))
    {
        result = left;
        result->next = merge(left->next, right, sortBy, compare);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next, sortBy, compare);
    }

    return result;
}

void TransactionsDialog::displayTransactions()
{
    transactionsListWidget->clear();

    TransactionNode *current = head;
    while (current != nullptr)
    {
        QString transactionString;

        if (sortComboBox->currentIndex() == 2) // Sort by Category
        {
            transactionString = QString("Category: %1\n").arg(current->category);
            transactionString += QString("Amount: %1\n").arg(current->amount);
            transactionString += QString("Mode: %1\n").arg(current->mode);
            transactionString += QString("Date: %1\n").arg(current->date.toString("dd-MM-yyyy"));
        }
        else // Sort by Date or Amount
        {
            transactionString = QString("Type: %1\n").arg(current->type);
            transactionString += QString("Amount: %1\n").arg(current->amount);
            transactionString += QString("Category: %1\n").arg(current->category);
            transactionString += QString("Mode: %1\n").arg(current->mode);
            transactionString += QString("Date: %1\n").arg(current->date.toString("dd-MM-yyyy"));
        }

        transactionsListWidget->addItem(transactionString);
        current = current->next;
    }
}


