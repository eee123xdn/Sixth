#include "piggame.h"
#include "ui_piggame.h"
#include<QPushButton>
#include"page1.h"
#include"page2.h"
#include"page3.h"
#include"page4.h"
#include"page5.h"
#include"config.h"
#include"store.h"
#include"honor.h"
#include<QTime>
#include<QTimer>
#include<QString>
#include<QDebug>
PigGame::PigGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PigGame)
{
    ui->setupUi(this);
    PigGame::new_game();
    QTimer* my_timer=new QTimer();
    connect(my_timer,SIGNAL(timeout()),this,SLOT(goout()));
    my_timer->start(1000);
}

PigGame::~PigGame()
{
    delete ui;

}
void PigGame::new_game()
{
    p = head;
    //350hua or bai
    for(int i = 0;i<70;i++)
    {
        for(int K=0;K<5;K++)
        {
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime())+K*10000+i);
            p->data[K][0]=qrand()%2+1;

            //p->data[K][1] = 200;
            p->data[K][2] = 1;
            p->data[K][3] = 0;
            p->data[K][4] = 0;
        }
        for(int K=5;K<10;K++)         //每个猪圈后面五个位置没装，种类定为4
        {
            p->data[K][0] = 4;
            p->data[K][1] = 0;
            p->data[K][2] = 0;
            p->data[K][3] = 0;
            p->data[K][4] = 0;
        }
        p->number=5;
        p->N = new Node();
        p=p->N;
    }
    //150hei
    for(int i = 70;i<100;i++)
    {
        p->type = true;
        for(int K=0;K<5;K++)
        {
           //qDebug()<<"1";
            p->data[K][0] = 3;
           // p->data[K][1] = 200;
            p->data[K][2] = 1;
            //qDebug()<<p->data[K][0];
            p->data[K][3] = 0;            //改动
            p->data[K][4] = 0;
        }
        for(int K=5;K<10;K++)         //每个猪圈后面五个位置没装，种类定为4
        {
            p->data[K][0] = 4;
            p->data[K][1] = 0;
            p->data[K][2] = 0;
            p->data[K][3] = 0;
            p->data[K][4] = 0;
        }
        p->number=5;                      //改动
        p->N = new Node();
        p=p->N;
    }
    p=head;
    for(int i = 0;i<100;i++)
    {

        for(int K=0;K<5;K++)
        {


                    qsrand(QTime(0,0,0).secsTo(QTime::currentTime())+K*100+i);
                    p->data[K][1]=qrand()%300+200;
                    //if(i>=70)

                    qDebug()<<p->data[K][0];
                    }


        p=p->N;

        }

     sum = 500;
    //MainWindow::savefile_zhuangtai("a");

}

void PigGame::on_btn_config_clicked()
{
    config *a = new config(this);
    a->show();
}

void PigGame::on_btn_store_clicked()
{
    store *a = new store(this);
    a->show();
}

void PigGame::on_btn_honor_clicked()
{
    honor *a = new honor(this);
    a->show();
}

void PigGame::on_btn_nextpage_clicked()
{
    int nIndex = ui->stackedWidget->currentIndex();

        // 获取下一个需要显示的页面索引
        ++nIndex;

        // 当需要显示的页面索引大于等于总页面时，切换至首页
        if (nIndex == 5)
            nIndex = 0;

       ui->stackedWidget->setCurrentIndex(nIndex);
}

void PigGame::on_btn_frontpage_clicked()
{
    int nIndex = ui->stackedWidget->currentIndex();

        // 获取下一个需要显示的页面索引
        --nIndex;

        // 当需要显示的页面索引大于等于总页面时，切换至首页
        if (nIndex == -1)
            nIndex = 4;

       ui->stackedWidget->setCurrentIndex(nIndex);
}
void PigGame::goout()//chu lan
{
    qDebug()<<"go out";
    sum_money = 0;
    int hua=0,bai = 0,hei = 0;;
    int numpig = 0;
    *p = *head;
    //grow shuiji
    for(int i = 0;i<100;i++)
    {
        for(int K=0;K<10;K++)
        {
            if((p->data[K][1]>=750||p->data[K][2]>360)&&p->data[K][0]<=3&&p->data[K][3]==0)//一个月30天//注意：要该猪不是空，且未被感染
            {
                numpig ++;
                if(p->data[K][0]==1)
                    sum_money += 7*p->data[K][1]/10;
                if(p->data[K][0]==2)
                    sum_money += 6*p->data[K][1]/10;
                if(p->data[K][0]==3)
                    sum_money += 15*p->data[K][1]/10;
                if(p->type == false)
                {
                qsrand(QTime(0,0,0).secsTo(QTime::currentTime())+K*10000+i);
                p->data[K][0]=qrand()%2+1;
                if(p->data[K][0] == 1)
                    hua++;
                if(p->data[K][0] == 2)
                    bai++;
                qsrand(QTime(0,0,0).secsTo(QTime::currentTime())+K*100+i);
                p->data[K][1]=qrand()%300+200;
                p->data[K][2]=1;
                p->data[K][3]=0;
                p->data[K][4]=0;
                }
                else
                {
                    hei++;
                    p->data[K][0]=3;
                    qsrand(QTime(0,0,0).secsTo(QTime::currentTime())+K*100+i);
                    p->data[K][1]=qrand()%300+200;
                    p->data[K][2]=1;
                    p->data[K][3]=0;
                    p->data[K][4]=0;
                }
            }
        }

        p=p->N;
    }
    //MainWindow::savefile_chulan(QString::number(sum)+"|"+QString::number(numpig)+"|"+QString::number(hua)+"|"+QString::number(bai)+"|"+QString::number(hei));
    //MainWindow::savefile_zhuangtai("a");
    QString ab = QString::number(sum_money) + "|" +QString::number(numpig);//返回，一会用正则表达式搞一波           //还有天数没弄
}
