#include "mainweight.h"
#include "ui_mainweight.h"
#include <QDir>
#include <QProcess>

MainWeight::MainWeight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWeight)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/icon.png"));
    this->setWindowTitle("数据结构课程设计——20190408");

    this->hashWeight = new HashWeight(ui->stackedWidget);
    this->biWeight = new BiWeight(ui->stackedWidget);
    this->cmpWeight = new CmpWeight(ui->stackedWidget);

    ui->stackedWidget->addWidget(this->hashWeight);
    ui->stackedWidget->addWidget(this->biWeight);
    ui->stackedWidget->addWidget(this->cmpWeight);

    ui->stackedWidget->setCurrentWidget(this->hashWeight);
}

MainWeight::~MainWeight()
{
    delete ui;
}


void MainWeight::on_btn_hash_clicked()
{
    ui->stackedWidget->setCurrentWidget(this->hashWeight);
}


void MainWeight::on_btn_bi_clicked()
{
    ui->stackedWidget->setCurrentWidget(this->biWeight);
}


void MainWeight::on_btn_cmp_clicked()
{
    ui->stackedWidget->setCurrentWidget(this->cmpWeight);
}


void MainWeight::on_btn_back_clicked()
{
        QString program = QApplication::applicationFilePath();
        QStringList arguments = QApplication::arguments();
        QString workingDirectory = QDir::currentPath();
        QProcess::startDetached(program, arguments, workingDirectory);
        QApplication::exit();

}

