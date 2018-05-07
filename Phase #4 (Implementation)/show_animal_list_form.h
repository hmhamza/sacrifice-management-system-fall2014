#ifndef SHOW_ANIMAL_LIST_FORM_H
#define SHOW_ANIMAL_LIST_FORM_H

#include <QWidget>

namespace Ui {
class Show_Animal_List_Form;
}

class Show_Animal_List_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Show_Animal_List_Form(QWidget *parent = 0);
    ~Show_Animal_List_Form();

private slots:
    void on_Submit_clicked();

private:
    Ui::Show_Animal_List_Form *ui;
};

#endif // SHOW_ANIMAL_LIST_FORM_H
