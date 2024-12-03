#ifndef DBHANDLER_H
#define DBHANDLER_H
#include <QString>
#include <QtSql/QSqlDatabase>
class dbHandler
{
public:
    //Constructor
    dbHandler(const QString &dbHandler);
    ~dbHandler();

    bool insertShift(const QString &location, const QString &startTime, const QString &endTime,
                    int numEmployees, double amountEarned);
    void displayShifts();
private:
    QSqlDatabase db;
};

#endif // DBHANDLER_H
