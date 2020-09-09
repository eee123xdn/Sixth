#include "startgame.h"
#include "piggame.h"
#include <QApplication>
#include<piggame.h>
int sum=0,day=0,money=0,sum_money=0;
Node *p =  new Node(),*head =  new Node(),*tail =  new Node();
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartGame w;
    w.show();
    return a.exec();
}
