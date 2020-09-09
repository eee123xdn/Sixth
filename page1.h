#ifndef PAGE1_H
#define PAGE1_H

#include <QWidget>

namespace Ui {
class page1;
}

class page1 : public QWidget
{
    Q_OBJECT

public:
    explicit page1(QWidget *parent = nullptr);
    ~page1();

private:
    Ui::page1 *ui;
};

#endif // PAGE1_H
