#include "booking_form.h"
#include "ui_booking_form.h"

#include"add_new_customer_form.h"

#include "sms_singleton.h"
#include"show_animal_list_form.h"

#include<QMessageBox>

Booking_Form::Booking_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Booking_Form)
{
    ui->setupUi(this);

    this->setFixedSize(610,570);

    SMS_Singleton s;

    QString str;

    str="Select ID";
    ui->Animal_ID->addItem(str);

    for(int i=0;i<s.getMySystem()->no_Of_Animals();i++){

        str=QString::number(s.getMySystem()->Animal_At(i)->getID());
        ui->Animal_ID->addItem(str);
    }



    str="Select CNIC";
    ui->Customer_CNIC->addItem(str);

    for(int i=0;i<s.getMySystem()->no_Of_Persons();i++){

        if(s.getMySystem()->Person_At(i)->getType()=="C")
            ui->Customer_CNIC->addItem(s.getMySystem()->Person_At(i)->getCNIC());
    }
}

Booking_Form::~Booking_Form()
{
    delete ui;
}

void Booking_Form::on_Animal_ID_currentTextChanged(const QString &arg1)
{
    int ID=arg1.toInt();

    SMS_Singleton s;
    Animal *A=s.getMySystem()->Search_Animal_by_ID(ID);



    if(A!=nullptr){
        ui->Name->setText(A->getName());

        ui->Price->setText(QString::number(A->getPrice()));


        ui->Name_Label->show();
        ui->Price_Label->show();


        ui->Name->show();
        ui->Price->show();

    }
    else{
        ui->Name_Label->hide();
        ui->Price_Label->hide();


        ui->Name->hide();
        ui->Price->hide();

    }


   if(A!=nullptr){
        QString S=A->getType();
        if(S=="S"){

            ui->No_Of_Shares->clear();
            QString str="Select";
            ui->No_Of_Shares->addItem(str);

            for(int i=1;i<=A->getNoOfSharesAvailable();i++){

               ui->No_Of_Shares->addItem(QString::number(i));
            }


            ui->NoOfShares_Label->show();
            ui->No_Of_Shares->show();
            ui->NoOfShares_Message->show();


        }
        else if(S=="N"){
            ui->NoOfShares_Label->hide();
            ui->No_Of_Shares->hide();
            ui->NoOfShares_Message->hide();


        }
    }
    else{
        ui->NoOfShares_Label->hide();
        ui->No_Of_Shares->hide();
        ui->NoOfShares_Message->hide();
    }

}

void Booking_Form::on_Chech_Availability_clicked()
{
    SMS_Singleton s;

    QMessageBox msgBox;
    if(ui->Animal_ID->currentText()=="Select ID"){
        msgBox.setText("Please select an Animal ID");
        msgBox.exec();
        return;
    }

    int ID=ui->Animal_ID->currentText().toInt();

    if(s.getMySystem()->CheckAnimalAvailability(ID)){
        msgBox.setText("YES!! Animal is Available");
        msgBox.exec();
    }
    else{
        msgBox.setText("NO!! Animal is not Available");
        msgBox.exec();
    }
}

void Booking_Form::on_Submit_clicked()
{

    QMessageBox msgBox;
    SMS_Singleton s;

    if(ui->Day->currentText()=="Day"){
        msgBox.setText("Please select a Day");
        msgBox.exec();
        return;
    }

    if(ui->Month->currentText()=="Month"){
        msgBox.setText("Please select a Month");
        msgBox.exec();
        return;
    }

    if(ui->Year->currentText()=="Year"){
        msgBox.setText("Please select a Year");
        msgBox.exec();
        return;
    }


    if(ui->Animal_ID->currentText()=="Select ID"){
        msgBox.setText("Please select an Animal to Book");
        msgBox.exec();
        return;
    }

    int ID=ui->Animal_ID->currentText().toInt();

    Animal *A=s.getMySystem()->Search_Animal_by_ID(ID);

    if(!A->isAvailable()){
        msgBox.setText("This Animal is not Available");
        msgBox.exec();
        return;
    }

    if(ui->Customer_CNIC->currentText()=="Select CNIC"){
        msgBox.setText("Please select a Customer to Book to");
        msgBox.exec();
        return;
    }

    int Day=ui->Day->currentText().toInt();
    QString Month=ui->Month->currentText();
    int Year=ui->Year->currentText().toInt();

    //int ID=ui->Animal_ID->currentText().toInt();

    int Shares=ui->No_Of_Shares->currentText().toInt();

    QString CNIC=ui->Customer_CNIC->currentText();

    s.getMySystem()->makeBooking(Day,Month,Year,ID,Shares,CNIC);

    msgBox.setText("Booking has been made Successfully!!");
    msgBox.exec();
    this->close();
    delete this;
}




void Booking_Form::on_ShowAnimalList_clicked()
{
    Show_Animal_List_Form *s=new Show_Animal_List_Form;
    s->show();
}

void Booking_Form::on_Customer_CNIC_currentTextChanged(const QString &arg1)
{
    SMS_Singleton s;
    Person *P=s.getMySystem()->Search_Person_by_CNIC(arg1);

    if(P!=nullptr){
        ui->Customer_Name->setText(P->getName());

        if(P->getContactNo()=="")
            ui->Customer_ContactNo->setText("<Empty>");
        else
            ui->Customer_ContactNo->setText(P->getContactNo());

        ui->Customer_Name_Label->show();
        ui->Customer_Contact_Number_Label->show();

        ui->Customer_Name->show();
        ui->Customer_ContactNo->show();
    }
    else{
        ui->Customer_Name_Label->hide();
        ui->Customer_Contact_Number_Label->hide();

        ui->Customer_Name->hide();
        ui->Customer_ContactNo->hide();

    }
}
