/////////////////////////////////////////////////////////////////////////
//////////////////////////////�?��� ���?���//////////////////////////////
/////////////////////////////////////////////////////////////////////////

//////////////////////////////////////
//�i������ ��������i 䠩�� �஥���
#include "ui_info.h"
#include "info.h"
#include <QSound>

info::info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::info)
{
    QSound::play (":/resource/res/sound/you.wav");
    label = new QLabel(this);
    movie = new QMovie(":/resource/res/gif/3.gif"); // ��䪨 ���室�� ⮪ 1000*600, �� � ���� ��।����� ���� ⢮� ��� ��� ��� ࠧ���s
    label -> setMovie(movie); //��᢮���� ��䪨
    //this->resize(1000, 600); //�� ����� ����������
    label->resize(1000, 600); //ࠧ��� ��䪨
    label->show(); //�������� ���
    movie->start(); //�������� ���
    movie->setSpeed(130); //᪮���� ��� *130
    ui->setupUi(this);
}

info::~info()
{
    delete ui;
}
