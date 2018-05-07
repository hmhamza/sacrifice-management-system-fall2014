#ifndef SHAREABLE_H
#define SHAREABLE_H

#include "animal.h"
#include <vector>

using namespace std;

class Shareable:public Animal
{
    vector <Booking*> B;

    int NoOfSharesAvailable;
public:
    Shareable();

    Shareable(int, QString, int ,   int, int X=7);

    QString getType();

    bool isAvailable();

    int getNoOfSharesAvailable();

    void addBooking(int ID,int Day, QString Month, int Year, int Shares, Customer *C);

    int getNoOfBookings();

    Booking* getBooking(int i);

    void setBooking(Booking *Book);

};

#endif // SHAREABLE_H
