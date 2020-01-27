#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    Record.setNumNights(arg1);
}

void MainWindow::on_roomView_currentIndexChanged(int index)
{
    Record.setRoomSize(index);
}

void MainWindow::on_roomSize_currentIndexChanged(int index)
{
    Record.setRoomSize(index);
}

void MainWindow::on_resDate_userDateChanged(const QDate &date)
{
    Record.setStartDate(date);
}

void MainWindow::on_numAdults_valueChanged(int arg1)
{
    Record.setNumAdults(arg1);
}

void MainWindow::on_lenStay_valueChanged(int arg1)
{
    Record.setNumChildren(arg1);
}

void MainWindow::on_parking_clicked(bool checked)
{
    if (checked)
        Record.setParkingNeeded(true);
    else
        Record.setParkingNeeded(false);
}
