#ifndef REMOVE_ANIMALS_LIST_FORM_H
#define REMOVE_ANIMALS_LIST_FORM_H

#include <QWidget>

namespace Ui {
class Remove_Animals_List_Form;
}

class Remove_Animals_List_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Remove_Animals_List_Form(QWidget *parent = 0);
    ~Remove_Animals_List_Form();

private slots:

    void on_List_currentTextChanged(const QString &arg1);

    void on_Submit_clicked();

private:
    Ui::Remove_Animals_List_Form *ui;
};

#endif // REMOVE_ANIMALS_LIST_FORM_H
