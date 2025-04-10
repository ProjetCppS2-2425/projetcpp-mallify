#include "chartwindow.h"
#include <QtCharts/QChart>
#include <QtCharts/QPieSlice>
#include <QPainter>

ChartWindow::ChartWindow(QWidget *parent) : QMainWindow(parent)
{
    // Create an empty pie series initially
    QPieSeries *series = new QPieSeries();

    // Create a chart, add the series, and set a title
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques par type de réclamation");

    // Create the chart view and set it as the central widget
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
}

void ChartWindow::setChartData(const QMap<QString, int> &data)
{
    // Calculate total count for percentage calculations.
    int total = 0;
    for (auto value : data) {
        total += value;
    }

    // Create a new pie series and add slices with percentage labels.
    QPieSeries *series = new QPieSeries();
    for (auto it = data.begin(); it != data.end(); ++it) {
        int count = it.value();
        double percentage = (total > 0) ? (count * 100.0 / total) : 0;
        // Format label as: "Type (count, percentage%)"
        QString label = QString("%1 (%2, %3%)")
                            .arg(it.key())
                            .arg(count)
                            .arg(QString::number(percentage, 'f', 1));
        series->append(label, count);
    }

    // Update the chart with the new series.
    QChart *chart = chartView->chart();
    chart->removeAllSeries();
    chart->addSeries(series);
    chart->setTitle("Statistiques par type de réclamation");
}
