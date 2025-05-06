#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QMap>
#include <QString>



    class ChartWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChartWindow(QWidget *parent = nullptr);
    // This function accepts the map with statistics to update the chart
    void setChartData(const QMap<QString, int> &data);

private:
    QChartView *chartView;
};

#endif // CHARTWINDOW_H
