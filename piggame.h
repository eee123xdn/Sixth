#ifndef PIGGAME_H
#define PIGGAME_H

#include <QMainWindow>
#include<page1.h>
namespace Ui {
class PigGame;
}
class Node
{
public:
    Node()
    {
     ;
    }
    int number,data[15][5],kind[3][6];
    //1 = hua 2 = write 3 =blake;
    int type;
    bool flag;
    Node *F,*N;
};
extern Node *p,*head,*tail;
extern int sum,day,money,sum_money;
class PigGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit PigGame(QWidget *parent = nullptr);
    ~PigGame();
public slots:
    void goout();
    void new_game();
private slots:
    void on_btn_config_clicked();

    void on_btn_store_clicked();

    void on_btn_honor_clicked();

    void on_btn_nextpage_clicked();

    void on_btn_frontpage_clicked();

private:
    Ui::PigGame *ui;
};

#endif // PIGGAME_H
