#ifndef CMPWEIGHT_H
#define CMPWEIGHT_H

#include <QWidget>

namespace Ui {
class CmpWeight;
}

class CmpWeight : public QWidget
{
    Q_OBJECT

public:
    explicit CmpWeight(QWidget *parent = nullptr);
    ~CmpWeight();

private:
    Ui::CmpWeight *ui;
};

#endif // CMPWEIGHT_H
