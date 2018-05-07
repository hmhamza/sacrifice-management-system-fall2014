#include "show_animal_list_form.h"
#include "ui_show_animal_list_form.h"

#include "sms_singleton.h"

Show_Animal_List_Form::Show_Animal_List_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Show_Animal_List_Form)
{
    ui->setupUi(this);

    this->setFixedSize(543,420);

    SMS_Singleton s;

    Animal *A;


    for(int i=0,count=0;i<s.getMySystem()->no_Of_Animals()&&count<5;i++){

        A=s.getMySystem()->Animal_At(i);

        if(A->isAvailable()){

            ui->ID->addItem(QString::number(A->getID()));
            ui->Name->addItem(A->getName());
            ui->Price->addItem(QString::number(A->getPrice()));
            count++;

        }

    }


}

Show_Animal_List_Form::~Show_Animal_List_Form()
{
    delete ui;
}

void Show_Animal_List_Form::on_Submit_clicked()
{
    this->close();
    delete this;
}
