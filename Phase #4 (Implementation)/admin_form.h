#ifndef ADMIN_FORM_H
#define ADMIN_FORM_H

#include <QMainWindow>

namespace Ui {
class Admin_Form;
}

class Admin_Form : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin_Form(QWidget *parent = 0);
    ~Admin_Form();

private slots:
    void on_AddAnimal_clicked();

    void on_Make_Booking_clicked();

    void on_Add_Account_clicked();

    void on_RemoveAnimal_clicked();

    void on_RemoveAccount_clicked();

    void on_ScheduleSacrifice_clicked();

    void on_EditAccount_clicked();

    void on_RecordMeatLabel_clicked();

    void on_RecordDelivery_clicked();

    void on_ChangePassword_clicked();

    void on_Logout_clicked();

private:
    Ui::Admin_Form *ui;
};

#endif // ADMIN_FORM_H
