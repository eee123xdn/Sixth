#include "page1.h"
#include "ui_page1.h"
#include<QString>
page1::page1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page1)
{
    ui->setupUi(this);
  /*  QPushButton * btn[21];
    for (int i = 1;i <= 20;i++)
    {
        btn[i] = new QPushButton;
        btn[i]->setParent(this);
         btn[i]->setText(QString::number(i));
          btn[i]->resize(60,60);
          btn[i]->move((i/5+1)*15+(i/5)*60,(i%5+1)*64+(i%5)*60);
      }
    }

    //change size of btn

    //QPushButton *btn2 = new QPushButton("second blood",this);
    //windoes daxiao
    //resize(600,400);
    //btn move*/}


page1::~page1()
{
    delete ui;
}
