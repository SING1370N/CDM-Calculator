/////////////////////////////////////////////////////////////////////////
//////////////////////////////в?кно дов?дки//////////////////////////////
/////////////////////////////////////////////////////////////////////////

//////////////////////////////////////
//пiдключаємо заголовнi файли проекту
#include "ui_info.h"
#include "info.h"
#include <QSound>

info::info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::info)
{
    QSound::play (":/resource/res/sound/you.wav");
    label = new QLabel(this);
    movie = new QMovie(":/resource/res/gif/3.gif"); // гифки подходят ток 1000*600, но я могу переделать любую твою гиф под этот размерs
    label -> setMovie(movie); //присвоение гифки
    //this->resize(1000, 600); //Это можно закоментить
    label->resize(1000, 600); //размер гифки
    label->show(); //показать гиф
    movie->start(); //запустить гиф
    movie->setSpeed(130); //скорость гиф *130
    ui->setupUi(this);
}

info::~info()
{
    delete ui;
}
