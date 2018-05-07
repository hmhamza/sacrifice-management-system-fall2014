#ifndef SMS_H
#define SMS_H

#include<QtSql/QSql>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlError>
#include<QtCore>

#include<vector>

#include "person.h"
#include "animal.h"
#include "list.h"

using namespace std;
class SMS
{

    //List<Person*> Persons;
    //List<Animal*> Animals;

    vector<Person*> Persons;
    vector<Animal*> Animals;

    Person *current_Official;

public:
    SMS();

    int no_Of_Persons();

    int no_Of_Animals();

    Person* Person_At(int);

    Animal* Animal_At(int);

    Person* Search_Person_by_CNIC(QString);

    Person *Search_Customer_by_CNIC(QString C);

    Animal* Search_Animal_by_ID(int);

    void EditAccount(QString C, QString Name, QString CNIC, QString Address, QString ContactNo, QString Username, QString Password,QString Type);

    void AddAccount(Person*);

    void AddAnimal(Animal*);

    void RemoveAccount(QString,QString);

    void RemoveAnimal(QString);

    void PopulatePersons();

    void PopulateAnimals();

    int Login(QString,QString);

    void LogOut();

    void ScheduleSacrifice(QString,QString);

    bool CheckAnimalAvailability(int ID);

    void makeBooking(int Day, QString Month, int Year, int ID, int Shares, QString CNIC);

    Booking* Search_Booking(int ID);

    void Record_Meat_Label(int ID,int Label);

    void Record_Delivery(int ID,int Day,QString Month,int Year);

    Person* getCurrent_Official();

};

#endif // SMS_H
