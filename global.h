#ifndef GLOBAL_H
#define GLOBAL_H

#include<iostream>
#include <QWidget>
class Global : public QObject
{
    Q_OBJECT
public:
    explicit Global(QObject *parent = nullptr);
    static std::string fileName;
    static int hashCnt;
    static int hashTime;
    static int biCnt;
    static int biTime;
};


#endif // GLOBAL_H
