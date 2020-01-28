#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <iomanip>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayCost(double estCost)
{
    stringstream cost;
    cost << fixed << setprecision(2) << estCost;
    string c = cost.str();
    ui->totCost->setText("$" + QString::fromStdString(c));
}

void MainWindow::on_nextPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_nextPage_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_lastPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_lastPage_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_nameInput_textChanged()
{
    QString name = ui->nameInput->toPlainText();
    Record.setCustomerName(name.toUtf8().constData());
}

void MainWindow::on_numChild_valueChanged(int arg1)
{
    Record.setNumChildren(arg1);
}

void MainWindow::on_roomView_currentIndexChanged(int index)
{
    Record.setRoomView(index);
    double estCost = Record.CalculateCost();
    displayCost(estCost);
}

void MainWindow::on_roomSize_currentIndexChanged(int index)
{
    Record.setRoomSize(index);
    double estCost = Record.CalculateCost();
    displayCost(estCost);

    // reset guest values
    ui->numChild->setValue(0);
    ui->numAdults->setValue(1);

    // set maximum number of guests based on room size
    int adultMax = 1;
    int childMax = 0;
    if (index == 1)
    {
        adultMax = 3;
        childMax = 2;
    }
    else if (index == 2)
    {
        adultMax = 4;
        childMax = 3;
    }
    ui->numAdults->setMaximum(adultMax);
    ui->numChild->setMaximum(childMax);
}

void MainWindow::on_resDate_userDateChanged(const QDate &date)
{
    Record.setStartDate(date);
}

void MainWindow::on_numAdults_valueChanged(int arg1)
{
    int roomSize = Record.getRoomSize();
    int maxChildren = 0;
    if (roomSize == 1)
        maxChildren = 3 - arg1;
    else if (roomSize == 2)
        maxChildren = 4 - arg1;
    ui->numChild->setMaximum(maxChildren);

    Record.setNumAdults(arg1);
}

void MainWindow::on_lenStay_valueChanged(int arg1)
{
    Record.setNumNights(arg1);
    double estCost = Record.CalculateCost();
    displayCost(estCost);
}

void MainWindow::on_parking_clicked(bool checked)
{
    if (checked)
        Record.setParkingNeeded(true);
    else
        Record.setParkingNeeded(false);
}
