#include "honor.h"
#include "ui_honor.h"

honor::honor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::honor)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);
}

honor::~honor()
{
    delete ui;
}

void honor::on_pushButton_clicked()
{
    this->close();
}
