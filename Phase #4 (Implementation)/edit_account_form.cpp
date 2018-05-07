#include "edit_account_form.h"
#include "ui_edit_account_form.h"

#include"sms_singleton.h"

#include<QMessageBox>

Edit_Account_Form::Edit_Account_Form(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Edit_Account_Form)
{
    ui->setupUi(this);
    this->setFixedSize(680,670);

    SMS_Singleton s;

    QString str;

    str="Select CNIC";
    ui->List->addItem(str);

    for(int i=0;i<s.getMySystem()->no_Of_Persons();i++){

        ui->List->addItem(s.getMySystem()->Person_At(i)->getCNIC());
    }
}

Edit_Account_Form::~Edit_Account_Form()
{
    delete ui;
}

void Edit_Account_Form::on_List_currentTextChanged(const QString &arg1)
{
    SMS_Singleton s;
    Person *P=s.getMySystem()->Search_Person_by_CNIC(arg1);

    if(P!=nullptr){
        ui->Name->setText(P->getName());

        if(P->getAddress()=="")
            ui->Address->setText("<Empty>");
        else
            ui->Address->setText(P->getAddress());

        if(P->getContactNo()=="")
            ui->ContactNo->setText("<Empty>");
        else
            ui->ContactNo->setText(P->getContactNo());

        if(P->getType()=="M")
            ui->Account_Type->setText("Mosque Official");
        else if(P->getType()=="C")
            ui->Account_Type->setText("Customer");

        ui->Name_Label->show();
        ui->Address_Label->show();
        ui->ContactNo_Label->show();
        ui->Account_Type_Label->show();

        ui->New_Name_Label->show();
        ui->New_CNIC_Label->show();
        ui->New_Address_Label->show();
        ui->New_ContactNo_Label->show();




        ui->Name->show();
        ui->Address->show();
        ui->ContactNo->show();
        ui->Account_Type->show();

        ui->getName->show();
        ui->getCNIC->show();
        ui->getAddress->show();
        ui->getContactNo->show();


        if(P->getType()=="M"){
            ui->Username_Label->show();
            ui->Password_Label->show();
            ui->Username->setText(P->getUsername());
            ui->Password->setText(P->getPassword());
            ui->Username->show();
            ui->Password->show();

            ui->New_Username_Label->show();
            ui->New_Password_Label->show();
            ui->getUsername->show();
            ui->getPassword->show();
        }
        else if(P->getType()=="C"){
            ui->Username_Label->hide();
            ui->Password_Label->hide();
            ui->Username->hide();
            ui->Password->hide();

            ui->New_Username_Label->hide();
            ui->New_Password_Label->hide();
            ui->getUsername->hide();
            ui->getPassword->hide();
        }

    }
    else{
        ui->Name_Label->hide();
        ui->Address_Label->hide();
        ui->ContactNo_Label->hide();
        ui->Account_Type_Label->hide();
        ui->Username_Label->hide();
        ui->Password_Label->hide();

        ui->New_Name_Label->hide();
        ui->New_CNIC_Label->hide();
        ui->New_Address_Label->hide();
        ui->New_ContactNo_Label->hide();
        ui->New_Username_Label->hide();
        ui->New_Password_Label->hide();



        ui->Name->hide();
        ui->Address->hide();
        ui->ContactNo->hide();
        ui->Account_Type->hide();
        ui->Username->hide();
        ui->Password->hide();

        ui->getName->hide();
        ui->getCNIC->hide();
        ui->getAddress->hide();
        ui->getContactNo->hide();
        ui->getUsername->hide();
        ui->getPassword->hide();
    }
}

void Edit_Account_Form::on_Submit_clicked()
{
    QMessageBox msgBox;

    if(ui->List->currentText()=="Select CNIC"){
        msgBox.setText("Please select a CNIC");
        msgBox.exec();
        return;
    }

    SMS_Singleton s;
    s.getMySystem()->EditAccount(ui->List->currentText(),ui->getName->text(),ui->getCNIC->text(),ui->getAddress->text(),ui->getContactNo->text(),ui->getUsername->text(),ui->getPassword->text(),ui->Account_Type->text());

    msgBox.setText("Updation performed successfully");
    msgBox.exec();

    this->close();
    delete this;
}
