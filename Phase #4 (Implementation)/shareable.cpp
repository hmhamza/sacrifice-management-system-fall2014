#include "shareable.h"

Shareable::Shareable()
{
}

Shareable::Shareable(int I, QString N, int P,   int D, int X):Animal(I, N,P, D){
    NoOfSharesAvailable=X;

}

QString Shareable::getType(){
    return "S";
}

bool Shareable::isAvailable(){
    if(NoOfSharesAvailable==0)
        return false;

    return true;
}


void Shareable::addBooking(int B_ID,int Day,QString Month,int Year,int Shares,Customer *C){
    NoOfSharesAvailable-=Shares;
    QSqlQuery query;

   query.exec("update Shareable set No_Of_Shares="+QString::number(NoOfSharesAvailable)+" where Parent_ID="+QString::number(ID)+"");

    Booking *book=new Booking(B_ID,Day,Month,Year,this,Shares,C);
    B.push_back(book);
}

void Shareable::setBooking(Booking *Book){
   B.push_back(Book);
}

int Shareable::getNoOfSharesAvailable(){
    return NoOfSharesAvailable;

}

Booking* Shareable::getBooking(int i){
    return B.at(i);
}

int Shareable::getNoOfBookings(){
    return B.size();
}
