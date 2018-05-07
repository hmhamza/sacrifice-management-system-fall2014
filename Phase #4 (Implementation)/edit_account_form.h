#ifndef EDIT_ACCOUNT_FORM_H
#define EDIT_ACCOUNT_FORM_H

#include <QMainWindow>

namespace Ui {
class Edit_Account_Form;
}

class Edit_Account_Form : public QMainWindow
{
    Q_OBJECT

public:
    explicit Edit_Account_Form(QWidget *parent = 0);
    ~Edit_Account_Form();

private slots:
    void on_List_currentTextChanged(const QString &arg1);

    void on_Submit_clicked();

private:
    Ui::Edit_Account_Form *ui;
};

#endif // EDIT_ACCOUNT_FORM_H
