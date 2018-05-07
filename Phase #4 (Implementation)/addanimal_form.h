#ifndef ADDANIMAL_FORM_H
#define ADDANIMAL_FORM_H

#include <QMainWindow>

namespace Ui {
class AddAnimal_Form;
}

class AddAnimal_Form : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddAnimal_Form(QWidget *parent = 0);
    ~AddAnimal_Form();

private slots:
    void on_Submit_clicked();

private:
    Ui::AddAnimal_Form *ui;
};

#endif // ADDANIMAL_FORM_H
