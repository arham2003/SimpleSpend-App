#ifndef REPORTSDIALOG_H
#define REPORTSDIALOG_H

#include "qboxlayout.h"
#include <QDialog>
#include <QChart>
#include <QtCharts/QChartGlobal>
#include <QChartView>
#include <QPieSeries>
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>

namespace Ui {
class ReportsDialog;
}

class ReportsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReportsDialog(const QString &username, QWidget *parent = nullptr);
    ~ReportsDialog();

private:
    Ui::ReportsDialog *ui;
    QString currentUsername;
    QChart *chart;

    void createIncomeBarChart(QVBoxLayout *layout);
    void createExpenseBarChart(QVBoxLayout *layout);
    void createCategoryPieChart(QVBoxLayout *layout);
    void loadAndAppendData(const QString &type, QBarSeries *series);
    void loadAndAppendCategoryData(QPieSeries *series);
};

#endif // REPORTSDIALOG_H
