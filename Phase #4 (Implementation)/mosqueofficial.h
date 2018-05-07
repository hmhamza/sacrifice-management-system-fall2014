#ifndef MOSQUEOFFICIAL_H
#define MOSQUEOFFICIAL_H

#include"person.h"

class MosqueOfficial:public Person
{

protected:
    QString Username;
    QString Password;

public:
    MosqueOfficial();

    MosqueOfficial( QString ,QString ,  QString ,  QString,QString,QString );

    QString getType();

    QString getOfficialType();

    QString getUsername();

    QString getPassword();

};

#endif // MOSQUEOFFICIAL_H
