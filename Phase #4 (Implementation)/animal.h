#ifndef ANIMAL_H
#define ANIMAL_H

#include<QApplication>

#include"booking.h"

class Animal
{
protected:
    int ID;
    QString Name;
    int Price;
    int DayOfSacrifice;
    //char Type;


public:
    Animal();

    Animal(int,QString,int ,   int);

    int getID();

    void setID(int);

    QString getName();

    int getPrice();

    int getDayOfSacrifice();

    void setDayOfSacrifice(int);

    virtual QString getType();

    virtual int getNoOfSharesAvailable();

    virtual bool isAvailable()=0;

    virtual void addBooking(int ID,int Day,QString Month,int Year,int Shares,Customer *C)=0;

    virtual Booking* getBooking(int i=0);

    virtual void setBooking(Booking *Book)=0;

    virtual int getNoOfBookings();
};

#endif // ANIMAL_H
