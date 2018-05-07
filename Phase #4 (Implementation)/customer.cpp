#include "customer.h"

Customer::Customer()
{
}

Customer::Customer( QString N,QString Cn,QString A,QString Co ):Person(N,Cn,A,Co,'C'){


}

QString Customer::getType(){
    return "C";
}

void Customer::addBooking(Booking *B){
    Bookings.push_back(B);
}
