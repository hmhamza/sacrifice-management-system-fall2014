#ifndef FDO_H
#define FDO_H

#include"_DB.h"
#include"mosqueofficial.h"

class FDO:public MosqueOfficial
{
public:
    FDO();

    FDO( QString ,QString ,  QString ,  QString ,QString ,QString );

    QString getOfficialType();

    void ChangePassword(QString P);
};

#endif // FDO_H
