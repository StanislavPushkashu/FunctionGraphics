#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>

#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool flag = false;
    QChart *Ch = new QChart();
    QChartView *ChV = new QChartView(Ch);
    QLineSeries *FunctionCh = new QLineSeries();
    QLineSeries *SecondSeries = new QLineSeries();

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    double GetY_LinearFunction(double x, double a, double b);
    double GetY_RadicalFunction(double x, double a, double b);
    double GetY_AbsoluteFunction(double x, double a, double b);
    double GetY_SecondDegreeFunction(double x, double a, double b);
    double GetY_ThirdDegreeFunction(double x, double a, double b);
    double GetY_SINFunction(double x, double a, double b);
    double GetY_COSFunction(double x, double a, double b);
    double GetY_TANFunction(double x, double a, double b);
    double GetY_COTANFunction(double x, double a, double b);

    QChart::AnimationOption GetAnimationState();
    QChart::ChartTheme GetThemeState();

    void on_ThemesComboBox_activated(int index);

    void on_AnimationsComboBox_activated(int index);

    void on_DrawButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
