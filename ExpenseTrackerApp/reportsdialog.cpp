#include "ui_reportsdialog.h"
#include <QtCharts/QChartView>
#include <QGraphicsTextItem>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QFile>
#include <QTextStream>
#include <QMap>
#include <QBarCategoryAxis>
#include <QVBoxLayout>
#include <QScrollArea>

#include "reportsdialog.h"

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QFile>
#include <QTextStream>
#include <QMap>
#include <QDate>
#include <QBarCategoryAxis>
#include <QVBoxLayout>
#include <QScrollArea>

ReportsDialog::ReportsDialog(const QString &username, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportsDialog),
    currentUsername(username)
{
    Qt::WindowFlags flags = windowFlags();
    setWindowFlags(flags | Qt::WindowMaximizeButtonHint);

    ui->setupUi(this);
    QString styleSheet = "QDialog { background-color: silver;}";
    this->setStyleSheet(styleSheet);

    chart = new QChart();

    setWindowTitle("Reports");

    QVBoxLayout *layout = new QVBoxLayout(this);
    QScrollArea *scrollArea = new QScrollArea(this);
    QWidget *scrollWidget = new QWidget(this);
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollWidget);

    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollWidget);

    layout->addWidget(scrollArea);

    createIncomeBarChart(scrollLayout);
    createExpenseBarChart(scrollLayout);
    createCategoryPieChart(scrollLayout);
}

ReportsDialog::~ReportsDialog()
{
    delete ui;
}

void ReportsDialog::createIncomeBarChart(QVBoxLayout *layout)
{

    QChart *incomeChart = new QChart();

    QBarSeries *incomeSeries = new QBarSeries();

    loadAndAppendData("Income", incomeSeries);

    incomeChart->addSeries(incomeSeries);
    incomeChart->setTitle("Report by Monthly Income");
    QFont titleFont = incomeChart->titleFont();
    titleFont.setBold(true);
    incomeChart->setTitleFont(titleFont);
    incomeChart->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Amount");
    incomeChart->addAxis(axisY, Qt::AlignLeft);
    incomeSeries->attachAxis(axisY);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->setTitleText("Data");
    incomeChart->addAxis(axisX, Qt::AlignBottom);
    incomeSeries->attachAxis(axisX);

    QChartView *incomeChartView = new QChartView(incomeChart);
    incomeChartView->setRenderHint(QPainter::Antialiasing);
    incomeChartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    incomeChartView->setMinimumSize(400,600);

    layout->addWidget(incomeChartView);
}

void ReportsDialog::createExpenseBarChart(QVBoxLayout *layout)
{


    QChart *expenseChart = new QChart();

    QBarSeries *expenseSeries = new QBarSeries();

    loadAndAppendData("Expense", expenseSeries);

    expenseChart->addSeries(expenseSeries);
    expenseChart->setTitle("Report by Monthly Expenses");
    QFont titleFont = expenseChart->titleFont();
    titleFont.setBold(true);
    expenseChart->setTitleFont(titleFont);
    expenseChart->setAnimationOptions(QChart::SeriesAnimations);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Amount");
    expenseChart->addAxis(axisY, Qt::AlignLeft);
    expenseSeries->attachAxis(axisY);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->setTitleText("Data");
    expenseChart->addAxis(axisX, Qt::AlignBottom);
    expenseSeries->attachAxis(axisX);

    QChartView *expenseChartView = new QChartView(expenseChart);
    expenseChartView->setRenderHint(QPainter::Antialiasing);
    expenseChartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    expenseChartView->setMinimumSize(400, 600);

    layout->addWidget(expenseChartView);
}

void ReportsDialog::createCategoryPieChart(QVBoxLayout *layout)
{




    QChart *categoryChart = new QChart();

    QPieSeries *categorySeries = new QPieSeries();

    loadAndAppendCategoryData(categorySeries);
    categoryChart->addSeries(categorySeries);
    categoryChart->setTitle("Report by Categories");
    QFont titleFont = categoryChart->titleFont();
    titleFont.setBold(true);
    categoryChart->setTitleFont(titleFont);
    categoryChart->setAnimationOptions(QChart::SeriesAnimations);

    QChartView *categoryChartView = new QChartView(categoryChart);
    categoryChartView->setRenderHint(QPainter::Antialiasing);
    categoryChartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    categoryChartView->setMinimumSize(400, 500);

    layout->addWidget(categoryChartView);
}

void ReportsDialog::loadAndAppendData(const QString &type, QBarSeries *series)
{
    QString ledgerFilePath = "ledger_" + currentUsername + ".txt";
    QFile IncExpFile(ledgerFilePath);

    if (!IncExpFile.open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }

    QTextStream input(&IncExpFile);
    QStringList lines;

    while (!input.atEnd())
    {
        QString IncExpense = input.readLine();
        lines.append(IncExpense.split(","));
    }

    IncExpFile.close();

    QMap<QString, QMap<QString, double>> monthData;

    for (int i = 0; i + 4 < lines.size(); i = i + 5)
    {
        QString currentType = lines[i];
        QString amount = lines[i + 1];
        QString date = lines[i + 4];

        if (currentType == type)
        {
            QString currentMonthKey = QDate::fromString(date, "dd-MM-yyyy").toString("MMMM yyyy");

            if (!monthData.contains(currentMonthKey))
            {
                monthData[currentMonthKey] = QMap<QString, double>();
            }

            if (!monthData[currentMonthKey].contains(type))
            {
                monthData[currentMonthKey][type] = 0.0;
            }

            monthData[currentMonthKey][type] += amount.toDouble();
        }
    }

    // Create categories and append data to series
    QStringList categories;
    for (const auto &month : monthData.keys())
    {
        QBarSet *currentSet = new QBarSet(type);
        *currentSet << monthData[month][type];
        series->append(currentSet);

        // Collect categories for the x-axis labels
        categories << month;

        // Add text label to the bar
        QString label = QString("%1")
                            .arg(month);
        currentSet->setLabel(label);
    }

    // Set up the x-axis
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    series->attachAxis(axisX);
}










void ReportsDialog::loadAndAppendCategoryData(QPieSeries *series)
{
    QString ledgerFilePath = "ledger_" + currentUsername + ".txt";
    QFile IncExpFile(ledgerFilePath);

    if (!IncExpFile.open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }

    QTextStream input(&IncExpFile);
    QStringList lines;

    while (!input.atEnd())
    {
        QString IncExpense = input.readLine();
        lines.append(IncExpense.split(","));
    }

    IncExpFile.close();

    QMap<QString, double> categoryAmounts;

    for (int i = 0; i + 4 < lines.size(); i = i + 5)
    {
        QString currentType = lines[i];
        QString amount = lines[i + 1];
        QString category = lines[i + 2];

        if (currentType == "Expense" || currentType == "Income")
        {
            double currentAmount = categoryAmounts.value(category, 0.0);
            currentAmount += amount.toDouble();
            categoryAmounts.insert(category, currentAmount);
        }
    }

    for (auto it = categoryAmounts.begin(); it != categoryAmounts.end(); ++it)
    {
        series->append(it.key(), it.value());
    }
}
