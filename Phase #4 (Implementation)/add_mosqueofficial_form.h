#ifndef ADD_MOSQUEOFFICIAL_FORM_H
#define ADD_MOSQUEOFFICIAL_FORM_H

#include <QWidget>

namespace Ui {
class Add_MosqueOfficial_Form;
}

class Add_MosqueOfficial_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Add_MosqueOfficial_Form(QWidget *parent = 0);
    ~Add_MosqueOfficial_Form();

private slots:
    void on_Submit_clicked();

private:
    Ui::Add_MosqueOfficial_Form *ui;
};

#endif // ADD_MOSQUEOFFICIAL_FORM_H
