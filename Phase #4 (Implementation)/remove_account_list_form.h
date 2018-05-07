#ifndef REMOVE_ACCOUNT_LIST_FORM_H
#define REMOVE_ACCOUNT_LIST_FORM_H

#include <QMainWindow>

namespace Ui {
class Remove_Account_List_Form;
}

class Remove_Account_List_Form : public QMainWindow
{
    Q_OBJECT

public:
    explicit Remove_Account_List_Form(QWidget *parent = 0);
    ~Remove_Account_List_Form();

private slots:
    void on_Submit_clicked();

    void on_List_currentTextChanged(const QString &arg1);

private:
    Ui::Remove_Account_List_Form *ui;
};

#endif // REMOVE_ACCOUNT_LIST_FORM_H
