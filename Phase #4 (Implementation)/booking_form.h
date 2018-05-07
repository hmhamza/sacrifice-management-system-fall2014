#ifndef BOOKING_FORM_H
#define BOOKING_FORM_H

#include <QWidget>

namespace Ui {
class Booking_Form;
}

class Booking_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Booking_Form(QWidget *parent = 0);
    ~Booking_Form();

private slots:

    void on_Animal_ID_currentTextChanged(const QString &arg1);

    void on_Chech_Availability_clicked();

    void on_Submit_clicked();



    void on_ShowAnimalList_clicked();

    void on_Customer_CNIC_currentTextChanged(const QString &arg1);

private:
    Ui::Booking_Form *ui;
};

#endif // BOOKING_FORM_H
