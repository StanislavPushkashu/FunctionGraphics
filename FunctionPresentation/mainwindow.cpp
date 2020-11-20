#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCharts>
#include <QLineSeries>

#include <QDebug>

using namespace QtCharts;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // possible functions
    ui->AvailableFunctionsComboBox->addItem("Linear Funtion (y = a * x + b)");
    ui->AvailableFunctionsComboBox->addItem("Radical Function (y = a / x + b)");
    ui->AvailableFunctionsComboBox->addItem("Absolute function (y = a * |x| + b)");
    ui->AvailableFunctionsComboBox->addItem("Second degree function (y = a * x^2 + b)");
    ui->AvailableFunctionsComboBox->addItem("Third degree function (y = a * x^3 + b)");
    ui->AvailableFunctionsComboBox->addItem("Sinus Function (y = sin(x))");
    ui->AvailableFunctionsComboBox->addItem("Cosinus Function (y = cos(x))");

    // possible themes

    ui->ThemesComboBox->addItem("Light");
    ui->ThemesComboBox->addItem("Blue Cerulean");
    ui->ThemesComboBox->addItem("Dark");
    ui->ThemesComboBox->addItem("Brown Sand");
    ui->ThemesComboBox->addItem("Blue NCS");
    ui->ThemesComboBox->addItem("High Contrast");
    ui->ThemesComboBox->addItem("Blue Icy");
    ui->ThemesComboBox->addItem("Qt");

    // possbile animations

    ui->AnimationsComboBox->addItem("No animation");
    ui->AnimationsComboBox->addItem("Grid axis");
    ui->AnimationsComboBox->addItem("Series");
    ui->AnimationsComboBox->addItem("All animations");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ThemesComboBox_activated(int index)
{
    if (!index)
        Ch->setTheme(QChart::ChartThemeLight);
    else if (index == 1)
        Ch->setTheme(QChart::ChartThemeBlueCerulean);
    else if (index == 2)
        Ch->setTheme(QChart::ChartThemeDark);
    else if (index == 3)
        Ch->setTheme(QChart::ChartThemeBrownSand);
    else if (index == 4)
        Ch->setTheme(QChart::ChartThemeBlueNcs);
    else if (index == 5)
        Ch->setTheme(QChart::ChartThemeHighContrast);
    else if (index == 6)
        Ch->setTheme(QChart::ChartThemeBlueIcy);
    else if (index == 7)
        Ch->setTheme(QChart::ChartThemeQt);
}

void MainWindow::on_AnimationsComboBox_activated(int index)
{
    if (!index)
        Ch->setAnimationOptions(QChart::NoAnimation);
    else if (index == 1)
        Ch->setAnimationOptions(QChart::GridAxisAnimations);
    else if (index == 2)
        Ch->setAnimationOptions(QChart::SeriesAnimations);
    else if (index == 3)
        Ch->setAnimationOptions(QChart::AllAnimations);
}

double MainWindow::GetY_LinearFunction(double x, double a, double b)
{ return (a * x + b); }

double MainWindow::GetY_RadicalFunction(double x, double a, double b)
{ return (1 / x); }

double MainWindow::GetY_AbsoluteFunction(double x, double a, double b)
{ return (a * abs(x) + b); }

double MainWindow::GetY_SecondDegreeFunction(double x, double a, double b)
{ return (a * pow(x, 2) + b); }

double MainWindow::GetY_ThirdDegreeFunction(double x, double a, double b)
{ return (a * pow(x, 3) + b); }

double MainWindow::GetY_SINFunction(double x, double a, double b)
{ return a * sin(x) + b; }

double MainWindow::GetY_COSFunction(double x, double a, double b)
{ return a * cos(x) + b; }

double MainWindow::GetY_TANFunction(double x, double a, double b)
{ return a * tan(x) + b; }

double MainWindow::GetY_COTANFunction(double x, double a, double b)
{ return a * cos(x) / sin(x) + b; }

QChart::AnimationOption MainWindow::GetAnimationState()
{
    if (!ui->AnimationsComboBox->currentIndex())
        return QChart::NoAnimation;
    else if (ui->AnimationsComboBox->currentIndex() == 1)
        return QChart::GridAxisAnimations;
    else if (ui->AnimationsComboBox->currentIndex() == 2)
        return QChart::SeriesAnimations;
    else if (ui->AnimationsComboBox->currentIndex() == 3)
        return QChart::AllAnimations;
}

QChart::ChartTheme MainWindow::GetThemeState()
{
    if (!ui->ThemesComboBox->currentIndex())
        return QChart::ChartThemeLight;
    else if (ui->ThemesComboBox->currentIndex() == 1)
        return QChart::ChartThemeBlueCerulean;
    else if (ui->ThemesComboBox->currentIndex() == 2)
        return QChart::ChartThemeDark;
    else if (ui->ThemesComboBox->currentIndex() == 3)
        return QChart::ChartThemeBrownSand;
    else if (ui->ThemesComboBox->currentIndex() == 4)
        return QChart::ChartThemeBlueNcs;
    else if (ui->ThemesComboBox->currentIndex() == 5)
        return QChart::ChartThemeHighContrast;
    else if (ui->ThemesComboBox->currentData() == 6)
        return QChart::ChartThemeBlueIcy;
    else if (ui->ThemesComboBox->currentIndex() == 7)
        return QChart::ChartThemeQt;
}

void MainWindow::on_DrawButton_clicked()
{
    int index = ui->AvailableFunctionsComboBox->currentIndex();
    double y;
    double a = ui->ALineEdit->text().toDouble();
    double b = ui->BLineEdit->text().toDouble();
    double z = 1;

    // clearing all the data before updating
    ui->GridLayout->removeWidget(ChV);

    // updating

    Ch = new QChart();
    ChV = new QChartView(Ch);
    FunctionCh = new QLineSeries();
    SecondSeries = new QLineSeries();

    if (index == 0){
        for (int i = -100; i <= 100; i++){
            y = GetY_LinearFunction(i, a, b);
            FunctionCh->append(i, y);
        }
    }


    // to be continued
    else if (index == 1){
        for (double i = -100; i < 0; i += 0.1){
            if (!i)
                continue;
            y = GetY_RadicalFunction(i, a, b);
            FunctionCh->append(i, y);
        }
        for (double i = 1; i <= 100; i += 0.1){
            y = GetY_RadicalFunction(i, a, b);
            SecondSeries->append(i, y);
        }
    }
    else if (index == 2)
        for (double i = -100; i <= 100; i += 0.1){
            y = GetY_AbsoluteFunction(i, a, b);
            FunctionCh->append(i, y);
        }
    else if (index == 3)
        for (double i = -100; i < 100; i += 0.1){
            y = GetY_SecondDegreeFunction(i, a, b);
            FunctionCh->append(i, y);
        }
    else if (index == 4)
        for (double i = -100; i <= 100; i += 0.1){
            y = GetY_ThirdDegreeFunction(i, a, b);
            FunctionCh->append(i, y);
        }
    else if (index == 5)
        for (double i = -100; i < 100; i += 0.1){
            y = GetY_SINFunction(i, a, b);
            FunctionCh->append(i, y);
        }
    else if (index == 6)
        for (double i = -100; i < 100; i += 0.1){
            y = GetY_COSFunction(i, a, b);
            FunctionCh->append(i, y);
        }

    Ch->addSeries(FunctionCh);
    if(index == 1)
        Ch->addSeries(SecondSeries);
    Ch->createDefaultAxes();
    Ch->legend()->hide();
    Ch->setAnimationOptions(GetAnimationState());
    Ch->setTheme(GetThemeState());
    ChV->setRenderHint(QPainter::Antialiasing);

    ui->GridLayout->addWidget(ChV, 4, 0);
}
