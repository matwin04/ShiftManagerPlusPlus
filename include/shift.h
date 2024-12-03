#ifndef SHIFT_H
#define SHIFT_H
#include <QString>
class Shift
{
public:
    Shift(const QString &location, const QString &startTime, const QString &endTime,
        int numEmployees, double amountEarned);
    //Getter functions for shift details
    QString getLocation() const;
    QString getStartTime() const;
    QString getEndTime() const;
    int getNumEmployees() const;
    double getAmountEarned() const;
private:
    QString location;       // Shift location
    QString startTime;      // Start time
    QString endTime;        // End time
    int numEmployees;       // Number of employees
    double amountEarned;    // Amount Earned
};

#endif // SHIFT_H
