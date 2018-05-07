#ifndef SMS_SINGLETON_H
#define SMS_SINGLETON_H

#include"sms.h"

class SMS_Singleton
{

    static SMS* mySystem;
public:
    SMS_Singleton();

    SMS* getMySystem();
};


#endif // SMS_SINGLETON_H
