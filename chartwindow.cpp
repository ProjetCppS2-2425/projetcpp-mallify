#include "chartwindow.h"
#include <QChartView>
#include <QChart>
#include <QPieSeries>
#include <QPieSlice>
#include <QPainter>

ChartWindow::ChartWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create an empty pie series
    auto *series = new QPieSeries();

    // Create the chart (no QWidget* parent!)
    auto *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques par type de réclamation");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Put the chart into a view, and set this window as its parent
    chartView = new QChartView(chart, this);  // QChartView(QChart*, QWidget* parent)
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
}

void ChartWindow::setChartData(const QMap<QString, int> &data)
{
    int total = 0;
    for (int v : data) total += v;

    auto *series = new QPieSeries();
    for (auto it = data.constBegin(); it != data.constEnd(); ++it) {
        double pct = total > 0 ? it.value() * 100.0 / total : 0;
        QString label = QString("%1 (%2, %3%)")
                            .arg(it.key())
                            .arg(it.value())
                            .arg(QString::number(pct, 'f', 1));
        series->append(label, it.value());
    }

    series->setLabelsVisible(true);
    // Use QPieSlice::LabelOutside, not a QPieSeries enum
    series->setLabelsPosition(QPieSlice::LabelOutside);

    QFont f;
    f.setPointSize(16);
    f.setBold(true);
    for (QPieSlice *slice : series->slices()) {
        slice->setLabelFont(f);
        slice->setExploded(true);
        slice->setExplodeDistanceFactor(0.1);
    }

    auto *chart = chartView->chart();
    chart->removeAllSeries();
    chart->addSeries(series);
    chart->setTitle("Statistiques par type de réclamation");
}
