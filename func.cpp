/////////////////////////////////////////////////////////////////////////
/////////////////////�����i� ��� ஡�� � ���������/////////////////////
/////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////
//�i������ ��������i 䠩�� �஥��� � �i��i�⥪�
#include "mainwindow.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <QSound>


//�㭪�i� ��'󤭠���
void ob(QStringList A,QStringList B,QStringList &C)
{
    int i=0, j=0;                              //��⠭����� �i稫쭨�� ��� ��ॣ��� �������i�
    while(i<A.size() && j<B.size())            //横� ��� ��ॣ��� �������i�
    {
        if(A[i]<B[j])                          //�� ������� ���讣� ��ᨢ� ���訩 �� ��㣨�, �
            C<<A[i++];                         //��९���� ���� � ��ᨢ � � ��i����� �i稫쭨� �������i� �� 1
        else
            if(A[i]>B[j])                      //�� ������� ��㣮�� ��ᨢ� ���訩 �� ���訩, �
                C<<B[j++];                     //��९���� ���� � ��ᨢ � � ��i����� �i稫쭨� �������i� �� 1
            else {                             //�� ������� �������i, �
                C<<B[j++];                     //������� ���� � ��ᨢ � � ��i����� ������ �i稫쭨�� �� 1
                i++;}
    }
    for(i=i;i<A.size();i++)                    //横� ��� ��९��㢠��� ����ॣ����� �������i� ���讣� ��ᨢ�
        C<<A[i];
    for(j=j;j<B.size();j++)                    //横� ��� ��९��㢠��� ����ॣ����� �������i� ��㣮�� ��ᨢ�
        C<<B[j];
}


//�㭪�i� ���⨭�
void perer(QStringList A,QStringList B,QStringList &C)
{
    for(int i=0;i<A.size();i++)                 //横� ��� ��ॣ��� �������i� ���讣� ��ᨢ�
        for(int j=0;j<B.size();j++)             //横� ��� ��ॣ��� �������i� ��㣮�� ��ᨢ�
        {
            if(A[i]==B[j])                          //�� ������� �������i, �
                C<<A[i];                            //���i�� � ��ᨢ �
        }
}


//�㭪�i� �i����i ������
void razAB(QStringList A,QStringList B,QStringList &C)
{
    for(int i=0;i<A.size();i++)                 //横� ��� ��१����� �������i� � � � �
        C<<A[i];
    for(int i=0;i<C.size();i++)                 //横� ��ॣ��� �������i� �
        for(int j=0;j<B.size();j++)             //横� ��ॣ��� �������i� �
            if(C[i]==B[j])                      //�� ������� � ��i������� � ������⠬� �, �
                C.removeAt(i);                  //������� 楩 ������� � �
}


//�㭪�i� ��ॢiન �� �室�����
bool vhod(QStringList A,QStringList B)
{
    int n=0;                                    //�⢮��� ��i���, � �i� �㤥� ����i��� �i��i��� ��������� �������i� � � i �
    for(int i=0;i<A.size();i++)                 //横� ��ॣ��� �������i� �
        for(int j=0;j<B.size();j++)             //横� ��ॣ��� �������i� �
        {
            if(A[i]==B[j]){                         //�� ������� � ��i������� � ������⠬� �, �
                n++;                                //��i����� �i��i��� �������i� � ��i��i�
                break;}
        }
    return n==A.size();                         //������� true �� ��i ������� ���i�� ������� �i�������� � ������⠬� i���
}


//������� ���������� ᨬ���i�
void ran(QString &z)
{

    int O_rand = 1 + rand() % 3, rand_f;        //������� �᫮ - �i��i��� �������i�
    bool Rand;
    for (int O_for=0; O_for<=O_rand; O_for++)   //横� ��� �����㢠��� �������i� �i��i���� O_rand
    {
        Rand = bool (rand() % 2);               //������� �᫮ (0 ��� 1) 瘟 �i����i��� �� ⨯ ᨢ���
        rand_f = 1 + rand() % 2;                //������� �᫮, 瘟 �i����i��� �i�쪮��i ᨬ���i� � �������i
        if(Rand)                                //�� 1, � ᨬ���� ����� �᫠��
        {
            for(int i=0;i<rand_f;i++)           //������� rand_f �ᥫ i ������� � ��i��� z
                z += QChar(rand()% 10 + 48);
        }
        else                                    //�� 0, � ᨬ���� ����� �i�ࠬ�
        {
            for(int i=0;i<rand_f;i++)           //������� rand_f �i�� i ������� � ��i��� z
                z += QChar(rand()% 26 + 65);
        }
        if(O_for!=O_rand)                       //�� ������� �� ��⠭�i� �i��i��� ���� ᨬ�����-�஡i���
            z += " ";
    }
    QSound plays (":/resource/res/sound/random.wav");
    plays.play(":/resource/res/sound/random.wav");
}
