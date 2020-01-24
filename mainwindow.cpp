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
