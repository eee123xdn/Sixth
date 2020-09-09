#ifndef PAGE4_H
#define PAGE4_H

#include <QWidget>

namespace Ui {
class page4;
}

class page4 : public QWidget
{
    Q_OBJECT

public:
    explicit page4(QWidget *parent = nullptr);
    ~page4();

private:
    Ui::page4 *ui;
};

#endif // PAGE4_H
