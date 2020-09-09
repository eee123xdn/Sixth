#include "page4.h"
#include "ui_page4.h"

page4::page4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page4)
{
    ui->setupUi(this);
}

page4::~page4()
{
    delete ui;
}
