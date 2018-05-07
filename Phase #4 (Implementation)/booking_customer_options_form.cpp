#include "booking_customer_options_form.h"
#include "ui_booking_customer_options_form.h"

#include"booking_form.h"
#include"add_new_customer_form.h"

Booking_Customer_Options_Form::Booking_Customer_Options_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Booking_Customer_Options_Form)
{
    ui->setupUi(this);

    this->setFixedSize(400,180);
}

Booking_Customer_Options_Form::~Booking_Customer_Options_Form()
{
    delete ui;
}

void Booking_Customer_Options_Form::on_YES_clicked()
{
    Booking_Form *b=new Booking_Form;
    b->show();

    this->close();
    delete this;
}

void Booking_Customer_Options_Form::on_NO_clicked()
{
    Add_New_Customer_Form *c=new Add_New_Customer_Form;
    c->show();

    this->close();
    delete this;
}
