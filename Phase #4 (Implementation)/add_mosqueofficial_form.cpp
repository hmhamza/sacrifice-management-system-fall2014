#include "add_mosqueofficial_form.h"
#include "ui_add_mosqueofficial_form.h"

//#include"_System.h"
#include"sms_singleton.h"

#include"person.h"

#include"admin.h"
#include"fdo.h"

#include<QMessageBox>

Add_MosqueOfficial_Form::Add_MosqueOfficial_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_MosqueOfficial_Form)
{
    ui->setupUi(this);

    this->setFixedSize(585,600);
}

Add_MosqueOfficial_Form::~Add_MosqueOfficial_Form()
{
    delete ui;
}

void Add_MosqueOfficial_Form::on_Submit_clicked()
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

     bool flag;
     if(ui->Admin->isChecked())
         flag=true;
     else if(ui->FDO->isChecked())
         flag=false;
     else{
         msgBox.setText("Please select one of the Roles");
         msgBox.exec();
         return;
     }

     QString Username=ui->Username->text();
      if(Username==""){
          msgBox.setText("Enter Username of the Mosque Official");
          msgBox.exec();
          return;
      }

      QString Password=ui->Password->text();
       if(Password==""){
           msgBox.setText("Enter Password of the Mosque Official");
           msgBox.exec();
           return;
       }

       QString Address=ui->Address->text();
       QString ContactNo=ui->ContactNo->text();

       Person *p;

       QString msg;
       if(flag){
           p=new Admin(Name,CNIC,Address,ContactNo,Username,Password);
           msgBox.setText("New Admin added Successfully");
       }
       else{
           p=new FDO(Name,CNIC,Address,ContactNo,Username,Password);
           msgBox.setText("New FDO added Successfully");
       }

       s.getMySystem()->AddAccount(p);

       msgBox.exec();

       this->close();
       delete this;



}
