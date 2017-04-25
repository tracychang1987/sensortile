#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"win_qextserialport.h"


#ifdef   _DL645_GLOBALS
    #define  DL645_EXT
#else
    #define  DL645_EXT extern
#endif

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    Win_QextSerialPort *myCom; //声明对象

private slots:
    void readMyCom();         //声明读串口槽函数
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_9_clicked();
    void on_toolButton_clicked();
    void on_pushButton_clicked();
};

typedef struct
{
    unsigned int GP1;
    unsigned int Gphs1;
    unsigned int P1OFF;
  unsigned int I1RMSOFFSET;
    unsigned int I2RMSOFFSET;
    unsigned int Power;
}FirmPara_Tyepdef;

DL645_EXT FirmPara_Tyepdef Dl645RN8209D_data;
DL645_EXT FirmPara_Tyepdef Signal_box;
#endif // MAINWINDOW_H
