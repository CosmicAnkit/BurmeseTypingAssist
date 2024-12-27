/********************************************************************************
** Form generated from reading UI file 'transliterationguide.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSLITERATIONGUIDE_H
#define UI_TRANSLITERATIONGUIDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_TransliterationGuide
{
public:
    QTableWidget *guideTable;

    void setupUi(QDialog *TransliterationGuide)
    {
        if (TransliterationGuide->objectName().isEmpty())
            TransliterationGuide->setObjectName("TransliterationGuide");
        TransliterationGuide->resize(500, 400);
        guideTable = new QTableWidget(TransliterationGuide);
        if (guideTable->columnCount() < 2)
            guideTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        guideTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        guideTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        guideTable->setObjectName("guideTable");
        guideTable->setGeometry(QRect(20, 20, 450, 350));
        guideTable->setGridStyle(Qt::PenStyle::SolidLine);
        guideTable->setColumnCount(2);
        guideTable->horizontalHeader()->setCascadingSectionResizes(false);

        retranslateUi(TransliterationGuide);

        QMetaObject::connectSlotsByName(TransliterationGuide);
    } // setupUi

    void retranslateUi(QDialog *TransliterationGuide)
    {
        TransliterationGuide->setWindowTitle(QCoreApplication::translate("TransliterationGuide", "Transliteration Guide", nullptr));
        QTableWidgetItem *___qtablewidgetitem = guideTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TransliterationGuide", "Burmese", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = guideTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TransliterationGuide", "SLP1(English)", nullptr));
        guideTable->setStyleSheet(QCoreApplication::translate("TransliterationGuide", "\n"
"     QTableWidget {\n"
"         border: 1px solid #bbb;\n"
"         border-radius: 8px;\n"
"         font-size: 14px;\n"
"         font-family: \"Arial\";\n"
"         background-color: #f9f9f9;\n"
"         color: #333;\n"
"     }\n"
"     QHeaderView::section {\n"
"         background-color: #5CB85C;\n"
"         color: white;\n"
"         font-size: 14px;\n"
"         font-weight: bold;\n"
"         border: 1px solid #ddd;\n"
"     }\n"
"    ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransliterationGuide: public Ui_TransliterationGuide {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSLITERATIONGUIDE_H
