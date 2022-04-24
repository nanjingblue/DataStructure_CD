#include "hashweight.h"
#include "ui_hashweight.h"
#include "Hash/include/hash_procress.h"
#include "global.h"
#include <QDebug>

HashWeight::HashWeight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HashWeight)
{
    ui->setupUi(this);
    setTableWeight();
    goHash();
}

HashWeight::~HashWeight()
{
    delete ui;
}

void HashWeight::setTableWeight()
{
    //设置表格的列数，必须要先设置，不然表格显示不出来
        ui->tableWidget->setColumnCount(2);
        //建立表头
        QStringList header;
        header << "关键字" << "频度";
        ui->tableWidget->setHorizontalHeaderLabels(header);
        //设置表头显示模式,这里设置的是拉伸模式
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        // 设置默认行高
        ui->tableWidget->verticalHeader()->setDefaultSectionSize(50);
        // 设置隔行变色
        ui->tableWidget->setAlternatingRowColors(true);
        //设置行高不可变动，即不能通过鼠标拖动增加列宽
        ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
        // 设置自适应列宽
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); // 选中时整行选中
}

void HashWeight::goHash()
{
    string fileName = Global::fileName;
    HashTable<string, int>hashTable;
    qDebug() << "hash " << QString::fromStdString(Global::fileName);
    Hash::readToHashTable(hashTable, fileName);
    Global::hashCnt = Hash::getHashCompareCnt(hashTable);
    Global::hashTime = Hash::getHashCompareTime(hashTable);
    qDebug() << "hash " << Global::hashCnt;
    hashTable.hashSort();
    for (int i = HASHMAXSIZE - 1; i >= 0; --i) {
        if (hashTable.data[i].stat != VALID) continue;
        int rowCount = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rowCount);
        ui->tableWidget->setItem(rowCount,0,new QTableWidgetItem(QString::fromStdString(hashTable.data[i].key)));
        ui->tableWidget->setItem(rowCount,1,new QTableWidgetItem(QString::number(hashTable.data[i].value)));
        // 设置文字居中
        ui->tableWidget->item(rowCount, 0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget->item(rowCount, 1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    }
}
