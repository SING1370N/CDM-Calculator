/////////////////////////////////////////////////////////////////////////
//////////////////////////////головне вiкно//////////////////////////////
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////
//пiдключаємо заголовнi файли
//проекту та модулi
#include "mainwindow.h"
#include "ui_info.h"
#include "ui_mainwindow.h"
#include "windows.h"
#include <QFontDatabase>
#include <QSound>

////////////////////////////////////////////////////////////////////////////////////
//дiї з головним вiкном

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),ui(new Ui::MainWindow)
{
    //пiдключаємо ресурси
    QFontDatabase::addApplicationFont(":/resource/res/Airfool.otf");
    //створюємо та активуємо головне вiкно
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);
}

MainWindow::~MainWindow()                       //деструктор для знищення об'єкта (головного вiкна)
{
    delete ui;

}

void MainWindow::on_InfoW_clicked()             //iнструкцiя при клiку по областi довiдки
{
    window = new info(this);                    //створення вiна довiдки
    window->show();                             //вивiд на екран
}


////////////////////////////////////////////////////////////////////////////////////////////
//функцiї для кнопок

void MainWindow::on_Funk1_clicked()         //iнструкцiї для кнопки "Рiзниця A/B"
{
    QSound sound(":/resource/res/sound/clicks.wav");
    sound.play(":/resource/res/sound/clicks.wav");
    QStringList A, B;
    Input(A,B);                             //читаємо множини
    if(prEmpty(A,B))                        //перевiряємо їх на порожнiсть
        return;                             //виходимо з функцiї, якщо вони порожнi
    QStringList C;
    razAB(A,B,C);                           //викликаємо функцiю виконання рiзницi множин А i В
    if(C.isEmpty())                         //якщо утворена множина порожня, то
        empty();                            //виводимо вiдповiдне повiдомлення
    else                                    //якщо нi - виводимо множину на екран
        ui->output->setText(C.join(" "));

}


void MainWindow::on_Funk2_clicked()         //iнструкцiї для кнопки "Рiзниця В/А"
{
    QSound sound(":/resource/res/sound/clicks.wav");
    sound.play(":/resource/res/sound/clicks.wav");
    QStringList A, B;
    Input(A,B);                             //читаємо множини
    if(prEmpty(A,B))                        //перевiряємо їх на порожнiсть
        return;                             //виходимо з функцiї, якщо вони порожнi
    QStringList C;
    razAB(B,A,C);                           //викликаємо функцiю виконання рiзницi множин В i А
    if(C.isEmpty())                         //якщо утворена множина порожня, то
        empty();                            //виводимо вiдповiдне повiдомлення
    else
        ui->output->setText(C.join(" "));   //виводимо множину на екран

}

void MainWindow::on_Funk3_clicked()         //iнструкцiї для кнопки "Перетин"
{
    QSound sound(":/resource/res/sound/clicks.wav");
    sound.play(":/resource/res/sound/clicks.wav");
    QStringList A, B;
    Input(A,B);                             //читаємо множини
    QStringList C;
    perer(A,B,C);                           //викликаємо фукнцiю виконання перетину
    if(C.isEmpty())                         //якщо утворена множина порожня, то
        empty();                            //вивести вiдповiдне повiдомлення
    else
        ui->output->setText(C.join(" "));   //виводимо множину на екран
}

void MainWindow::on_Funk4_clicked()     //iнструкцiї для кнопки "Об'єднання"
{
    QSound sound(":/resource/res/sound/clicks.wav");
    sound.play(":/resource/res/sound/clicks.wav");
    QStringList A, B;
    Input(A,B);                         //читаємо множини
    if(prEmpty(A,B)){                   //перевiряємо їх на порожнiсть
        return;}                        //виходимо з функцiї, якщо вони порожнi
    QStringList C;
    ob(A,B,C);                          //викликаємо функцiю виконання об'єднання
    ui->output->setText(C.join(" "));   //виводимо множину на екран

}

void MainWindow::on_Funk5_clicked()     //iнструкцiї для кнопки "Симетрична рiзниця"
{
    QSound sound(":/resource/res/sound/clicks.wav");
    sound.play(":/resource/res/sound/clicks.wav");
    QStringList A, B;
    Input(A,B);                         //читаємо множини
    if(prEmpty(A,B)){                   //перевiряємо їх на порожнiсть
        return;}                        //виходимо з функцiї, якщо вони порожнi
    QStringList C1,C2,C;
    ob(A,B,C1);                         //записуємо в множину С1 об'єднання множин А i В
    perer(A,B,C2);                      //записуємо в множину С2 перетин множин А i В
    razAB(C1,C2,C);                     //записуємо в множину С рiзницю множин С1 i С2
    ui->output->setText(C.join(" "));   //виводимо множину на екран

}

void MainWindow::on_Funk6_clicked() //iнструкцiї для кнопки "Входження"
{
    QSound sound(":/resource/res/sound/clicks.wav");
    sound.play(":/resource/res/sound/clicks.wav");
    QStringList A, B;
    Input(A,B);                     //читаємо множини
    bool a,b;
    a=vhod(A,B);                    //повертаємо з фукнцiї перевiрки булеве значення чи входить A в B
    b=vhod(B,A);                    //повертаємо з фукнцiї перевiрки булеве значення чи входить B в A
    QString l;
    if(a==true && b==true){         //якщо обiдвi функцiї повернули true, то
        l="B_=_A";                  //записуэмо повiдомлення, що множини рiвнi
    }
    else if(b==true)                //якщо В входить в А
        l="B_in_A";                 //записуємо в змiнну повiдомлення про це
    else if(a==true)                //якщо А входить в В
        l="A_in_B";                 //записуємо в змiнну повiдомлення про це
    else{                           //якщо нi А не входить в В, нi навпаки
        l="nothing";                //записуємо в змiнну "нiчого"
    }
    ui->output->setText(l);         //вивiд тексту змiнної
}

void MainWindow::on_RandomA_clicked()       //iнструкцiї для кнопки "Випадковi символи для множини А"
{
    QString z;
    ran(z);                                 //викликаємо функцiю генерування випадкових символiв
    ui->InputA->setText(z);                 //виводимо символи в поле для вводу

}

void MainWindow::on_RandomB_clicked()       //iнструкцiї для кнопки "Випадковi символи для множини В"
{

    QString z;
    ran(z);                                 //викликаємо функцiю генерування випадкових символiв
    ui->InputB->setText(z);                 //виводимо символи в поле для вводу
}

void MainWindow::on_RandomAB_clicked()      //iнструкцiї для кнопки "Випадковi символи для множин А i В"
{
    QString a;
    QString b;
    ran(a);                                 //викликаємо функцiю генерування випадкових символiв
    ran(b);
    ui->InputA->setText(a);                 //виводимо символи в поле для вводу А
    ui->InputB->setText(b);                 //виводимо символи в поле для вводу В
}


////////////////////////////////////////////////////////////////////////////////////////////
//робочi функцiї

void MainWindow::empty()                               //функцiя виведення
{                                                      //повiдомлення "Порожня множина"
    QString l="empty_set";
    ui->output->setText(l);
}

bool MainWindow::prEmpty(QStringList A,QStringList B)  //фукнцiя перевiрки на порожнiсть
{
    if(A.isEmpty()==true && B.isEmpty()==true){         //якщо обидвi множини порожнi
        empty();                                        //виводимо текст
        return true;}
    return false;
}

void MainWindow::Input(QStringList &A,QStringList &B)   //функцiя для читання елементiв
{                                                       //множин з областi вводу
    QString a,b;
    a=(ui->InputA->text());                             //записуємо текст з лейбла в а
    b=(ui->InputB->text());                             //записуємо текст з лейбла в b
    if(!a.isEmpty()){                                   //якщо множина a не порожня
        A=a.split(" ");                                 //роздiляємо елементи
        A.sort();                                       //сортуємо елементи
        A.removeDuplicates();}                          //видаляємо дублiкати
    if(!b.isEmpty()){                                   //аналогиiчно якщо множина b не порожня
        B=b.split(" ");                                 //роздiляємо елементи
        B.sort();                                       //сортуємо елементи
        B.removeDuplicates();}                          //видаляємо дублiкати
}

void MainWindow::on_ExitBut_clicked()
{

}
