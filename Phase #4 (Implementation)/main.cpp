#include "login.h"
#include <QApplication>

//#include"mySystem.h"

#include "_DB.h"

//#include "_System.h"

#include "sms_singleton.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //SMS_Singleton s;

    //s.getMySystem()->PopulatePersons();
    //s.getMySystem()->PopulateAnimals();

    Login *w=new Login;
    w->show();

    return a.exec();
}
