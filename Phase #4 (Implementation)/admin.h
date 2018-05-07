#ifndef ADMIN_H
#define ADMIN_H

#include"mosqueofficial.h"

class Admin:public MosqueOfficial
{

public:
    Admin();

    Admin( QString ,QString ,  QString ,  QString,QString,QString );

    void setUsername(QString U);

    void setPassword(QString P);

    QString getOfficialType();
};

#endif // ADMIN_H
