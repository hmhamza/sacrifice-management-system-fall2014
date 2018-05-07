#include "mydal.h"

myDAL::myDAL()
{
    QSqlDatabase DB;
    DB= QSqlDatabase::addDatabase("QODBC");
    DB.setHostName("HAZA");
    DB.setDatabaseName("SMS");

    if(!DB.open()){
        //qDebug("Error");
    }
    else{
        //qDebug("Connected");
    }

}

