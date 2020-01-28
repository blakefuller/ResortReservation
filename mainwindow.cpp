#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <iomanip>
#include <QLineEdit>
#include <QMessageBox>

extern const double PARK_FEE;
extern const double RESORT_FEE;

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

string MainWindow::formatPrice(double price)
{
    stringstream ss;
    ss << fixed << setprecision(2) << price;
    return ss.str();
}

void MainWindow::on_nextPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    // display room type
    string roomText;
    int roomSize = Record.getRoomSize();
    int roomView = Record.getRoomView();
    if(roomSize == 1 && roomView == 1)
        roomText = "1-King Standard room";
    else if(roomSize == 1 && roomView == 2)
        roomText = "1-King Atrium room";
    else if (roomSize == 2 && roomView == 1)
        roomText = "2-Queen Standard room";
    else if (roomSize == 2 && roomView == 2)
        roomText = "2-Queen Atrium room";
    ui->roomDis->setText(QString::fromStdString(roomText));

    // display tax
    double tax = Record.CalculateCost() * 0.15;
    string t = formatPrice(tax);
    ui->taxDis->setText("$" + QString::fromStdString(t));

    // display parking fee
    double parking = 0;
    if(Record.getParkingNeeded())
        parking = PARK_FEE * Record.getNumNights();
    string p = formatPrice(parking);
    ui->parkDis->setText("$" + QString::fromStdString(p));

    // display resort fee
    double resort = RESORT_FEE * Record.getNumNights();
    string r = formatPrice(resort);
    ui->resDis->setText("$" + QString::fromStdString(r));

    // display resort fee
    double total = Record.CalculateCost() + tax + parking + resort;
    string tc = formatPrice(total);
    ui->totDis->setText("$" + QString::fromStdString(tc));
}

void MainWindow::on_nextPage_2_clicked()
{
    // build message box
    QMessageBox msgBox;
    msgBox.setText("Payment successfully processed");
    msgBox.exec();

    // page 3 start date
    QDate startDate = Record.getStartDate();
    ui->nightLabel->setText(startDate.toString("MM/dd/yyyy"));

    // page 3 length of stay
    int numNights = Record.getNumNights();
    ui->stayNum->setText(QString::number(numNights));

    // page 3 size and view of room
    int roomSize = Record.getRoomSize();
    int roomView = Record.getRoomView();
    if(roomSize == 1 && roomView == 1)
    {
        ui->sizeOfRoom->setText("1-King");
        ui->typeOfRoom->setText("Standard");
    }
    else if(roomSize == 1 && roomView == 2)
    {
        ui->sizeOfRoom->setText("1-King");
        ui->typeOfRoom->setText("Atrium");
    }
    else if (roomSize == 2 && roomView == 1)
    {
        ui->sizeOfRoom->setText("2-Queen");
        ui->typeOfRoom->setText("Standard");
    }
    else if (roomSize == 2 && roomView == 2)
    {
        ui->sizeOfRoom->setText("2-Queen");
        ui->typeOfRoom->setText("Atrium");
    }

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

void MainWindow::on_closeButton_clicked()
{
    QApplication::quit();
}

void MainWindow::on_visaButton_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit->setInputMask("4999-9999-9999-9999");
}

void MainWindow::on_masterButton_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit->setInputMask("5999-9999-9999-9999");
}

void MainWindow::on_discoverButton_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit->setInputMask("6999-9999-9999-9999");
}

void MainWindow::on_radioButton_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit->setInputMask("3999-999999-99999");
}
