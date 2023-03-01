#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("my.db");
    if (!db.open()) {
        QMessageBox::critical(0, "Cannot open database1",
                              "Unable to establish a database connection.", QMessageBox::Cancel);
        return false;
    }
    QSqlQuery query;

    // 创建student表
    query.exec("create table student (id int primary key, "
                       "name varchar, province varchar, city varchar, phone varchar, remark varchar)");
    query.exec("insert into student values(1, '张三', '广州', '越秀区', '233','备注123' )");
    query.exec("insert into student values(2, '李四', '新疆', '','514','备注123' )");
    query.exec("insert into student values(3, '王五', '浙江', '杭州','115','备注123' )");


    return true;
}

#endif // CONNECTION_H
