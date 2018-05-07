#ifndef SCHEDULE_SACRIFICE_FORM_H
#define SCHEDULE_SACRIFICE_FORM_H

#include <QMainWindow>

namespace Ui {
class Schedule_Sacrifice_Form;
}

class Schedule_Sacrifice_Form : public QMainWindow
{
    Q_OBJECT

public:
    explicit Schedule_Sacrifice_Form(QWidget *parent = 0);
    ~Schedule_Sacrifice_Form();

private slots:
    void on_List_currentTextChanged(const QString &arg1);

    void on_Submit_clicked();

private:
    Ui::Schedule_Sacrifice_Form *ui;
};

#endif // SCHEDULE_SACRIFICE_FORM_H
