#include "MyPushButton.h"

MyPushButton::MyPushButton(QString province)
{
    this->province= province;
    init();
}

void MyPushButton::init()
{
    QSqlQuery query;

    int ret=0;
    query.exec("select count(1) from student where 1=1 and province = '"+province+"' ");

    count=ret;

}
