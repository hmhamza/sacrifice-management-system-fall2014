#include "change_password_form.h"
#include "ui_change_password_form.h"

#include "sms_singleton.h"

#include <QMessageBox>

Change_Password_Form::Change_Password_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Change_Password_Form)
{
    ui->setupUi(this);

    this->setFixedSize(505,360);
}

Change_Password_Form::~Change_Password_Form()
{
    delete ui;
}

void Change_Password_Form::on_Submit_clicked()
{

    SMS_Singleton s;

    QMessageBox msgBox;

    Person *P=s.getMySystem()->getCurrent_Official();
    if(ui->Current->text()==""){
        msgBox.setText("Enter your Current Password");
        msgBox.exec();
        return;
    }
    else{

        if(P->getPassword()!=ui->Current->text()){
            msgBox.setText("You entered Incorrect Current Password");
            msgBox.exec();
            return;
        }
    }

    if(ui->New->text()==""){
        msgBox.setText("Enter New Password");
        msgBox.exec();
        return;
    }

    if(ui->Confirm->text()==""){
        msgBox.setText("Confirm Password");
        msgBox.exec();
        return;
    }

    if(ui->New->text()!=ui->Confirm->text()){
        msgBox.setText("Passwords don't Match");
        msgBox.exec();
        return;
    }

    P->ChangePassword(ui->New->text());
    msgBox.setText("Password has been changed Successfully");
    msgBox.exec();

    this->close();
    delete this;




}
