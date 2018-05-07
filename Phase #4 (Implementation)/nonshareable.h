#ifndef NONSHAREABLE_H
#define NONSHAREABLE_H

#include"animal.h"

class NonShareable:public Animal
{

    Booking *B;
public:
    NonShareable();

    NonShareable( int,QString ,int ,   int);

    QString getType();

    bool isAvailable();

    int NonShareable::getNoOfSharesAvailable();

    void addBooking(int ID,int Day, QString Month, int Year, int Shares, Customer *C);

    Booking* getBooking(int i=0);

    void setBooking(Booking *Book);

};

#endif // NONSHAREABLE_H
