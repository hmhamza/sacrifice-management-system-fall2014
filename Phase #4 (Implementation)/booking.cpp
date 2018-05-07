#include "booking.h"
#include"animal.h"

Booking::Booking()
{
}

Booking::Booking(int ID,int B_D, QString B_M, int B_Y, Animal *Ani, int Shares, Customer *Cust,int Label,bool flag,int D_D, QString D_M, int D_Y){

    bookingID=ID;
    A=Ani;
    NoOfShares=Shares;
    C=Cust;
    dateOfBooking.day=B_D;
    dateOfBooking.month=B_M;
    dateOfBooking.year=B_Y;

    meatLabel=Label;
    isDelivered=flag;

    dateOfDelivery.day=D_D;
    dateOfDelivery.month=D_M;
    dateOfDelivery.year=D_Y;

    C->addBooking(this);

}

int Booking::getBookingID(){
    return bookingID;
}

Animal* Booking::getAnimal(){
    return A;
}

Customer* Booking::getCustomer(){
    return C;
}

int Booking::getNoOfShares(){
    return NoOfShares;
}

void Booking::setMeatLabel(int Label){
    meatLabel=Label;
}

void Booking::RecordDelivery(int Day, QString Month, int Year){
    isDelivered=true;
    dateOfDelivery.day=Day;
    dateOfDelivery.month=Month;
    dateOfDelivery.year=Year;
}

bool Booking::getIsDelivered(){
    return isDelivered;
}
