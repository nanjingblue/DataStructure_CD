#include "cmpweight.h"
#include "ui_cmpweight.h"
#include "global.h"
#include <QDebug>

CmpWeight::CmpWeight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CmpWeight)
{
    qDebug() << Global::hashCnt;
    ui->setupUi(this);
    ui->edit_hashCnt->setText(QString::number(Global::hashCnt));
    ui->edit_hashTime->setText(QString::number(Global::hashTime));
    ui->edit_biCnt->setText(QString::number(Global::biCnt));
    ui->edit_biTime->setText(QString::number(Global::biTime));
}

CmpWeight::~CmpWeight()
{
    delete ui;
}
