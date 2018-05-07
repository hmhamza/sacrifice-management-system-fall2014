#include "record_delivery.h"
#include "ui_record_delivery.h"

#include"sms_singleton.h"
#include"booking.h"

#include<QMessageBox>

Record_Delivery::Record_Delivery(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Record_Delivery)
{
    ui->setupUi(this);

     this->setFixedSize(570,420);

    Booking *B;
    SMS_Singleton s;

    QString str;

    str="Booking ID";
    ui->List->addItem(str);

    for(int i=0;i<s.getMySystem()->no_Of_Animals();i++){

        Animal *A=s.getMySystem()->Animal_At(i);
        if(A->getType()=="N"){
            B=A->getBooking();
            if(B!=nullptr)
                ui->List->addItem(QString::number(B->getBookingID()));
            else;
            //ui->List->addItem("NULL");
        }

        else if(A->getType()=="S"){
            for(int i=0;i<A->getNoOfBookings();i++){
                B=A->getBooking(i);
                if(B!=nullptr)
                    ui->List->addItem(QString::number(B->getBookingID()));
                else;
                //ui->List->addItem("NULL");
            }
        }
    }
}

Record_Delivery::~Record_Delivery()
{
    delete ui;
}

void Record_Delivery::on_List_currentTextChanged(const QString &arg1)
{
    int ID=arg1.toInt();

    SMS_Singleton s;
    Booking *B=s.getMySystem()->Search_Booking(ID);

    if(B!=nullptr){
        ui->Animal->setText(B->getAnimal()->getName());

        ui->Customer->setText(B->getCustomer()->getName());

        if(B->getNoOfShares()==0)
            ui->Shares->setText("---");
        else
            ui->Shares->setText(QString::number(B->getNoOfShares()));

        ui->Animal_Label->show();
        ui->Customer_Label->show();
        ui->Shares_Label->show();

        ui->Animal->show();
        ui->Customer->show();
        ui->Shares->show();
    }
    else{
        ui->Animal_Label->hide();
        ui->Customer_Label->hide();
        ui->Shares_Label->hide();

        ui->Animal->hide();
        ui->Customer->hide();
        ui->Shares->hide();
    }
}

void Record_Delivery::on_Submit_clicked()
{
    QMessageBox msgBox;


    SMS_Singleton s;

    if(ui->List->currentText()=="Booking ID"){
        msgBox.setText("Please select an ID");
        msgBox.exec();
        return;
    }

    int ID=ui->List->currentText().toInt();
    Booking *B=s.getMySystem()->Search_Booking(ID);


    if(B->getIsDelivered()){
        msgBox.setText("This Booking has already been delivered");
        msgBox.exec();
        return;
    }

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

    int Day=ui->Day->currentText().toInt();
    QString Month=ui->Month->currentText();
    int Year=ui->Year->currentText().toInt();

    //SMS_Singleton s;
    s.getMySystem()->Record_Delivery(ID,Day,Month,Year);

    msgBox.setText("Delivery has been recorded Successfully");
    msgBox.exec();

    this->close();
    delete this;
}
