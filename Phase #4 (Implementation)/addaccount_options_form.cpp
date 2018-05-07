#include "addaccount_options_form.h"
#include "ui_addaccount_options_form.h"

#include"add_new_customer_form.h"
#include"add_mosqueofficial_form.h"

AddAccount_Options_Form::AddAccount_Options_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddAccount_Options_Form)
{
    ui->setupUi(this);

    this->setFixedSize(470,190);
}

AddAccount_Options_Form::~AddAccount_Options_Form()
{
    delete ui;
}


void AddAccount_Options_Form::on_Mosque_Official_clicked()
{
    this->close();
    Add_MosqueOfficial_Form *m=new Add_MosqueOfficial_Form;
    m->show();
    delete this;
}

void AddAccount_Options_Form::on_Customer_clicked()
{
    this->close();
    Add_New_Customer_Form *c=new Add_New_Customer_Form;
    c->show();
    delete this;
}
