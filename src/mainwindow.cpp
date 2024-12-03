#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
const double WAGE_PER_HOUR = 18.0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), database(new dbHandler("database/smpp.db")) {
    ui->setupUi(this); // Set up the UI defined in the .ui file
}

//Destructor
MainWindow::~MainWindow(){
    delete ui;
    delete database;
}

//Slot for handling "add shift"
void MainWindow::on_addShiftBtn(){
    QString location = ui->locationEdit->text();
    QString startTimeStr = ui->startTimeEdit->text();
    QString endTimeStr = ui->endTimeEdit->text();
    int numEmployees = ui->employeeSpinBox->value();

    QTime startTime = QTime::fromString(startTimeStr, "hh:mm");
    QTime endTime = QTime::fromString(endTimeStr, "hh:mm");

    if (!startTime.isValid()||!endTime.isValid()){
        ui->statusLabel->setText("Invalid time format");
        return;
    }

    int minWorked = startTime.secsTo(endTime)/60;
    if (minWorked<0){
        minWorked += 24 * 60;
    }
    double hoursWorked = minWorked / 60.0;
    double amountEarned = hoursWorked * WAGE_PER_HOUR;

    if (database->insertShift(location,startTimeStr,endTimeStr,numEmployees,amountEarned)){
        ui->statusLabel->setText("Shift Added Successfully");
    } else {
        ui->statusLabel->setText("Failed to add shift to database");
    }
}
