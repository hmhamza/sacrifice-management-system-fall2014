#include "sms_singleton.h"

SMS_Singleton::SMS_Singleton(){
}

SMS* SMS_Singleton::getMySystem(){

    if(mySystem==nullptr)
        mySystem=new SMS;

    return mySystem;
}

SMS* SMS_Singleton :: mySystem = nullptr;


