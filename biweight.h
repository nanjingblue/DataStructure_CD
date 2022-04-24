#ifndef BIWEIGHT_H
#define BIWEIGHT_H

#include <QWidget>

namespace Ui {
class BiWeight;
}

class BiWeight : public QWidget
{
    Q_OBJECT

public:
    explicit BiWeight(QWidget *parent = nullptr);
    ~BiWeight();
    void setTableWeight();
    void goBi();

private:
    Ui::BiWeight *ui;
};

#endif // BIWEIGHT_H
