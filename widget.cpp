#include "widget.h"
#include "ui_widget.h"
#include <QtCharts/QtCharts>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //极坐标风向图 //曲线
    seriesWD = new QLineSeries();
    seriesWD->setName("texture pole"); //图表
    chartWD = new QPolarChart();
    chartWD->addSeries(seriesWD);
    chartWD->setTheme(QChart::ChartThemeBlueCerulean);
    //设置图表theme
    chartWD->setTitle("Polor WindDirection Chart");
    //坐标轴
    angleAxis = new QValueAxis();
    angleAxis->setTickCount(9);
    angleAxis->setLabelFormat("%.1f");
    //angleAxis->setLabelFormat("%d");
    angleAxis->setShadesVisible(true);
    angleAxis->setShadesBrush(QBrush(QColor(249, 249, 255)));
    chartWD->addAxis(angleAxis, QPolarChart::PolarOrientationAngular);
    radialAxis = new QValueAxis();
    radialAxis->setTickCount(9);
    radialAxis->setLabelFormat("%d");
    chartWD->addAxis(radialAxis, QPolarChart::PolarOrientationRadial);
    seriesWD->attachAxis(radialAxis);
    seriesWD->attachAxis(angleAxis);
    //画布
    chartViewWD = new QChartView();
    chartViewWD->setChart(chartWD);
    chartViewWD->setRenderHint(QPainter::Antialiasing);
    //加入布局
    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout = new QHBoxLayout();
    setLayout(mainLayout);
    mainLayout->addWidget(chartViewWD);
//    for (int i = 0; i <= 360; i+=30)
//    {
//      seriesWD->append(i, (i / 200.0)*200.0);
//    }
    radialAxis->setRange(0, 9);
    angleAxis->setRange(0, 360);
}

Widget::~Widget()
{
    delete ui;
}
