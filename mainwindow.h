/////////////////////////////////////////////////////////////////////////
//заголовий файл для роботи з головним вiкном
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
////////////////////////////////
//пiдключаємо Qt-модулi
#include <QWidget>
#include <QMovie>
#include <QLabel>
#include <QMainWindow>
#include <QtGui>
/////////////////////////////////
//пiдключаємо потрiбнi бiбiлотеки
//та файли
#include <string.h>
#include "info.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }                  //додаємо клас нашого вiкна в простiр iмен Ui
QT_END_NAMESPACE

////////////////////////////////
//оголошуємо прототипи функцiй
void ob(QStringList,QStringList,QStringList &);     //функцiя об'єднання
void perer(QStringList,QStringList,QStringList &);  //функцiя перерiз
void razAB(QStringList,QStringList,QStringList &);  //функцiя рiзниця
bool vhod(QStringList,QStringList);                 //функцiя входження
void ran(QString&);                                 //функцiя випадкових чисел

class MainWindow : public QMainWindow               //класс об'єкту головне вiкно
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = NULL);
    ~MainWindow();                                  //деструктор

private slots:

    void on_RandomAB_clicked();                     //ф. для кнопки "Випадковi символи АВ"
    void on_RandomB_clicked();                      //ф. для кнопки "Випадковi символи В"
    void on_RandomA_clicked();                      //ф. для кнопки "Випадковi символи А"
    void on_Funk6_clicked();                        //ф. для кнопки "Входження"
    void on_Funk5_clicked();                        //ф. для кнопки "Симетрична рiзниця"
    void on_Funk4_clicked();                        //ф. для кнопки "Об'єднання"
    void on_Funk3_clicked();                        //ф. для кнопки "Перетин"
    void on_Funk2_clicked();                        //ф. для кнопки "Рiзниця В/А"
    void on_Funk1_clicked();                        //ф. для кнопки "Рiзниця А/В"
    void on_InfoW_clicked();                        //ф. виводу вiкна с iнформацiєю
    void Input(QStringList &,QStringList &);        //ф. для вводу елементiв
    void empty();                                   //ф. виводу тестового повiдомлення
    bool prEmpty(QStringList,QStringList);          //ф. перевiрки двух множин на порожнiсть

    void on_ExitBut_clicked();

private:
    Ui::MainWindow *ui;                             //вказiвник для головного вiкна
    info *window;                                   //вказiвник для фiкна довiдки
};
#endif
////////////////////////////////////////////////////////////////////////////////////////////
