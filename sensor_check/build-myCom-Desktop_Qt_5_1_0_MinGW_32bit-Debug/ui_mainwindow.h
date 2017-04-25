/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QComboBox *PortName_comboBox;
    QComboBox *BaudRate_comboBox;
    QComboBox *Parity_comboBox;
    QComboBox *DataBits_comboBox;
    QComboBox *StopBits_comboBox;
    QToolButton *toolButton;
    QPushButton *pushButton_2;
    QTextBrowser *textBrowser_2;
    QPushButton *pushButton_3;
    QTextBrowser *textBrowser_3;
    QPushButton *pushButton_4;
    QTextBrowser *textBrowser_4;
    QPushButton *pushButton_5;
    QTextBrowser *textBrowser_5;
    QPushButton *pushButton_6;
    QTextBrowser *textBrowser_6;
    QTextBrowser *textBrowser_7;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QTextBrowser *textBrowser_10;
    QPushButton *pushButton_9;
    QTextBrowser *textBrowser_11;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(616, 508);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 0, 101, 31));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 240, 581, 231));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 30, 51, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(11);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(70, 30, 71, 171));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        PortName_comboBox = new QComboBox(verticalLayoutWidget_2);
        PortName_comboBox->setObjectName(QStringLiteral("PortName_comboBox"));
        PortName_comboBox->setEditable(true);

        verticalLayout_2->addWidget(PortName_comboBox);

        BaudRate_comboBox = new QComboBox(verticalLayoutWidget_2);
        BaudRate_comboBox->setObjectName(QStringLiteral("BaudRate_comboBox"));
        BaudRate_comboBox->setEditable(true);

        verticalLayout_2->addWidget(BaudRate_comboBox);

        Parity_comboBox = new QComboBox(verticalLayoutWidget_2);
        Parity_comboBox->setObjectName(QStringLiteral("Parity_comboBox"));
        Parity_comboBox->setEditable(true);

        verticalLayout_2->addWidget(Parity_comboBox);

        DataBits_comboBox = new QComboBox(verticalLayoutWidget_2);
        DataBits_comboBox->setObjectName(QStringLiteral("DataBits_comboBox"));
        DataBits_comboBox->setEditable(true);

        verticalLayout_2->addWidget(DataBits_comboBox);

        StopBits_comboBox = new QComboBox(verticalLayoutWidget_2);
        StopBits_comboBox->setObjectName(QStringLiteral("StopBits_comboBox"));
        StopBits_comboBox->setEditable(false);

        verticalLayout_2->addWidget(StopBits_comboBox);

        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(20, 200, 101, 31));
        QFont font1;
        font1.setUnderline(true);
        toolButton->setFont(font1);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 40, 131, 31));
        textBrowser_2 = new QTextBrowser(centralWidget);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(310, 40, 61, 31));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 80, 131, 31));
        textBrowser_3 = new QTextBrowser(centralWidget);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(310, 80, 61, 31));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(170, 120, 131, 31));
        textBrowser_4 = new QTextBrowser(centralWidget);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(310, 120, 61, 31));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(170, 160, 131, 31));
        textBrowser_5 = new QTextBrowser(centralWidget);
        textBrowser_5->setObjectName(QStringLiteral("textBrowser_5"));
        textBrowser_5->setGeometry(QRect(310, 160, 61, 31));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(390, 40, 131, 31));
        textBrowser_6 = new QTextBrowser(centralWidget);
        textBrowser_6->setObjectName(QStringLiteral("textBrowser_6"));
        textBrowser_6->setGeometry(QRect(530, 40, 61, 31));
        textBrowser_7 = new QTextBrowser(centralWidget);
        textBrowser_7->setObjectName(QStringLiteral("textBrowser_7"));
        textBrowser_7->setGeometry(QRect(530, 80, 61, 31));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(390, 80, 131, 31));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(390, 120, 131, 31));
        textBrowser_10 = new QTextBrowser(centralWidget);
        textBrowser_10->setObjectName(QStringLiteral("textBrowser_10"));
        textBrowser_10->setGeometry(QRect(530, 120, 61, 31));
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(390, 160, 131, 31));
        textBrowser_11 = new QTextBrowser(centralWidget);
        textBrowser_11->setObjectName(QStringLiteral("textBrowser_11"));
        textBrowser_11->setGeometry(QRect(530, 160, 61, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 616, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\346\211\223\345\274\200", 0));
        label_2->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267", 0));
        label->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", 0));
        label_3->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", 0));
        label_4->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", 0));
        label_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", 0));
        PortName_comboBox->clear();
        PortName_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "COM1", 0)
         << QApplication::translate("MainWindow", "COM2", 0)
         << QApplication::translate("MainWindow", "COM3", 0)
         << QApplication::translate("MainWindow", "COM4", 0)
        );
        BaudRate_comboBox->clear();
        BaudRate_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "2400", 0)
         << QApplication::translate("MainWindow", "9600", 0)
         << QApplication::translate("MainWindow", "115200", 0)
        );
        Parity_comboBox->clear();
        Parity_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "EVEN", 0)
         << QApplication::translate("MainWindow", "NONE", 0)
         << QApplication::translate("MainWindow", "ODD", 0)
        );
        DataBits_comboBox->clear();
        DataBits_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "8", 0)
         << QApplication::translate("MainWindow", "7", 0)
        );
        StopBits_comboBox->clear();
        StopBits_comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "2", 0)
        );
        toolButton->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\346\212\245\346\226\207", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "GP1\347\254\254\344\270\200\351\200\232\351\201\223\346\234\211\345\212\237\345\242\236\347\233\212", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "GPhs1\346\234\211\345\212\237\347\233\270\344\275\215\350\241\245\345\201\277", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "P1OFF\344\270\200\351\200\232\351\201\223\345\212\237\347\216\207\345\201\217\347\247\273", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "I1RMS\347\224\265\346\265\201\346\234\211\346\225\210\345\200\274\345\201\217\347\247\273", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "I2RMS\347\224\265\346\265\201\346\234\211\346\225\210\345\200\274\345\201\217\347\247\273", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "HFCONST\350\204\211\345\206\262\345\270\270\346\225\260", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "PQstart\345\220\257\345\212\250\345\212\237\347\216\207", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "POWER\345\212\237\347\216\207\346\234\211\346\225\210\345\200\274", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
