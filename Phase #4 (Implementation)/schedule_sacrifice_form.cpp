#include "schedule_sacrifice_form.h"
#include "ui_schedule_sacrifice_form.h"

#include"sms_singleton.h"

#include<QMessageBox>

Schedule_Sacrifice_Form::Schedule_Sacrifice_Form(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Schedule_Sacrifice_Form)
{
    ui->setupUi(this);

    this->setFixedSize(585,420);

    SMS_Singleton s;

    QString str;

    str="Select ID";
    ui->List->addItem(str);

    for(int i=0;i<s.getMySystem()->no_Of_Animals();i++){

        str=QString::number(s.getMySystem()->Animal_At(i)->getID());
        ui->List->addItem(str);
    }
}

Schedule_Sacrifice_Form::~Schedule_Sacrifice_Form()
{
    delete ui;
}

void Schedule_Sacrifice_Form::on_List_currentTextChanged(const QString &arg1)
{
    int ID=arg1.toInt();

    SMS_Singleton s;
    Animal *A=s.getMySystem()->Search_Animal_by_ID(ID);

    if(A!=nullptr){
        ui->Name->setText(A->getName());

        ui->Price->setText(QString::number(A->getPrice()));

        if(A->getDayOfSacrifice()==0)
            ui->Day->setText("<Not Decided>");
        else
            ui->Day->setText(QString::number(A->getDayOfSacrifice()));

        ui->Name_Label->show();
        ui->Price_Label->show();
        ui->Day_Label->show();
         ui->Enter_Label->show();

        ui->Name->show();
        ui->Price->show();
        ui->Day->show();
        ui->Days_Options->show();
    }
    else{
        ui->Name_Label->hide();
        ui->Price_Label->hide();
        ui->Day_Label->hide();
        ui->Enter_Label->hide();


        ui->Name->hide();
        ui->Price->hide();
        ui->Day->hide();
        ui->Days_Options->hide();
    }
}

void Schedule_Sacrifice_Form::on_Submit_clicked()
{
    QMessageBox msgBox;

    if(ui->List->currentText()=="Select ID"){
        msgBox.setText("Please select an Animal");
        msgBox.exec();
        return;
    }

    if(ui->Days_Options->currentText()=="Select"){
        msgBox.setText("Please select a Day to Schedule");
        msgBox.exec();
        return;
    }

    SMS_Singleton s;
    s.getMySystem()->ScheduleSacrifice(ui->List->currentText(),ui->Days_Options->currentText());


    msgBox.setText("Animal with ID: "+ui->List->currentText()+" has been Scheduled for Sacrifice to Day#"+ui->Days_Options->currentText()+" ");
    msgBox.exec();

     this->close();
     delete this;
}
