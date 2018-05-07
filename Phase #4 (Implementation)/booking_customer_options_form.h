#ifndef BOOKING_CUSTOMER_OPTIONS_FORM_H
#define BOOKING_CUSTOMER_OPTIONS_FORM_H

#include <QWidget>

namespace Ui {
class Booking_Customer_Options_Form;
}

class Booking_Customer_Options_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Booking_Customer_Options_Form(QWidget *parent = 0);
    ~Booking_Customer_Options_Form();

private slots:
    void on_YES_clicked();

    void on_NO_clicked();

private:
    Ui::Booking_Customer_Options_Form *ui;
};

#endif // BOOKING_CUSTOMER_OPTIONS_FORM_H
