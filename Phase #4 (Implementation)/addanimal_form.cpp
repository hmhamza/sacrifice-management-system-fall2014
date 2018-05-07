#include "addanimal_form.h"
#include "ui_addanimal_form.h"

//#include"_System.h"
#include"sms_singleton.h"
#include"animal.h"
#include"shareable.h"
#include"nonshareable.h"

#include<QMessageBox>

AddAnimal_Form::AddAnimal_Form(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddAnimal_Form)
{
    ui->setupUi(this);

    this->setFixedSize(505,435);
}

AddAnimal_Form::~AddAnimal_Form()
{
    delete ui;
}

void AddAnimal_Form::on_Submit_clicked()
{
    SMS_Singleton s;

    QMessageBox msgBox;

    QString Name=ui->Name->text();
     if(Name==""){
         msgBox.setText("Enter Name of the Animal");
         msgBox.exec();
         return;
     }

     bool flag;
     if(ui->YES->isChecked())
         flag=true;
     else if(ui->NO->isChecked())
         flag=false;
     else{
         msgBox.setText("Please Check one of the Shareable options");
         msgBox.exec();
         return;
     }

     QString Price=ui->Price->text();
     if(Price==""){
         msgBox.setText("Enter Price of the Animal");
         msgBox.exec();
         return;
     }

     QString Day=ui->DayOfSacrifice->currentText();

     int P=Price.toInt();
     int D;
     if(Day=="Not Decided")
         D=0;
     else if(Day=="First")
         D=1;
     else if(Day=="Second")
         D=2;
     else if(Day=="Third")
         D=3;

     Animal *newAnimal;

    if(flag){
        newAnimal=new Shareable(-1,Name,P,D);
        msgBox.setText("Shareable Animal added Successfully!!");
    }
    else if(!flag){
        newAnimal=new NonShareable(-1,Name,P,D);
        msgBox.setText("Non-Shareable Animal added Successfully!!");
    }

    s.getMySystem()->AddAnimal(newAnimal);
    msgBox.exec();
    this->close();
    delete this;
}
