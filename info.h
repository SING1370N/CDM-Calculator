/////////////////////////////////////////////////////////////////////////
//��������� 䠩� ��� ஡�� � �i���� ���i���
#ifndef INFO_H
#define INFO_H

////////////////////////////////
//�i������ Qt-����i
#include <QMovie>
#include <QLabel>

namespace Ui {
class info;                     //������� ���� info � ����i� i��� Ui
}

class info : public QWidget     //����� ��'��� �i��� ���i���
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
