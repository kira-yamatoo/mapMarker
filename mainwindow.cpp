#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QTableView>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);
    model->setTable("student");
    model->select();

    // 设置编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);

    //重置flag
    isReset=0;

    //设置count标签
    ui->label_xinjiang->setText(QString::number(provinceCount("新疆")));
    ui->label_xinjiang->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->label_xinjiang->setAttribute(Qt::WA_TransparentForMouseEvents);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 提交修改按钮
void MainWindow::on_pushButton_clicked()
{
    // 开始事务操作
    model->database().transaction();
    if (model->submitAll()) {
        if(model->database().commit()) // 提交
            QMessageBox::information(this, tr("tableModel"),
                                     tr("数据修改成功！"));
    } else {
        model->database().rollback(); // 回滚
        QMessageBox::warning(this, tr("tableModel"),
                             tr("数据库错误: %1").arg(model->lastError().text()),
                             QMessageBox::Ok);
    }
}

// 撤销修改按钮
void MainWindow::on_pushButton_2_clicked()
{
    model->revertAll();
}

// 查询按钮，进行筛选
void MainWindow::on_pushButton_5_clicked()
{
    QString name = ui->lineEdit->text();

    // 根据姓名进行筛选，一定要使用单引号
    model->setFilter(QString("name = '%1'").arg(name));
    model->select();
}

// 显示全表按钮
void MainWindow::on_pushButton_6_clicked()
{
    model->setTable("student");
    model->select();
}

// 按id升序排列按钮
void MainWindow::on_pushButton_7_clicked()
{
    //id字段，即第0列，升序排列
    model->setSort(2, Qt::AscendingOrder);
    model->select();

}

// 按id降序排列按钮
void MainWindow::on_pushButton_8_clicked()
{
    model->setSort(2, Qt::DescendingOrder);
    model->select();

}
// 删除选中行按钮
void MainWindow::on_pushButton_4_clicked()
{
    // 获取选中的行
    int curRow = ui->tableView->currentIndex().row();

    // 删除该行
    model->removeRow(curRow);
    int ok = QMessageBox::warning(this,tr("删除当前行!"),
                                  tr("你确定删除当前行吗？"), QMessageBox::Yes, QMessageBox::No);
    if(ok == QMessageBox::No)
    { // 如果不删除，则撤销
        model->revertAll();
    } else { // 否则提交，在数据库中删除该行
        model->submitAll();
    }

}
// 添加记录按钮
void MainWindow::on_pushButton_3_clicked()
{
    model->setTable("student");
    model->select();

    // 获得表的行数
    int rowNum = model->rowCount();
    int id = rowNum+1;

    // 添加一行
    model->insertRow(rowNum);
    model->setData(model->index(rowNum, 0), id);

    // 可以直接提交
    //model->submitAll();
}


void MainWindow::provinceSelect(QString province)
{
    // 根据省份进行过滤
    if(!isReset){
        model->setFilter(QString("province = '%1'").arg(province));
        model->select();

        isReset=1;
    }
    else{
        model->setTable("student");
        model->select();

        isReset=0;
    }

}

int MainWindow::provinceCount(QString province)
{
    // 根据省份进行过滤
    model->setFilter(QString("province = '%1'").arg(province));
    model->select();
    int count= model->rowCount();

    model->setTable("student");
    model->select();

    return count;
}

//---------------------------button-----------------------------------
void MainWindow::on_pushButton_xinjiang_clicked()
{
    provinceSelect("新疆");
}

void MainWindow::on_pushButton_xizang_clicked()
{
    provinceSelect("西藏");
}

void MainWindow::on_pushButton_gansu_clicked()
{
    provinceSelect("甘肃");
}

void MainWindow::on_pushButton_qinghai_clicked()
{
    provinceSelect("青海");
}

void MainWindow::on_pushButton_sichuan_clicked()
{
    provinceSelect("四川");
}

void MainWindow::on_pushButton_yunnan_clicked()
{
    provinceSelect("云南");
}

void MainWindow::on_pushButton_neimenggu_clicked()
{
    provinceSelect("内蒙古");
}

void MainWindow::on_pushButton_ningxia_clicked()
{
    provinceSelect("宁夏");
}

void MainWindow::on_pushButton_shanxi_clicked()
{
    provinceSelect("陕西");
}

void MainWindow::on_pushButton_chongqing_clicked()
{
    provinceSelect("重庆");
}

void MainWindow::on_pushButton_guizhou_clicked()
{
    provinceSelect("贵州");
}

void MainWindow::on_pushButton_guangxi_clicked()
{
    provinceSelect("广西");
}

void MainWindow::on_pushButton_shanxiyi_clicked()
{
    provinceSelect("山西");
}

void MainWindow::on_pushButton_henan_clicked()
{
    provinceSelect("河南");
}

void MainWindow::on_pushButton_hubei_clicked()
{
    provinceSelect("湖北");
}

void MainWindow::on_pushButton_hunan_clicked()
{
    provinceSelect("湖南");
}

void MainWindow::on_pushButton_guangdong_clicked()
{
    provinceSelect("广东");
}

void MainWindow::on_pushButton_aomen_clicked()
{
    provinceSelect("澳门");
}

void MainWindow::on_pushButton_xianggang_clicked()
{
    provinceSelect("香港");
}

void MainWindow::on_pushButton_hainan_clicked()
{
    provinceSelect("海南");
}

void MainWindow::on_pushButton_hebei_clicked()
{
    provinceSelect("河北");
}

void MainWindow::on_pushButton_shandong_clicked()
{
    provinceSelect("山东");
}

void MainWindow::on_pushButton_anhui_clicked()
{
    provinceSelect("安徽");
}

void MainWindow::on_pushButton_jiangsu_clicked()
{
    provinceSelect("江苏");
}

void MainWindow::on_pushButton_jiangxi_clicked()
{
    provinceSelect("江西");
}

void MainWindow::on_pushButton_zhejiang_clicked()
{
    provinceSelect("浙江");
}

void MainWindow::on_pushButton_fujian_clicked()
{
    provinceSelect("福建");
}

void MainWindow::on_pushButton_shanghai_clicked()
{
    provinceSelect("上海");
}

void MainWindow::on_pushButton_taiwan_clicked()
{
    provinceSelect("台湾");
}

void MainWindow::on_pushButton_heilongjiang_clicked()
{
    provinceSelect("黑龙江");
}

void MainWindow::on_pushButton_jilin_clicked()
{
    provinceSelect("吉林");
}

void MainWindow::on_pushButton_liaoning_clicked()
{
    provinceSelect("辽宁");
}

void MainWindow::on_pushButton_beijing_clicked()
{
    provinceSelect("北京");
}

void MainWindow::on_pushButton_tianjin_clicked()
{
    provinceSelect("天津");
}
