/////////////////////////////////////////////////////////////////////////
//заголовий файл для роботи з вiкном довiдки
#ifndef INFO_H
#define INFO_H

////////////////////////////////
//пiдключаємо Qt-модулi
#include <QMovie>
#include <QLabel>

namespace Ui {
class info;                     //записуємо клас info в простiр iмен Ui
}

class info : public QWidget     //класс об'єкту вiкна довiдки
{
    Q_OBJECT
public:
    explicit info(QWidget *parent = NULL);
    ~info();
    QMovie *movie;
    QLabel *label;
private:
    Ui::info *ui;
};

#endif
/////////////////////////////////////////////////////////////////////////
