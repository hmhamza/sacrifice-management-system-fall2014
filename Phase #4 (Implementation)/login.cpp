#include "login.h"
#include "ui_login.h"

#include <QMessageBox>

#include "admin_form.h"

#include"_DB.h"
//#include"_System.h"

#include"sms_singleton.h"

using namespace std;

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setFixedSize(500,500);

    QLineEdit::EchoMode PasswordMode = QLineEdit::Password;
    ui->Password->setEchoMode(PasswordMode);

    SMS_Singleton s;

    s.getMySystem()->PopulatePersons();
    s.getMySystem()->PopulateAnimals();
}

Login::~Login()
{
    delete ui;
}

void Login::on_Submit_clicked()
{
    QMessageBox msgBox;

    QString Username=ui->Username->text();
    if(Username==""){
        msgBox.setText("Enter Username");
        msgBox.exec();
        return;
    }
    QString Password=ui->Password->text();
    if(Password==""){
        msgBox.setText("Enter Password");
        msgBox.exec();
        return;
    }

    SMS_Singleton s;
    int status = s.getMySystem()->Login(Username,Password);


    if(status==1){

        msgBox.setText("Successfully Logged-In");
        msgBox.exec();
        this->close();
        delete this;

        Admin_Form *admin=new Admin_Form;
        admin->show();
    }

    else if(status==2){
        QMessageBox msgBox;
        msgBox.setText("Incorrect Password");
        msgBox.exec();
    }

    else if(status==3){
        QMessageBox msgBox;
        msgBox.setText("Username not found");
        msgBox.exec();

    }
}
