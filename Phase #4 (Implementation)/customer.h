#ifndef CUSTOMER_H
#define CUSTOMER_H

#include"person.h"
#include<vector>

using namespace std;

class Booking;

class Customer:public Person
{

    vector<Booking*> Bookings;


public:
    Customer();

    Customer( QString ,QString ,  QString ,  QString );

    QString getType();

    void addBooking(Booking *B);
};

#endif // CUSTOMER_H
