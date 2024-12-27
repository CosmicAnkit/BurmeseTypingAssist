#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QStringConverter>
#include <QRegularExpression>
#include "transliterationguide.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void convertText();
    void on_copyButton_clicked();
    void openTransliterationGuide();

private:
    Ui::MainWindow *ui;
    QString transliterate(const QString& text);
    QString transliterateReverse(const QString& burmese); // Declare reverse transliteration
    void loadSuggestions(const QString& convertedText);
    void createCsvFromTxt(const QString& txtPath, const QString& csvPath);
    QString toEnglish(const QString& text);
    void loadCsvData();
    void suggestionClicked(QTableWidgetItem *item);
    TransliterationGuide *transliterationGuideWindow = nullptr; // Declaration of the pointer
    QMap<QString, QString> csvData;



    // bool createCsvFromTxt(const QString& txtFilePath, const QString& csvFilePath); // Declare CSV creation function
};
#endif // MAINWINDOW_H
