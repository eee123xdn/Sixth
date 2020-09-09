#include "config.h"
#include "ui_config.h"
#include<piggame.h>
#include<QMessageBox>
config::config(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::config)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);

}

config::~config()
{
    delete ui;
}

void config::on_pushButton_3_clicked()
{
    int ret = QMessageBox::information(this,"提示","你确定要修改设置吗？","确定","取消");
    if(!ret)
    {
    this->close();
    }
}

void config::on_pushButton_2_clicked()
{
    int ret = QMessageBox::critical(this,"警告","你确定要退出游戏吗？","确定","取消");
    if(!ret)
    {
        exit(0);
    }
}

void config::on_pushButton_4_clicked()
{
    int ret = QMessageBox::information(this,"提示","你确定要放弃修改的设置吗？","确定","取消");
    if(!ret)
    {
    this->close();
    }
}
