#ifndef PAGE5_H
#define PAGE5_H

#include <QWidget>

namespace Ui {
class page5;
}

class page5 : public QWidget
{
    Q_OBJECT

public:
    explicit page5(QWidget *parent = nullptr);
    ~page5();

private:
    Ui::page5 *ui;
};

#endif // PAGE5_H
