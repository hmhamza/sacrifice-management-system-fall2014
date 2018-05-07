#ifndef BOOKING_H
#define BOOKING_H

#include"_DB.h"
#include"customer.h"

class Animal;

struct Date{

    int day;
    QString month;
    int year;

};

class Booking
{
    int bookingID;
    Customer *C;
    Animal *A;
    int NoOfShares;
    Date dateOfBooking;
    int meatLabel;
    bool isDelivered;
    Date dateOfDelivery;



public:
    Booking();

    Booking(int ID, int B_D, QString B_M, int B_Y, Animal *Ani, int Shares, Customer *Cust, int Label=0, bool flag=false, int D_D=0, QString D_M="", int D_Y=0);

    int getBookingID();
    Customer* getCustomer();

    Animal* getAnimal();

    int getNoOfShares();

    void setMeatLabel(int Label);

    void RecordDelivery(int Day,QString Month,int Year);

    bool getIsDelivered();

};

#endif // BOOKING_H
