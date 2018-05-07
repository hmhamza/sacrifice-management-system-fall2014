#include "nonshareable.h"

NonShareable::NonShareable()
{
}

NonShareable::NonShareable( int I,QString N,int P,   int D):Animal( I,N,P, D){
        B=nullptr;
}

QString NonShareable::getType(){
    return "N";
}

bool NonShareable::isAvailable(){
    if(B==nullptr)
        return true;
    return false;
}

void NonShareable::addBooking(int ID,int Day,QString Month,int Year,int Shares,Customer *C){
    Booking *book=new Booking(ID,Day,Month,Year,this,Shares,C);
    B=book;
}

int NonShareable::getNoOfSharesAvailable(){
   return -1;
}

Booking* NonShareable::getBooking(int i){
    return B;
}

void NonShareable::setBooking(Booking *Book){
    B=Book;
}
