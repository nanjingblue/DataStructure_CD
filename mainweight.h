#ifndef MAINWEIGHT_H
#define MAINWEIGHT_H

#include <QWidget>
#include "hashweight.h"
#include "biweight.h"
#include "cmpweight.h"

namespace Ui {
class MainWeight;
}

class MainWeight : public QWidget
{
    Q_OBJECT

public:
    explicit MainWeight(QWidget *parent = nullptr);
    ~MainWeight();
    void bindingSignals();

private slots:
    void on_btn_hash_clicked();

    void on_btn_bi_clicked();

    void on_btn_cmp_clicked();

    void on_btn_back_clicked();

private:
    Ui::MainWeight *ui;
    HashWeight *hashWeight;
    BiWeight *biWeight;
    CmpWeight *cmpWeight;
};

#endif // MAINWEIGHT_H
