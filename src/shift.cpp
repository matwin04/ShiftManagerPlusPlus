#include "shift.h"



Shift::Shift(const QString &location, const QString &startTime, const QString &endTime, int numEmployees, double amountEarned)
    : location(location), startTime(startTime), endTime(endTime),numEmployees(numEmployees), amountEarned(amountEarned) {}

QString Shift::getLocation() const {
    return location;
}

QString Shift::getStartTime() const {
    return startTime;
}

QString Shift::getEndTime() const{
    return endTime;
}

int Shift::getNumEmployees() const {
    return numEmployees;
}

double Shift::getAmountEarned() const {
    return amountEarned;
}
