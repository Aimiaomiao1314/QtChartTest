#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineSeries>
#include <QPolarChart>
#include <QValueAxis>
#include <QChartView>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QLineSeries *seriesWD; //曲线声明
    QPolarChart *chartWD; //极坐标图表声明
    QValueAxis *angleAxis; //角坐标，相对应于直角坐标系的X轴
    QValueAxis* radialAxis;//极坐标，相对应于直角坐标系的Y轴
    QChartView* chartViewWD; //画布声明

};

#endif // WIDGET_H
