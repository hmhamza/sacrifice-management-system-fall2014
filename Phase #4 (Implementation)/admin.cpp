#include "admin.h"

Admin::Admin()
{
}

Admin::Admin( QString N,QString Cn,QString A,QString Co,QString U,QString P ):MosqueOfficial(N,Cn,A,Co,U,P){


}

QString Admin::getOfficialType(){
    return "A";
}

void Admin::setUsername(QString U){
    Username=U;
}

void Admin::setPassword(QString P){
    Password=P;
}


