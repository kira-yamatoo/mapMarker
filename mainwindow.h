#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QSqlTableModel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void provinceSelect(QString province);
    int provinceCount(QString province);
    bool isReset;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();




    void on_pushButton_xinjiang_clicked();

    void on_pushButton_xizang_clicked();

    void on_pushButton_gansu_clicked();

    void on_pushButton_qinghai_clicked();

    void on_pushButton_sichuan_clicked();

    void on_pushButton_yunnan_clicked();

    void on_pushButton_neimenggu_clicked();

    void on_pushButton_ningxia_clicked();

    void on_pushButton_shanxi_clicked();

    void on_pushButton_chongqing_clicked();

    void on_pushButton_guizhou_clicked();

    void on_pushButton_guangxi_clicked();

    void on_pushButton_shanxiyi_clicked();

    void on_pushButton_henan_clicked();

    void on_pushButton_hubei_clicked();

    void on_pushButton_hunan_clicked();

    void on_pushButton_guangdong_clicked();

    void on_pushButton_aomen_clicked();

    void on_pushButton_xianggang_clicked();

    void on_pushButton_hainan_clicked();

    void on_pushButton_hebei_clicked();

    void on_pushButton_shandong_clicked();

    void on_pushButton_anhui_clicked();

    void on_pushButton_jiangsu_clicked();

    void on_pushButton_jiangxi_clicked();

    void on_pushButton_zhejiang_clicked();

    void on_pushButton_fujian_clicked();

    void on_pushButton_shanghai_clicked();

    void on_pushButton_taiwan_clicked();

    void on_pushButton_heilongjiang_clicked();

    void on_pushButton_jilin_clicked();

    void on_pushButton_liaoning_clicked();

    void on_pushButton_beijing_clicked();

    void on_pushButton_tianjin_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
};

#endif // MAINWINDOW_H
