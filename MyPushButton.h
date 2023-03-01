#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QSqlQuery>

class MyPushButton: public QPushButton
{
public:
    MyPushButton(QString province);
    void init();

    QString province;
    int count;
};

#endif // MYPUSHBUTTON_H
