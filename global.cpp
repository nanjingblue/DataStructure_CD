#include "global.h"


Global::Global(QObject *parent) : QObject(parent)
{

}

std::string Global::fileName = "";
int Global::hashCnt = 0;
int Global::hashTime = 0;
int Global::biCnt = 0;
int Global::biTime = 0;
