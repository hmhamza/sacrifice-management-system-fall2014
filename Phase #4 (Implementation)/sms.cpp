#include "sms.h"

#include "_DB.h"

#include"person.h"
#include"mosqueofficial.h"
#include"admin.h"
#include"fdo.h"
#include"customer.h"

#include"shareable.h"
#include"nonshareable.h"
#include"booking.h"


SMS::SMS(){
    //qDebug()<<"SMS constructor called\n\n";
}

int SMS::no_Of_Persons(){
    return Persons.size();
}

int SMS::no_Of_Animals(){
    return Animals.size();
}

Person* SMS::Person_At(int i){
    return Persons.at(i);
}

Animal* SMS::Animal_At(int i){
    return Animals.at(i);
}

Animal* SMS::Search_Animal_by_ID(int id){
    for(int i=0;i<Animals.size();i++){
        //qDebug()<<i<<endl;
        if(Animals.at(i)->getID()==id){
            return Animals.at(i);
            //qDebug()<<Animals.at(i)->getPrice()<<endl;
        }
    }

    return nullptr;
}

Person* SMS::Search_Person_by_CNIC(QString C){
    for(int i=0;i<Persons.size();i++){
        if(Persons.at(i)->getCNIC()==C)
            return Persons.at(i);

    }

    return nullptr;
}

void SMS::AddAccount(Person *P){

    Persons.push_back(P);

    QSqlQuery query;

    query.prepare("exec InsertPerson @Name=? , @CNIC=?,@Address= ?,@ContactNO=?,@Username=?,@Password=?,@P_Type=?,@M_Type =?");

    query.bindValue(0,  P->getName());
    query.bindValue(1,  P->getCNIC());
    query.bindValue(2,  P->getAddress());
    query.bindValue(3,  P->getContactNo());
    query.bindValue(4,  P->getUsername());
    query.bindValue(5,  P->getPassword());
    query.bindValue(6,  P->getType());

    query.bindValue(7,  P->getOfficialType());

    query.exec();

}

void SMS::AddAnimal(Animal *A){

    Animals.push_back(A);

    QSqlQuery query;

    query.prepare("declare @i int;   exec InsertAnimal @Name=? , @Day=?,@Price = ?,@Type=?,@ID= ? output");
    query.bindValue(0, A->getName());
    query.bindValue(1,  A->getDayOfSacrifice());
    query.bindValue(2,  A->getPrice());
    query.bindValue(3,  A->getType());
    query.bindValue(4, 0,QSql::Out);

    query.exec();

    int I=query.boundValue(4).toInt();
    A->setID(I);
    //qDebug()<<"ID: "<<I<<endl;

}

void SMS::RemoveAnimal(QString ID){
    QSqlQuery query;

    query.exec("delete from Animal where ID="+ID+"");

    for(int i=0;i<Animals.size();i++)
        if(Animals.at(i)->getID()==ID.toInt()){
            delete Animals.at(i);
            Animals.erase(Animals.begin()+i);
            return;
        }
}

void SMS::RemoveAccount(QString CNIC,QString Type){
    QSqlQuery query;

    if(Type=="Mosque Official")
        query.exec("delete from Mosque_Official where Parent_CNIC='"+CNIC+"'");

    query.exec("delete from Person where CNIC='"+CNIC+"'");

    for(int i=0;i<Persons.size();i++)
        if(Persons.at(i)->getCNIC()==CNIC){
            delete Persons.at(i);
            Persons.erase(Persons.begin()+i);
            return;
        }
}

void SMS::PopulatePersons(){

    Person *p;
    QString Name, CNIC, Address, ContactNo, Username,  Password,type,M_type;
    QSqlQuery query;

    query.exec("select * from [SMS].[dbo].[Person]");


    while(query.next()){

        Name=query.value(0).toString();
        //qDebug()<<"Name:"<<Name;

        CNIC=query.value(1).toString();
        //qDebug()<<"CNIC:"<<CNIC;

        Address=query.value(2).toString();
        //qDebug()<<"Address:"<<Address;

        ContactNo=query.value(3).toString();
        //qDebug()<<"ContactNo:"<<ContactNo;

        type=query.value(4).toString();
        //qDebug()<<"type:"<<type;
        if(type=="C"){

            p=new Customer(Name,CNIC,Address,ContactNo);
        }
        else if(type=="M"){
            QSqlQuery query1;

            query1.exec("select * from [SMS].[dbo].[Mosque_Official] where Parent_CNIC='"+CNIC+"'");

            while(query1.next()){
                Username=query1.value(0).toString();
                //qDebug()<<"Username:"<<Username;

                Password=query1.value(1).toString();
                //qDebug()<<"Password:"<<Password;

                M_type=query1.value(3).toString();
                //qDebug()<<"Official:"<<M_type;
            }

            if(M_type=="A"){

                p=new Admin(Name,CNIC,Address,ContactNo,Username,Password);
            }
            else if(M_type=="F"){
                p=new FDO(Name,CNIC,Address,ContactNo,Username,Password);
            }

        }

        Persons.push_back(p);

    }
}

void SMS::PopulateAnimals(){

    Animal *a;
    QString Name,type,CNIC,B_Month,D_Month;
    int ID,Day,Price,Shares,B_ID,B_Shares,B_Day,B_Year,Label,D_Day,D_Year;
    bool flag;

    Booking *B;

    QSqlQuery query,X,Y;

    query.exec("select * from [SMS].[dbo].[Animal]");


    while(query.next()){

        ID=query.value(0).toInt();
        Name=query.value(1).toString();
        Day=query.value(2).toInt();
        Price=query.value(3).toInt();
        type=query.value(4).toString();

        if(type=="S"){

            X.exec("select No_Of_Shares from Shareable where Parent_ID="+QString::number(ID)+"");

            while(X.next()){
                Shares=X.value(0).toInt();
            }


            a=new Shareable(ID,Name,Price,Day,Shares);
        }
        else if(type=="N"){
            a=new NonShareable(ID,Name,Price,Day);
        }

        Animals.push_back(a);

        Y.exec("select * from Booking where Animal_ID='"+QString::number(ID)+"'");

        while(Y.next()){
            B_ID=Y.value(0).toInt();
            CNIC=Y.value(1).toString();
            //Animal ID
            B_Shares=Y.value(3).toInt();
            B_Day=Y.value(4).toInt();
            B_Month=Y.value(5).toString();
            B_Year=Y.value(6).toInt();
            Label=Y.value(7).toInt();
            flag=Y.value(8).toBool();
            D_Day=Y.value(9).toInt();
            D_Month=Y.value(10).toString();
            D_Year=Y.value(11).toInt();

            Person *P=Search_Person_by_CNIC(CNIC);

             Customer *C;

             C=(Customer*) P;
            //Customer *C=(Customer*) (static_cast<Customer*>(P));

            B=new Booking( B_ID,B_Day,B_Month,B_Year,a,B_Shares,C,Label,flag,D_Day,D_Month,D_Year);

            a->setBooking(B);


        }



    }

}

int SMS::Login(QString U,QString P){


    for(int i=0;i<Persons.size();i++){

        Person* p=Persons.at(i);

        if(Persons.at(i)->getUsername()==U && Persons.at(i)->getPassword()==P ){
            current_Official=p;
            return 1;

        }
        else if(Persons.at(i)->getUsername()==U && Persons.at(i)->getPassword()!=P ){
            return 2;
        }
    }
    return 3;
}

void SMS::LogOut(){
      current_Official=nullptr;

      for(int i=0;i<Persons.size();i++){
          delete Persons.at(i);
          Persons.erase(Persons.begin()+i);
      }

      for(int i=0;i<Animals.size();i++){
          delete Animals.at(i);
          Animals.erase(Animals.begin()+i);
      }
}


void SMS::ScheduleSacrifice(QString ID,QString Day){

    QSqlQuery query;

    QString str="update Animal set DayOfSacrifice="+Day+" where ID="+ID+"";
    query.exec(str);


    for(int i=0;i<Animals.size();i++)
        if(Animals.at(i)->getID()==ID.toInt()){
            Animals.at(i)->setDayOfSacrifice(Day.toInt());
            return;
        }
}

void SMS::EditAccount(QString C, QString Name, QString CNIC, QString Address, QString ContactNo, QString Username, QString Password,QString Type){

    QSqlQuery query;

    Person *P=Search_Person_by_CNIC(C);

    if(Name!=""){
        P->setName(Name);
        query.exec("update Person set Name='"+Name+"' where CNIC='"+C+"'");
    }

    if(CNIC!=""){
        P->setCNIC(CNIC);
        query.exec("update Person set CNIC='"+CNIC+"' where CNIC='"+C+"'");
    }

    if(Address!=""){
        P->setAddress(Address);
        query.exec("update Person set Address='"+Address+"' where CNIC='"+C+"'");
    }

    if(ContactNo!=""){
        P->setContactNo(ContactNo);
        query.exec("update Person set ContactNo='"+ContactNo+"' where CNIC='"+C+"'");
    }

    if(Type=="Mosque Official"){
        if(Username!=""){
            P->setUsername(Username);
            query.exec("update Mosque_Official set Username='"+Username+"' where Parent_CNIC='"+C+"'");
        }

        if(Password!=""){
            P->setPassword(Password);
            query.exec("update Mosque_Official set Password='"+Password+"' where Parent_CNIC='"+C+"'");

        }
    }



}

bool SMS::CheckAnimalAvailability(int ID){
    Animal* A=Search_Animal_by_ID(ID);

    return A->isAvailable();
}

void SMS::makeBooking(int Day,QString Month,int Year,int ID,int Shares,QString CNIC){

    QSqlQuery query;

    query.prepare("declare @i int;   exec InsertBooking @Cust_CNIC=? , @Ani_ID=?,@Shares = ?,@Day=?,@Month=?,@Year=?,@ID= ? output");
    query.bindValue(0, CNIC);
    query.bindValue(1,  ID);
    query.bindValue(2,  Shares);
    query.bindValue(3, Day);
    query.bindValue(4, Month);
    query.bindValue(5, Year);
    query.bindValue(6, 0,QSql::Out);

    query.exec();

    int I=query.boundValue(6).toInt();

    Animal *A=Search_Animal_by_ID(ID);
    Person *P=Search_Person_by_CNIC(CNIC);

    Customer *C=(Customer*) (static_cast<Customer*>(P));
    A->addBooking(I,Day,Month,Year,Shares,C);

}

Booking* SMS::Search_Booking(int ID){


    Animal *A;
    for(int i=0;i<Animals.size();i++){
        A=Animals.at(i);
        if(A->getType()=="N" && A->getBooking()!=nullptr && A->getBooking()->getBookingID()==ID){

            return A->getBooking();
        }
        else if(A->getType()=="S"){

                for(int j=0;j<A->getNoOfBookings();j++)
                    if(A->getBooking(j)->getBookingID()==ID)
                        return A->getBooking(j);
        }

    }

    return nullptr;
}

void SMS::Record_Meat_Label(int ID, int Label){

    QSqlQuery query;
    query.exec("update Booking set MeatLabel="+QString::number(Label)+" where BookingID="+QString::number(ID));

    Booking *B=Search_Booking(ID);

    if(B!=nullptr)
        B->setMeatLabel(Label);



}

void SMS::Record_Delivery(int ID, int Day, QString Month, int Year){

    QSqlQuery query;
    query.exec("update Booking set isDelivered=1, Delivery_Day="+QString::number(Day)+",Delivery_Month='"+Month+"',Delivery_Year="+QString::number(Year)+" where BookingID="+QString::number(ID));

    Booking *B=Search_Booking(ID);

    if(B!=nullptr){

    }
}

Person* SMS::getCurrent_Official(){
    return current_Official;
}
