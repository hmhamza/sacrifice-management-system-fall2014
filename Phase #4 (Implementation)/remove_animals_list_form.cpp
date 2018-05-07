#include "remove_animals_list_form.h"
#include "ui_remove_animals_list_form.h"

#include "sms_singleton.h"

#include<QMessageBox>

Remove_Animals_List_Form::Remove_Animals_List_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Remove_Animals_List_Form)
{
    ui->setupUi(this);

    this->setFixedSize(570,330);

    SMS_Singleton s;

    QString str;

    str="Select ID";
    ui->List->addItem(str);

    for(int i=0;i<s.getMySystem()->no_Of_Animals();i++){

        str=QString::number(s.getMySystem()->Animal_At(i)->getID());
        //qDebug()<<str<<endl;
        ui->List->addItem(str);
    }

}

Remove_Animals_List_Form::~Remove_Animals_List_Form()
{
    delete ui;
}



void Remove_Animals_List_Form::on_List_currentTextChanged(const QString &arg1)
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

        ui->Name->show();
        ui->Price->show();
        ui->Day->show();
    }
    else{
        ui->Name_Label->hide();
        ui->Price_Label->hide();
        ui->Day_Label->hide();


        ui->Name->hide();
        ui->Price->hide();
        ui->Day->hide();
    }

}

void Remove_Animals_List_Form::on_Submit_clicked()
{

    QMessageBox msgBox;

    if(ui->List->currentText()=="Select ID"){
        msgBox.setText("Please select an Animal");
        msgBox.exec();
        return;
    }

    SMS_Singleton s;
    s.getMySystem()->RemoveAnimal(ui->List->currentText());


     msgBox.setText("Animal with ID: "+ui->List->currentText()+" removed Successfully");
     msgBox.exec();

     this->close();
     delete this;
}
