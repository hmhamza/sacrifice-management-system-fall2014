#ifndef RECORD_DELIVERY_H
#define RECORD_DELIVERY_H

#include <QWidget>

namespace Ui {
class Record_Delivery;
}

class Record_Delivery : public QWidget
{
    Q_OBJECT

public:
    explicit Record_Delivery(QWidget *parent = 0);
    ~Record_Delivery();

private slots:
    void on_List_currentTextChanged(const QString &arg1);

    void on_Submit_clicked();

private:
    Ui::Record_Delivery *ui;
};

#endif // RECORD_DELIVERY_H
