#ifndef HASHWEIGHT_H
#define HASHWEIGHT_H

#include <QWidget>
#include <QFile>
#include <QTextStream>

namespace Ui {
class HashWeight;
}

class HashWeight : public QWidget
{
    Q_OBJECT

public:
    explicit HashWeight(QWidget *parent = nullptr);
    ~HashWeight();
    void setTableWeight();
    void goHash();

private:
    Ui::HashWeight *ui;
};

#endif // HASHWEIGHT_H
