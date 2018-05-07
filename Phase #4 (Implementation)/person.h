#ifndef PERSON_H
#define PERSON_H

#include<QApplication>

class Person
{
protected:
    QString Name;
    QString CNIC;
    QString Address;
    QString ContactNo;
    //char type;

public:
    Person();

    Person(QString ,QString ,QString ,QString,char );

    QString getName();

    void setName(QString);

    QString getCNIC();

    void setCNIC(QString);

    QString getAddress();

    void setAddress(QString);

    QString getContactNo();

    void setContactNo(QString);

    virtual QString getUsername();

    virtual void setUsername(QString);

    virtual QString getPassword();

    virtual void setPassword(QString);

    virtual void ChangePassword(QString);

    virtual QString getType()=0;

    virtual QString getOfficialType();


};

#endif // PERSON_H
