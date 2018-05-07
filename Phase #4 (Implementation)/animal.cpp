#include "animal.h"

Animal::Animal(){


}

Animal::Animal( int I,QString N, int P, int D)
{
    ID=I;
    Name=N;
    Price=P;
    DayOfSacrifice=D;
}

int Animal::getID(){
    return ID;
}

void Animal::setID(int I){
    ID=I;
}


QString Animal::getName(){
    return Name;
}

int Animal::getDayOfSacrifice(){
    return DayOfSacrifice;
}

void Animal::setDayOfSacrifice(int I){
    DayOfSacrifice=I;
}

int Animal::getPrice(){
    return Price;
}

QString Animal::getType(){
    return "A";
}

int Animal::getNoOfSharesAvailable(){
   return -1;
}

int Animal::getNoOfBookings(){
    return 0;
}

Booking* Animal::getBooking(int i){
    return nullptr;
}
