#include "dbHandler.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <QFileInfo>

dbHandler::dbHandler(const QString &dbPath) {
    QFileInfo dbFileInfo(dbPath);
    bool dbExists = dbFileInfo.exists();

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (!db.open()){
        std::cerr << "Error opening DB: " << db.lastError().text();
        return;
    }

    //if db exists initialize it
    if (!dbExists){
        std::cout << "DB NOT FOUND creating a new one" << std::endl;
        QFile schemaFile("resources/init.sql");
        if (!schemaFile.open(QIODevice::ReadOnly|QIODevice::Text)){
            std::cerr << "Error opening init.sql file\n";
            return;
        }

        QTextStream in(&schemaFile);
        QString schema = in.readAll();
        schemaFile.close();

        QSqlQuery query;
        if (!query.exec(schema)){
            std::cerr << "Error 3\n";
        } else {
            std::cerr << "DB init\n";
        }
    }
}

dbHandler::~dbHandler(){
    if (db.isOpen())
        db.close();
}

bool dbHandler::insertShift(const QString &location, const QString &startTime, const QString &endTime,int numEmployees, double amountEarned) {
    QSqlQuery query;
    query.prepare("INSERT INTO shifts (location, startTime, endTime, numEmployees, amountEarned) "
                  "VALUES (:location, :startTime, :endTime, :numEmployees, :amountEarned)");
    query.bindValue(":location", location);
    query.bindValue(":startTime", startTime);
    query.bindValue(":endTime", endTime);
    query.bindValue(":numEmployees", numEmployees);
    query.bindValue(":amountEarned", amountEarned);

    return query.exec();
}
void dbHandler::displayShifts() {
    QSqlQuery query("SELECT * FROM shifts");
    while (query.next()) {
        QString location = query.value("location").toString();
        QString startTime = query.value("startTime").toString();
        QString endTime = query.value("endTime").toString();
        int numEmployees = query.value("numEmployees").toInt();
        double amountEarned = query.value("amountEarned").toDouble();

        std::cout << "Location: " << location.toStdString()
                  << ", Start Time: " << startTime.toStdString()
                  << ", End Time: " << endTime.toStdString()
                  << ", Employees: " << numEmployees
                  << ", Amount Earned: " << amountEarned << std::endl;
    }
}
