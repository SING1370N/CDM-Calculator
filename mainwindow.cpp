/////////////////////////////////////////////////////////////////////////
//////////////////////////////������� �i���//////////////////////////////
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////
//�i������ ��������i 䠩��
//�஥��� � ����i
#include "mainwindow.h"
#include "ui_info.h"
#include "ui_mainwindow.h"
#include "windows.h"
#include <QFontDatabase>
#include <QSound>

////////////////////////////////////////////////////////////////////////////////////
//�i� � �������� �i����

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),ui(new Ui::MainWindow)
{
    //�i������ �����
    QFontDatabase::addApplicationFont(":/resource/res/Airfool.otf");
    //�⢮��� � ��⨢�� ������� �i���
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);
}

MainWindow::~MainWindow()                       //�������� ��� ���饭�� ��'�� (��������� �i���)
{
    delete ui;

}

void MainWindow::on_InfoW_clicked()             //i������i� �� ��i�� �� ������i ���i���
{
    window = new info(this);                    //�⢮७�� �i�� ���i���
    window->show();                             //���i� �� ��࠭
}


////////////////////////////////////////////////////////////////////////////////////////////
//�㭪�i� ��� ������

void MainWindow::on_Funk1_clicked()         //i������i� ��� ������ "�i����� A/B"
{
    QSound sound(":/resource/res/sound/clicks.wav");
    sound.play(":/resource/res/sound/clicks.wav");
    QStringList A, B;
    Input(A,B);                             //��� �������
    if(prEmpty(A,B))                        //��ॢi��� �� �� ��஦�i���
        return;                             //��室��� � �㭪�i�, �� ���� ��஦�i
    QStringList C;
    razAB(A,B,C);                           //�������� �㭪�i� ��������� �i����i ������ � i �
    if(C.isEmpty())                         //�� �⢮७� ������� ��஦��, �
        empty();                            //�������� �i����i��� ���i��������
    else                                    //�� �i - �������� ������� �� ��࠭
        ui->output->setText(C.join(" "));

}


void MainWindow::on_Funk2_clicked()         //i������i� ��� ������ "�i����� �/�"
{
    QSound sound(":/resource/res/sound/clicks.wav");
    sound.play(":/resource/res/sound/clicks.wav");
    QStringList A, B;
    Input(A,B);                             //��� �������
    if(prEmpty(A,B))                        //��ॢi��� �� �� ��஦�i���
        return;                             //��室��� � �㭪�i�, �� ���� ��஦�i
    QStringList C;
    razAB(B,A,C);                           //�������� �㭪�i� ��������� �i����i ������ � i �
    if(C.isEmpty())                         //�� �⢮७� ������� ��஦��, �
        empty();                            //�������� �i����i��� ���i��������
    else
        ui->output->setText(C.join(" "));   //�������� ������� �� ��࠭

}

void MainWindow::on_Funk3_clicked()         //i������i� ��� ������ "���⨭"
{
    QSound sound(":/resource/res/sound/clicks.wav");
    sound.play(":/resource/res/sound/clicks.wav");
    QStringList A, B;
    Input(A,B);                             //��� �������
    QStringList C;
    perer(A,B,C);                           //�������� �㪭�i� ��������� ���⨭�
    if(C.isEmpty())                         //�� �⢮७� ������� ��஦��, �
        empty();                            //������ �i����i��� ���i��������
    else
        ui->output->setText(C.join(" "));   //�������� ������� �� ��࠭
}

void MainWindow::on_Funk4_clicked()     //i������i� ��� ������ "��'󤭠���"
{
    QSound sound(":/resource/res/sound/clicks.wav");
    sound.play(":/resource/res/sound/clicks.wav");
    QStringList A, B;
    Input(A,B);                         //��� �������
    if(prEmpty(A,B)){                   //��ॢi��� �� �� ��஦�i���
        return;}                        //��室��� � �㭪�i�, �� ���� ��஦�i
    QStringList C;
    ob(A,B,C);                          //�������� �㭪�i� ��������� ��'󤭠���
    ui->output->setText(C.join(" "));   //�������� ������� �� ��࠭

}

void MainWindow::on_Funk5_clicked()     //i������i� ��� ������ "������筠 �i�����"
{
    QSound sound(":/resource/res/sound/clicks.wav");
    sound.play(":/resource/res/sound/clicks.wav");
    QStringList A, B;
    Input(A,B);                         //��� �������
    if(prEmpty(A,B)){                   //��ॢi��� �� �� ��஦�i���
        return;}                        //��室��� � �㭪�i�, �� ���� ��஦�i
    QStringList C1,C2,C;
    ob(A,B,C1);                         //������� � ������� �1 ��'󤭠��� ������ � i �
    perer(A,B,C2);                      //������� � ������� �2 ���⨭ ������ � i �
    razAB(C1,C2,C);                     //������� � ������� � �i����� ������ �1 i �2
    ui->output->setText(C.join(" "));   //�������� ������� �� ��࠭

}

void MainWindow::on_Funk6_clicked() //i������i� ��� ������ "�室�����"
{
    QSound sound(":/resource/res/sound/clicks.wav");
    sound.play(":/resource/res/sound/clicks.wav");
    QStringList A, B;
    Input(A,B);                     //��� �������
    bool a,b;
    a=vhod(A,B);                    //������� � �㪭�i� ��ॢiન �㫥�� ���祭�� � �室��� A � B
    b=vhod(B,A);                    //������� � �㪭�i� ��ॢiન �㫥�� ���祭�� � �室��� B � A
    QString l;
    if(a==true && b==true){         //�� ��i��i �㭪�i� �����㫨 true, �
        l="B_=_A";                  //������� ���i��������, � ������� �i��i
    }
    else if(b==true)                //�� � �室��� � �
        l="B_in_A";                 //������� � ��i��� ���i�������� �� �
    else if(a==true)                //�� � �室��� � �
        l="A_in_B";                 //������� � ��i��� ���i�������� �� �
    else{                           //�� �i � �� �室��� � �, �i �������
        l="nothing";                //������� � ��i��� "�i箣�"
    }
    ui->output->setText(l);         //���i� ⥪��� ��i����
}

void MainWindow::on_RandomA_clicked()       //i������i� ��� ������ "��������i ᨬ���� ��� ������� �"
{
    QString z;
    ran(z);                                 //�������� �㭪�i� �����㢠��� ���������� ᨬ���i�
    ui->InputA->setText(z);                 //�������� ᨬ���� � ���� ��� �����

}

void MainWindow::on_RandomB_clicked()       //i������i� ��� ������ "��������i ᨬ���� ��� ������� �"
{

    QString z;
    ran(z);                                 //�������� �㭪�i� �����㢠��� ���������� ᨬ���i�
    ui->InputB->setText(z);                 //�������� ᨬ���� � ���� ��� �����
}

void MainWindow::on_RandomAB_clicked()      //i������i� ��� ������ "��������i ᨬ���� ��� ������ � i �"
{
    QString a;
    QString b;
    ran(a);                                 //�������� �㭪�i� �����㢠��� ���������� ᨬ���i�
    ran(b);
    ui->InputA->setText(a);                 //�������� ᨬ���� � ���� ��� ����� �
    ui->InputB->setText(b);                 //�������� ᨬ���� � ���� ��� ����� �
}


////////////////////////////////////////////////////////////////////////////////////////////
//஡��i �㭪�i�

void MainWindow::empty()                               //�㭪�i� ���������
{                                                      //���i�������� "��஦�� �������"
    QString l="empty_set";
    ui->output->setText(l);
}

bool MainWindow::prEmpty(QStringList A,QStringList B)  //�㪭�i� ��ॢiન �� ��஦�i���
{
    if(A.isEmpty()==true && B.isEmpty()==true){         //�� �����i ������� ��஦�i
        empty();                                        //�������� ⥪��
        return true;}
    return false;
}

void MainWindow::Input(QStringList &A,QStringList &B)   //�㭪�i� ��� �⠭�� �������i�
{                                                       //������ � ������i �����
    QString a,b;
    a=(ui->InputA->text());                             //������� ⥪�� � ������ � �
    b=(ui->InputB->text());                             //������� ⥪�� � ������ � b
    if(!a.isEmpty()){                                   //�� ������� a �� ��஦��
        A=a.split(" ");                                 //஧�i��� �������
        A.sort();                                       //����� �������
        A.removeDuplicates();}                          //������� �㡫i���
    if(!b.isEmpty()){                                   //�������i筮 �� ������� b �� ��஦��
        B=b.split(" ");                                 //஧�i��� �������
        B.sort();                                       //����� �������
        B.removeDuplicates();}                          //������� �㡫i���
}

void MainWindow::on_ExitBut_clicked()
{

}
