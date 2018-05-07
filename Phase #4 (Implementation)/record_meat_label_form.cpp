#include "record_meat_label_form.h"
#include "ui_record_meat_label_form.h"

#include"sms_singleton.h"
#include "animal.h"
#include "booking.h"

#include<QMessageBox>

Record_Meat_Label_Form::Record_Meat_Label_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Record_Meat_Label_Form)
{
    ui->setupUi(this);

     this->setFixedSize(570,400);

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

Record_Meat_Label_Form::~Record_Meat_Label_Form()
{
    delete ui;
}

void Record_Meat_Label_Form::on_List_currentTextChanged(const QString &arg1)
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
         ui->Meat_Label->show();

        ui->Animal->show();
        ui->Customer->show();
        ui->Shares->show();
        ui->MeatLabel->show();
    }
    else{
        ui->Animal_Label->hide();
        ui->Customer_Label->hide();
        ui->Shares_Label->hide();
        ui->Meat_Label->hide();

        ui->Animal->hide();
        ui->Customer->hide();
        ui->Shares->hide();
        ui->MeatLabel->hide();
    }

}

void Record_Meat_Label_Form::on_Submit_clicked()
{
    QMessageBox msgBox;

    if(ui->List->currentText()=="Booking ID"){
        msgBox.setText("Please select an ID");
        msgBox.exec();
        return;
    }
    int ID=ui->List->currentText().toInt();
    int Label=ui->MeatLabel->text().toInt();

    SMS_Singleton s;
    s.getMySystem()->Record_Meat_Label(ID,Label);


    msgBox.setText("Meat Label has been recorded Successfully");
    msgBox.exec();

    this->close();
    delete this;


}
