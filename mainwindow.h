/////////////////////////////////////////////////////////////////////////
//��������� 䠩� ��� ஡�� � �������� �i����
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
////////////////////////////////
//�i������ Qt-����i
#include <QWidget>
#include <QMovie>
#include <QLabel>
#include <QMainWindow>
#include <QtGui>
/////////////////////////////////
//�i������ ����i��i �i�i��⥪�
//� 䠩��
#include <string.h>
#include "info.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }                  //����� ���� ��讣� �i��� � ����i� i��� Ui
QT_END_NAMESPACE

////////////////////////////////
//�������� ���⨯� �㭪�i�
void ob(QStringList,QStringList,QStringList &);     //�㭪�i� ��'󤭠���
void perer(QStringList,QStringList,QStringList &);  //�㭪�i� ����i�
void razAB(QStringList,QStringList,QStringList &);  //�㭪�i� �i�����
bool vhod(QStringList,QStringList);                 //�㭪�i� �室�����
void ran(QString&);                                 //�㭪�i� ���������� �ᥫ

class MainWindow : public QMainWindow               //����� ��'��� ������� �i���
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = NULL);
    ~MainWindow();                                  //��������

private slots:

    void on_RandomAB_clicked();                     //�. ��� ������ "��������i ᨬ���� ��"
    void on_RandomB_clicked();                      //�. ��� ������ "��������i ᨬ���� �"
    void on_RandomA_clicked();                      //�. ��� ������ "��������i ᨬ���� �"
    void on_Funk6_clicked();                        //�. ��� ������ "�室�����"
    void on_Funk5_clicked();                        //�. ��� ������ "������筠 �i�����"
    void on_Funk4_clicked();                        //�. ��� ������ "��'󤭠���"
    void on_Funk3_clicked();                        //�. ��� ������ "���⨭"
    void on_Funk2_clicked();                        //�. ��� ������ "�i����� �/�"
    void on_Funk1_clicked();                        //�. ��� ������ "�i����� �/�"
    void on_InfoW_clicked();                        //�. ������ �i��� � i��ଠ�i��
    void Input(QStringList &,QStringList &);        //�. ��� ����� �������i�
    void empty();                                   //�. ������ ��⮢��� ���i��������
    bool prEmpty(QStringList,QStringList);          //�. ��ॢiન ���� ������ �� ��஦�i���

    void on_ExitBut_clicked();

private:
    Ui::MainWindow *ui;                             //����i���� ��� ��������� �i���
    info *window;                                   //����i���� ��� �i��� ���i���
};
#endif
////////////////////////////////////////////////////////////////////////////////////////////
