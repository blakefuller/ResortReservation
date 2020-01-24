#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ReservationRecord.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_nextPage_clicked();

    void on_nextPage_2_clicked();

    void on_lastPage_clicked();

    void on_lastPage_2_clicked();

    void on_nameInput_textChanged();

    void on_numChild_valueChanged(int arg1);

    void on_roomView_currentIndexChanged(int index);

    void on_roomSize_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    ReservationRecord Record;
};
#endif // MAINWINDOW_H
