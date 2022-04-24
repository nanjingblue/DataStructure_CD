#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include "mainweight.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void bindingSignals();

private slots:
    void onSelectBtnClicked();
    void onStartBtnClicked();
private:
    Ui::Widget *ui;
    MainWeight *start;
};
#endif // WIDGET_H
