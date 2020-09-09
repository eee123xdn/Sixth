#include "page5.h"
#include "ui_page5.h"

page5::page5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page5)
{
    ui->setupUi(this);
}

page5::~page5()
{
    delete ui;
}
