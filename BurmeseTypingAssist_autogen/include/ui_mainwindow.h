/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTransliterationGuide;
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QLabel *label_3;
    QTextEdit *inputText;
    QLabel *label_2;
    QPushButton *copyButton;
    QTextEdit *convertedText;
    QLabel *label;
    QTableWidget *suggestionsText;
    QMenuBar *menubar;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionTransliterationGuide = new QAction(MainWindow);
        actionTransliterationGuide->setObjectName("actionTransliterationGuide");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setSpacing(15);
        mainLayout->setContentsMargins(20, 20, 20, 20);
        mainLayout->setObjectName("mainLayout");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignCenter);

        mainLayout->addWidget(label_3);

        inputText = new QTextEdit(centralwidget);
        inputText->setObjectName("inputText");

        mainLayout->addWidget(inputText);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignCenter);

        mainLayout->addWidget(label_2);

        copyButton = new QPushButton(centralwidget);
        copyButton->setObjectName("copyButton");

        mainLayout->addWidget(copyButton);

        convertedText = new QTextEdit(centralwidget);
        convertedText->setObjectName("convertedText");

        mainLayout->addWidget(convertedText);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        mainLayout->addWidget(label);

        suggestionsText = new QTableWidget(centralwidget);
        if (suggestionsText->columnCount() < 2)
            suggestionsText->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        suggestionsText->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        suggestionsText->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        suggestionsText->setObjectName("suggestionsText");
        suggestionsText->setColumnCount(2);
        suggestionsText->setRowCount(5);

        mainLayout->addWidget(suggestionsText);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionTransliterationGuide);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Burmese Typing Assist", nullptr));
        actionTransliterationGuide->setText(QCoreApplication::translate("MainWindow", "SLP Guide", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "English SLP1", nullptr));
        label_3->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 16px; font-weight: bold; color: #222; font-family: \"Arial\";", nullptr));
        inputText->setStyleSheet(QCoreApplication::translate("MainWindow", "border: 1px solid #bbb; border-radius: 8px; padding: 10px; font-size: 16px; font-family: \"Arial\"; background-color: #ffffff; color: #000000;", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Burmese", nullptr));
        label_2->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 16px; font-weight: bold; color: #222; font-family: \"Arial\";", nullptr));
        copyButton->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        copyButton->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #5CB85C; color: white; border: none; border-radius: 8px; padding: 10px; font-size: 16px; font-family: \"Arial\"; cursor: pointer;", nullptr));
        convertedText->setStyleSheet(QCoreApplication::translate("MainWindow", "border: 1px solid #bbb; border-radius: 8px; padding: 10px; font-size: 16px; font-family: \"Arial\"; background-color: #ffffff; color: #000000;", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Suggestions", nullptr));
        label->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 16px; font-weight: bold; color: #222; font-family: \"Arial\";", nullptr));
        QTableWidgetItem *___qtablewidgetitem = suggestionsText->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Suggestion", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = suggestionsText->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Details", nullptr));
        suggestionsText->setStyleSheet(QCoreApplication::translate("MainWindow", "border: 1px solid #bbb; border-radius: 8px; font-size: 16px; font-family: \"Arial\"; background-color: #ffffff; color: #000000; text-align: left;", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
