/////////////////////////////////////////////////////////////////////////
/////////////////////////////���� �ணࠬ�//////////////////////////////
/////////////////////////////////////////////////////////////////////////

////////////////////////////////
//�i������ Qt-����i
#include <QApplication>
#include <QFile>
#include <QSound>
//�i������ ��������i 䠩�� �஥��� � �i��i�⥪�
#include "mainwindow.h"
#include "info.h"
#include <windows.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSound sound(":/resource/res/sound/Black_White.wav");
    sound.play();
    MainWindow w;
    w.show();                       //����᪠� ������� �i���
    return a.exec();
}
