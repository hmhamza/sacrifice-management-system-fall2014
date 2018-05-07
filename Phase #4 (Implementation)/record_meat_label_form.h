#ifndef RECORD_MEAT_LABEL_FORM_H
#define RECORD_MEAT_LABEL_FORM_H

#include <QWidget>

namespace Ui {
class Record_Meat_Label_Form;
}

class Record_Meat_Label_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Record_Meat_Label_Form(QWidget *parent = 0);
    ~Record_Meat_Label_Form();

private slots:
    void on_List_currentTextChanged(const QString &arg1);

    void on_Submit_clicked();

private:
    Ui::Record_Meat_Label_Form *ui;
};

#endif // RECORD_MEAT_LABEL_FORM_H
