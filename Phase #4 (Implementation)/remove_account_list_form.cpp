#include "remove_account_list_form.h"
#include "ui_remove_account_list_form.h"

#include "sms_singleton.h"

#include <QMessageBox>

Remove_Account_List_Form::Remove_Account_List_Form(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Remove_Account_List_Form)
{
    ui->setupUi(this);

    this->setFixedSize(680,415);

    SMS_Singleton s;

    QString str;

    str="Select CNIC";
    ui->List->addItem(str);

    for(int i=0;i<s.getMySystem()->no_Of_Persons();i++){

        //str=QString::number(s.getMySystem()->Person_At(i)->getCNIC());
        //qDebug()<<str<<endl;
        if(s.getMySystem()->Person_At(i)!=s.getMySystem()->getCurrent_Official())
           ui->List->addItem(s.getMySystem()->Person_At(i)->getCNIC());
    }
}

Remove_Account_List_Form::~Remove_Account_List_Form()
{
    delete ui;
}

void Remove_Account_List_Form::on_Submit_clicked()
{

    QMessageBox msgBox;

    if(ui->List->currentText()=="Select CNIC"){
        msgBox.setText("Please select a CNIC");
        msgBox.exec();
        return;
    }

    SMS_Singleton s;
    s.getMySystem()->RemoveAccount(ui->List->currentText(),ui->Account_Type->text());

    msgBox.setText("Person with CNIC: "+ui->List->currentText()+" removed Successfully");
    msgBox.exec();

    this->close();
    delete this;
}

void Remove_Account_List_Form::on_List_currentTextChanged(const QString &arg1)
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


        ui->Name->show();
        ui->Address->show();
        ui->ContactNo->show();
        ui->Account_Type->show();
    }
    else{
        ui->Name_Label->hide();
        ui->Address_Label->hide();
        ui->ContactNo_Label->hide();
        ui->Account_Type_Label->hide();


        ui->Name->hide();
        ui->Address->hide();
        ui->ContactNo->hide();
        ui->Account_Type->hide();
    }
}
