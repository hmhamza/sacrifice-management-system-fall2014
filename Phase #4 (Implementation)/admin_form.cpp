#include "admin_form.h"
#include "ui_admin_form.h"

#include"addanimal_form.h"
#include"booking_form.h"
#include "addaccount_options_form.h"

#include"remove_animals_list_form.h"
#include"remove_account_list_form.h"
#include"schedule_sacrifice_form.h"
#include"edit_account_form.h"
#include "record_meat_label_form.h"
#include"record_delivery.h"
#include"show_animal_list_form.h"
#include"change_password_form.h"
#include"login.h"
#include"booking_customer_options_form.h"

#include "sms_singleton.h"

#include<QMessageBox>

Admin_Form::Admin_Form(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin_Form)
{
    ui->setupUi(this);

    SMS_Singleton s;

    Person *P=s.getMySystem()->getCurrent_Official();

    ui->Name->setText(P->getName());
    ui->Username->setText(P->getUsername());

    if(P->getOfficialType()=="F"){
        this->setFixedSize(635,320);

        ui->ChangePassword->show();
        ui->FDO_Title->show();
        ui->Admin_Title->hide();

        ui->Add_Account->hide();
        ui->RemoveAccount->hide();
        ui->EditAccount->hide();


        ui->AddAnimal->hide();
        ui->RemoveAnimal->hide();
        ui->ScheduleSacrifice->hide();
    }
    else if(P->getOfficialType()=="A"){
        this->setFixedSize(635,420);

        ui->Admin_Title->show();
        ui->FDO_Title->hide();
        ui->ChangePassword->hide();

    }


}


Admin_Form::~Admin_Form()
{
    delete ui;
}

void Admin_Form::on_AddAnimal_clicked()
{
    AddAnimal_Form *w=new AddAnimal_Form;
    w->show();
}

void Admin_Form::on_Make_Booking_clicked()
{
    Booking_Customer_Options_Form *b=new Booking_Customer_Options_Form;
    b->show();

}

void Admin_Form::on_Add_Account_clicked()
{
    AddAccount_Options_Form *f=new AddAccount_Options_Form;
    f->show();

}

void Admin_Form::on_RemoveAnimal_clicked()
{
    Remove_Animals_List_Form *r=new Remove_Animals_List_Form;
    r->show();
}

void Admin_Form::on_RemoveAccount_clicked()
{
    Remove_Account_List_Form *r=new Remove_Account_List_Form;
    r->show();
}

void Admin_Form::on_ScheduleSacrifice_clicked()
{
    Schedule_Sacrifice_Form *s=new Schedule_Sacrifice_Form;
    s->show();
}

void Admin_Form::on_EditAccount_clicked()
{
    Edit_Account_Form *e=new Edit_Account_Form;
    e->show();
}

void Admin_Form::on_RecordMeatLabel_clicked()
{
    Record_Meat_Label_Form *r=new Record_Meat_Label_Form;
    r->show();
}

void Admin_Form::on_RecordDelivery_clicked()
{
    Record_Delivery *r=new Record_Delivery;
    r->show();
}

void Admin_Form::on_ChangePassword_clicked()
{
    Change_Password_Form *c=new Change_Password_Form;
    c->show();

}

void Admin_Form::on_Logout_clicked()
{
    this->close();
    delete this;

    SMS_Singleton s;
    s.getMySystem()->LogOut();

    QMessageBox msgBox;

    msgBox.setText("You have Successfully been Logged Out");
    msgBox.exec();

    Login *l=new Login;
    l->show();

}
