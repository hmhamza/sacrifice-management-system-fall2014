#include "fdo.h"

FDO::FDO()
{
}


FDO::FDO( QString N,QString Cn,QString A,QString Co,QString U,QString P ):MosqueOfficial(N,Cn,A,Co,U,P){


}

QString FDO::getOfficialType(){
    return "F";
}

void FDO::ChangePassword(QString P){
    Password=P;

    QSqlQuery query;
    query.exec("update Mosque_Official set Password='"+Password+"' where Parent_CNIC='"+CNIC+"'");
}
