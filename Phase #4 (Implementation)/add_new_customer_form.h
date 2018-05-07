#ifndef ADD_NEW_CUSTOMER_FORM_H
#define ADD_NEW_CUSTOMER_FORM_H

#include <QWidget>

namespace Ui {
class Add_New_Customer_Form;
}

class Add_New_Customer_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Add_New_Customer_Form(QWidget *parent = 0);
    ~Add_New_Customer_Form();

private slots:
    void on_Submit_clicked();

    void on_MakeBooking_clicked();

private:
    Ui::Add_New_Customer_Form *ui;
};

#endif // ADD_NEW_CUSTOMER_FORM_H
