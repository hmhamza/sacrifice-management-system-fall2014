#ifndef CHANGE_PASSWORD_FORM_H
#define CHANGE_PASSWORD_FORM_H

#include <QWidget>

namespace Ui {
class Change_Password_Form;
}

class Change_Password_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Change_Password_Form(QWidget *parent = 0);
    ~Change_Password_Form();

private slots:
    void on_Submit_clicked();

private:
    Ui::Change_Password_Form *ui;
};

#endif // CHANGE_PASSWORD_FORM_H
