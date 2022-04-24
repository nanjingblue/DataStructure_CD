#include "widget.h"
#include "ui_widget.h"
#include "global.h"
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/icon.png"));
    this->setWindowTitle("数据结构课程设计——20190408");
    // 绑定
    bindingSignals();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::bindingSignals()
{
    connect(ui->btn_select, SIGNAL(clicked()), this, SLOT(onSelectBtnClicked()));
    connect(ui->btn_start, SIGNAL(clicked()), this, SLOT(onStartBtnClicked()));
}

void Widget::onSelectBtnClicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("文件对话框！"),"F:",QStringLiteral("C语言文件(*h *c *cpp);;""文本文件(*txt)"));
    this->ui->lineEdit->setText(fileName);
    Global::fileName = fileName.toStdString();
}

void Widget::onStartBtnClicked()
{
    qDebug() << QString::fromStdString(Global::fileName);
    if (Global::fileName == "") {
        QMessageBox::information(this, "运行", "请先选择文件");
        return;
    }
    this->start = new MainWeight;
    this->close();
    this->start->show();
}

