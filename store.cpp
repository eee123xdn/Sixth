#include "store.h"
#include "ui_store.h"

store::store(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::store)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);

}

store::~store()
{
    delete ui;
}

void store::on_pushButton_2_clicked()
{
    this->close();
}
