/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *eChord;
    QPushButton *fChord;
    QSlider *volume;
    QSlider *pitchbend;
    QSpinBox *midichannel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_5;
    QSpinBox *program;
    QLabel *label_6;
    QPushButton *testButton;
    QPushButton *testButton_2;
    QPushButton *gChord;
    QPushButton *aChord;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(407, 347);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        eChord = new QPushButton(centralWidget);
        eChord->setObjectName(QStringLiteral("eChord"));
        eChord->setGeometry(QRect(40, 190, 16, 23));
        eChord->setCheckable(true);
        fChord = new QPushButton(centralWidget);
        fChord->setObjectName(QStringLiteral("fChord"));
        fChord->setGeometry(QRect(60, 190, 16, 23));
        fChord->setCheckable(true);
        volume = new QSlider(centralWidget);
        volume->setObjectName(QStringLiteral("volume"));
        volume->setGeometry(QRect(90, 270, 121, 21));
        volume->setMaximum(127);
        volume->setValue(127);
        volume->setOrientation(Qt::Horizontal);
        pitchbend = new QSlider(centralWidget);
        pitchbend->setObjectName(QStringLiteral("pitchbend"));
        pitchbend->setGeometry(QRect(350, 80, 22, 131));
        pitchbend->setMinimum(-100);
        pitchbend->setMaximum(100);
        pitchbend->setValue(75);
        pitchbend->setOrientation(Qt::Vertical);
        midichannel = new QSpinBox(centralWidget);
        midichannel->setObjectName(QStringLiteral("midichannel"));
        midichannel->setGeometry(QRect(110, 80, 42, 22));
        midichannel->setMaximum(15);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 160, 46, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 80, 46, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 270, 46, 13));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(340, 50, 46, 13));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(150, 20, 181, 22));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 20, 91, 16));
        program = new QSpinBox(centralWidget);
        program->setObjectName(QStringLiteral("program"));
        program->setGeometry(QRect(110, 120, 42, 22));
        program->setMaximum(127);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 120, 46, 13));
        testButton = new QPushButton(centralWidget);
        testButton->setObjectName(QStringLiteral("testButton"));
        testButton->setGeometry(QRect(50, 230, 75, 23));
        testButton_2 = new QPushButton(centralWidget);
        testButton_2->setObjectName(QStringLiteral("testButton_2"));
        testButton_2->setGeometry(QRect(140, 230, 75, 23));
        gChord = new QPushButton(centralWidget);
        gChord->setObjectName(QStringLiteral("gChord"));
        gChord->setGeometry(QRect(80, 190, 16, 23));
        gChord->setCheckable(true);
        aChord = new QPushButton(centralWidget);
        aChord->setObjectName(QStringLiteral("aChord"));
        aChord->setGeometry(QRect(100, 190, 16, 23));
        aChord->setCheckable(true);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(230, 230, 113, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 407, 21));
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
        eChord->setText(QApplication::translate("MainWindow", "E", 0));
        fChord->setText(QApplication::translate("MainWindow", "F", 0));
        label->setText(QApplication::translate("MainWindow", "Notes", 0));
        label_2->setText(QApplication::translate("MainWindow", "Channel:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Volume:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Speed", 0));
        label_5->setText(QApplication::translate("MainWindow", "Midi Output Device:", 0));
        label_6->setText(QApplication::translate("MainWindow", "Program:", 0));
        testButton->setText(QApplication::translate("MainWindow", "TEST!", 0));
        testButton_2->setText(QApplication::translate("MainWindow", "TEST!", 0));
        gChord->setText(QApplication::translate("MainWindow", "G", 0));
        aChord->setText(QApplication::translate("MainWindow", "A", 0));
        lineEdit->setText(QApplication::translate("MainWindow", "E", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
