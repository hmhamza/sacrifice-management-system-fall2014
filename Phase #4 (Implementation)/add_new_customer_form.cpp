#include "add_new_customer_form.h"
#include "ui_add_new_customer_form.h"

//#include"_System.h"
#include"sms_singleton.h"

#include"person.h"
#include"customer.h"
#include"booking_form.h"

#include<QMessageBox>

Add_New_Customer_Form::Add_New_Customer_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_New_Customer_Form)
{
    ui->setupUi(this);

    this->setFixedSize(500,415);

    ui->MakeBooking->hide();
}

Add_New_Customer_Form::~Add_New_Customer_Form()
{
    delete ui;
}

void Add_New_Customer_Form::on_Submit_clicked()
{
    SMS_Singleton s;
    QMessageBox msgBox;

    QString Name=ui->Name->text();
     if(Name==""){
         msgBox.setText("Enter Name of the Mosque Official");
         msgBox.exec();
         return;
     }

     QString CNIC=ui->CNIC->text();
      if(CNIC==""){
          msgBox.setText("Enter CNIC of the Mosque Official");
          msgBox.exec();
          return;
      }


      QString Address=ui->Address->text();
      QString ContactNo=ui->ContactNo->text();

      Person *p=new Customer(Name,CNIC,Address,ContactNo);
      s.getMySystem()->AddAccount(p);

      msgBox.setText("Customer Added Successfully");
      msgBox.exec();

      ui->MakeBooking->show();


}

void Add_New_Customer_Form::on_MakeBooking_clicked()
{
    Booking_Form *f=new Booking_Form;
    f->show();
}
