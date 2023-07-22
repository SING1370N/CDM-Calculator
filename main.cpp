/////////////////////////////////////////////////////////////////////////
/////////////////////////////старт програми//////////////////////////////
/////////////////////////////////////////////////////////////////////////

////////////////////////////////
//пiдключаємо Qt-модулi
#include <QApplication>
#include <QFile>
#include <QSound>
//пiдключаємо заголовнi файли проекту та бiблiотеки
#include "mainwindow.h"
#include "info.h"
#include <windows.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSound sound(":/resource/res/sound/Black_White.wav");
    sound.play();
    MainWindow w;
    w.show();                       //запускаємо головне вiкно
    return a.exec();
}
