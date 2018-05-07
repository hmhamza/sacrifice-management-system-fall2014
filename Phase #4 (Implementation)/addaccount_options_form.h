#ifndef ADDACCOUNT_OPTIONS_FORM_H
#define ADDACCOUNT_OPTIONS_FORM_H

#include <QWidget>

namespace Ui {
class AddAccount_Options_Form;
}

class AddAccount_Options_Form : public QWidget
{
    Q_OBJECT

public:
    explicit AddAccount_Options_Form(QWidget *parent = 0);
    ~AddAccount_Options_Form();

private slots:

    void on_Customer_clicked();

    void on_Mosque_Official_clicked();

private:
    Ui::AddAccount_Options_Form *ui;
};

#endif // ADDACCOUNT_OPTIONS_FORM_H
