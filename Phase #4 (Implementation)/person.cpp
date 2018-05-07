#include "person.h"

#include <iostream>
#include<QApplication>
#include<QDebug>
using namespace std;

Person::Person()
{
}

Person::Person(QString N, QString Cn, QString A, QString Co, char t)
{
    Name=N;
    CNIC=Cn;
    Address=A;
    ContactNo=Co;
    //type=t;
    //qDebug()<<"Person Constructor ' "<<t<<" '"<<endl;
}

QString Person::getName(){
    return Name;
}

void Person::setName(QString N){
    Name=N;
}

QString Person::getCNIC(){
    return CNIC;
}

void Person::setCNIC(QString C){
    CNIC=C;
}

QString Person::getAddress(){
    return Address;
}

void Person::setAddress(QString A){
    Address=A;
}

QString Person::getContactNo(){
    return ContactNo;
}

void Person::setContactNo(QString C){
    ContactNo=C;
}

QString Person::getOfficialType(){
    return "C";
}

QString Person::getUsername(){
    return "NULL";
}

void Person::setUsername(QString U){
    return;
}

QString Person::getPassword(){
    return "NULL";
}

void Person::setPassword(QString P){
    return;
}

void Person::ChangePassword(QString P){
    return;
}
