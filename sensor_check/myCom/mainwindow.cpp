#define  _DL645_GLOBALS

#include "mainwindow.h"
#include "ui_mainwindow.h"

QString str;
QByteArray GP1_play;
    QString buf,strr;

QString I2RMSOFFSET_comBuff[]="68 14 15";
//QString Power_comBuff[]="68 AA AA AA AA AA AA 68 11 07 34 23 21 21 59 33 37 40 16";
QString IRMSI1_comBuff[]="68 AA AA AA AA AA AA 68 11 07 34 23 21 21 55 33 36 3B 16";

int GP1_comBuff[]     =   {0x68,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0x68,0x11,0x07,0x34,0x23,0x21,0x21,0x38,0x33,0x35,0x1d,0x16};
int Gphs1_comBuff[]   =   {0x68,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0x68,0x11,0x07,0x34,0x23,0x21,0x21,0x3A,0x33,0x34,0x1e,0x16};
int P1OFF_comBuff[]   =   {0x68,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0x68,0x11,0x07,0x34,0x23,0x21,0x21,0x3d,0x33,0x35,0x22,0x16};
int I1RMSOFFSET_comBuff[]={0x68,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0x68,0x11,0x07,0x34,0x23,0x21,0x21,0x41,0x33,0x35,0x26,0x16};
int Power_comBuff[]   =   {0x68,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0x68,0x11,0x07,0x34,0x23,0x21,0x21,0x59,0x33,0x37,0x40,0x16};

//int com_num;
int i;
int Receive_Flag;
int Length;
QByteArray temp;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    str.clear();

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readMyCom() //读串口函数
{
    if(myCom->bytesAvailable())
    {
        buf.clear();
     temp = myCom->read(36);           //读取串口缓冲区的所有数据给临时变
    GP1_play=temp;
       ui->textBrowser->setText(temp);
    if((Signal_box.GP1==1)||(Signal_box.P1OFF==1)||(Signal_box.I1RMSOFFSET==1))
    {
        Receive_Flag=1;
    }

    //if((Signal_box.GP1==1)&&(Receive_Flag==1))///比如GP1是2个字节
    {
        Signal_box.GP1=0;
        Receive_Flag=0;
        //if(com_num==2)
        {
            Dl645RN8209D_data.GP1 = (((temp.data()[19]-0x33)<<8)|(GP1_play.data()[18]-0x33))&0x0000ffff;
         //  QString s2 = QString::number(n, 16).toUpper();
            QString s2= QString("%1").arg(Dl645RN8209D_data.GP1, 4, 16, QChar('0'));
            ui->textBrowser_2->setText(s2);
            //com_num=0;
        }
    }
     if(Signal_box.Gphs1==1)//Gphs1是1个字节
    {
        Signal_box.Gphs1=0;
        Dl645RN8209D_data.Gphs1 = (GP1_play.data()[18]-0x33)&0x000000ff;
        QString s2= QString("%1").arg(Dl645RN8209D_data.Gphs1, 2, 16, QChar('0'));
        ui->textBrowser_3->setText(s2);
    }
    else if((Signal_box.P1OFF==1)&&(Receive_Flag==1))//P1OFFSET 功率偏移 2个字节
    {
        Signal_box.P1OFF=0;
        Receive_Flag=0;
        Dl645RN8209D_data.P1OFF = (((temp.data()[19]-0x33)<<8)|((GP1_play.data()[18]-0x33)&0X00FF))&0x0000ffff;
        QString s2= QString("%1").arg(Dl645RN8209D_data.P1OFF, 4, 16, QChar('0'));
        ui->textBrowser_4->setText(s2);
    }
    else if((Signal_box.I1RMSOFFSET==1)&&(Receive_Flag==1))//I1RMSOFFSET第一通道电流有效值偏移 2个字节
    {
        Signal_box.I1RMSOFFSET=0;
        Receive_Flag=0;
        Dl645RN8209D_data.I1RMSOFFSET = (((temp.data()[19]-0x33)<<8)|((GP1_play.data()[18]-0x33)&0X00FF))&0x0000ffff;
        QString s2= QString("%1").arg(Dl645RN8209D_data.I1RMSOFFSET, 4, 16, QChar('0'));
        ui->textBrowser_5->setText(s2);
    }
    else if(Signal_box.Power==1)//Power_P1 0x26 功率有效值 4个字节
    {
        Signal_box.Power=0;
        Dl645RN8209D_data.Power = ((((temp.data()[21]-0x33)<<24)&0xff000000)|(((GP1_play.data()[20]-0x33)<<16)&0X00FF0000)|(((GP1_play.data()[19]-0x33)<<8)&0X0000FF00)|((GP1_play.data()[18]-0x33)&0X000000FF))&0xffffffff;
        QString s2= QString("%1").arg(Dl645RN8209D_data.Power, 8, 16, QChar('0'));
        ui->textBrowser_11->setText(s2);
    }
    QDataStream out(&temp,QIODevice::ReadWrite);


      while(!out.atEnd())
      {
           qint8 outChar=0;
           out>>outChar;
           strr =QString("%1").arg(outChar&0xFF,2,16,QLatin1Char('0')).toUpper()+QString(tr(" "));
           buf+=strr;
      }
      ui->textBrowser->append("\b");
      ui->textBrowser->insertPlainText(buf);

    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int i;
    str.clear();
    Signal_box.GP1=1;
    Length=22;
    for(i=0;i<19;i++)
    {
        str.append(QChar(*(GP1_comBuff+i)));

    }
    myCom->write(str.toLatin1());
}

void MainWindow::on_pushButton_3_clicked()
{
    int i;
    str.clear();
    Signal_box.Gphs1=1;
    Length=21;
    for(i=0;i<19;i++)
    {
        str.append(QChar(*(Gphs1_comBuff+i)));
    }
    myCom->write(str.toLatin1());
}

void MainWindow::on_pushButton_4_clicked()
{
    int i;
    str.clear();
    Signal_box.P1OFF=1;
    Length=22;
    for(i=0;i<19;i++)
    {
        str.append(QChar(*(P1OFF_comBuff+i)));
    }
    myCom->write(str.toLatin1());
}

void MainWindow::on_pushButton_5_clicked()
{
    int i;
    str.clear();
    Signal_box.I1RMSOFFSET=1;
     Length=22;
    for(i=0;i<19;i++)
    {
        str.append(QChar(*(I1RMSOFFSET_comBuff+i)));
    }
    myCom->write(str.toLatin1());
}

void MainWindow::on_pushButton_9_clicked()
{
    int i;
    str.clear();
    Signal_box.Power=1;
    Length=24;
    for(i=0;i<19;i++)
    {
        str.append(QChar(*(Power_comBuff+i)));
    }
    myCom->write(str.toLatin1());
}

void MainWindow::on_toolButton_clicked()
{
    //ui->textBrowser->setText(" ");
    ui->textBrowser->clear();
}

void MainWindow::on_pushButton_clicked()//串口打开关闭按键
{
    i++;
    if(i%2==1)
    {
        ui->pushButton->setText("串口关闭");
    }
    else
    {
        ui->pushButton->setText("串口打开");
    }
    if(ui->pushButton->text()==QStringLiteral("串口关闭"))//如果串口处于打开状态不允许修改
    {
        ui->PortName_comboBox->setEnabled(false);
        ui->BaudRate_comboBox->setEnabled(false);
        ui->DataBits_comboBox->setEnabled(false);
        ui->StopBits_comboBox->setEnabled(false);
        ui->Parity_comboBox->setEnabled(false);
        QString portName = ui->PortName_comboBox->currentText(); //获取串口名
        myCom = new Win_QextSerialPort(portName,QextSerialBase::EventDriven);


        myCom ->open(QIODevice::ReadWrite);//就是因为这句放在了new的前面，所以每次都异常退出


        if(ui->BaudRate_comboBox ->currentText()==tr("2400")) //根据组合框内容对串口
        {
            myCom->setBaudRate(BAUD2400);
        }
        else if(ui->BaudRate_comboBox->currentText()==tr("9600")) //根据组合框内容对串口
        {
            myCom->setBaudRate(BAUD9600);
        }

        if(ui->DataBits_comboBox->currentText()==tr("8"))
        {
            myCom->setDataBits(DATA_8);
        }

        if(ui->Parity_comboBox->currentText()==QStringLiteral("EVEN"))
        myCom->setParity(PAR_EVEN);

        if(ui->StopBits_comboBox->currentText()==tr("1"))

     myCom->setStopBits(STOP_1);

        myCom->setFlowControl(FLOW_OFF); //设置数据流控制，我们使用无数据流控制的默认设置
        myCom->setTimeout(500); //设置延时

        //以可读写方式打开串口
        connect(myCom,SIGNAL(readyRead()),this,SLOT(readMyCom()));
    }
    else  if(ui->pushButton->text()==QStringLiteral("串口打开"))
    {
        ui->PortName_comboBox->setEnabled(true);
        ui->BaudRate_comboBox->setEnabled(true);
        ui->DataBits_comboBox->setEnabled(true);
        ui->StopBits_comboBox->setEnabled(true);
        ui->Parity_comboBox->setEnabled(true);

    }
}
