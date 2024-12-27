#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QStringConverter>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QTableWidgetItem>
#include <QClipboard>
#include "burm.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->suggestionsText->verticalHeader()->setVisible(false);
    connect(ui->inputText, &QTextEdit::textChanged, this, &MainWindow::convertText);
    // Connect the table widget's itemClicked signal
    connect(ui->suggestionsText, &QTableWidget::itemClicked, this, &MainWindow::suggestionClicked);
    connect(ui->actionTransliterationGuide, &QAction::triggered, this, &MainWindow::openTransliterationGuide);

    loadCsvData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Store CSV data in a QMap for efficient filtering
QMap<QString, QString> csvData;

void MainWindow::loadCsvData()
{
    QString txtPath = "/home/ankit/Desktop/BurmeseTypingAssist/BurmeseTypingAssist/suggestions.txt";
    QString csvPath = "/home/ankit/Desktop/BurmeseTypingAssist/BurmeseTypingAssist/suggestions.csv";

    QFile csvFile(csvPath);
    if (!csvFile.exists()) {
        createCsvFromTxt(txtPath, csvPath);
    }
    else
    {
        qDebug()<<"csv file already exists";
    }

    if (!csvFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open CSV file:" << csvPath;
        return;
    }

    QTextStream in(&csvFile);
    in.setEncoding(QStringConverter::Utf8);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(',');
        if (parts.size() == 2) {
            QString burmese = parts[0].trimmed();
            QString english = parts[1].trimmed();
            csvData.insert(burmese, english); // Store in the QMap
        }
    }

    csvFile.close();
}

void MainWindow::convertText()
{
    QString input = ui->inputText->toPlainText();
    QString converted = QString::fromStdString(toBurm(input.toStdString()));
    ui->convertedText->setPlainText(converted);
    loadSuggestions(converted);
}

QString MainWindow::transliterate(const QString& text)
{
    QString result = text;
    result.replace(QRegularExpression("a"), "အ");
    result.replace(QRegularExpression("b"), "ဘ");
    result.replace(QRegularExpression("k"), "က");
    return result;
}


QString MainWindow::toEnglish(const QString& text)
{
    QString result = text;
    result.replace(QRegularExpression("အ"), "a");
    result.replace(QRegularExpression("ဘ"), "b");
    result.replace(QRegularExpression("က"), "k");
    return result;
}


void MainWindow::createCsvFromTxt(const QString& txtPath, const QString& csvPath)
{
    QFile txtFile(txtPath);
    if (!txtFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open TXT file:" << txtPath;
        return;
    }

    QFile csvFile(csvPath);
    if (!csvFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Could not create CSV file:" << csvPath;
        txtFile.close(); // Close the txt file in case of error
        return;
    }

    QTextStream in(&txtFile);
    in.setEncoding(QStringConverter::Utf8);
    QTextStream out(&csvFile);
    out.setEncoding(QStringConverter::Utf8);

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (!line.isEmpty()) {
            QString english = QString::fromStdString(toslp1(line.toStdString()));
            out << line << "," << english << "\n";
        }
    }

    txtFile.close();
    csvFile.close();
}


void MainWindow::loadSuggestions(const QString& convertedText)
{
    ui->suggestionsText->clear();
    ui->suggestionsText->setColumnCount(2);
    ui->suggestionsText->setHorizontalHeaderLabels({"Burmese", "English"});
    ui->suggestionsText->setRowCount(0);

    // Efficient filtering using the QMap
    QMapIterator<QString, QString> i(csvData);
    while (i.hasNext()) {
        i.next();
        if (i.key().contains(convertedText) || i.value().contains(convertedText)) {
            int row = ui->suggestionsText->rowCount();
            ui->suggestionsText->insertRow(row);
            QTableWidgetItem *burmeseItem = new QTableWidgetItem(i.key());
            QTableWidgetItem *englishItem = new QTableWidgetItem(i.value());
            ui->suggestionsText->setItem(row, 0, burmeseItem);
            ui->suggestionsText->setItem(row, 1, englishItem);
        }
    }
    ui->suggestionsText->resizeColumnsToContents();
}



void MainWindow::suggestionClicked(QTableWidgetItem *item)
{
    if (item) { // Check if a valid item was clicked
        int row = item->row();
        QTableWidgetItem *burmeseItem = ui->suggestionsText->item(row, 0); // Get Burmese item

        if (burmeseItem) {
            QString burmeseText = burmeseItem->text();

            ui->convertedText->setPlainText(burmeseText);
        }
    }
}


void MainWindow::on_copyButton_clicked()
{
    QString textToCopy = ui->convertedText->toPlainText();
    QApplication::clipboard()->setText(textToCopy);
}

TransliterationGuide *transliterationGuideWindow = nullptr; // Declare a pointer
void MainWindow::openTransliterationGuide()
{
    if (!transliterationGuideWindow) {
        transliterationGuideWindow = new TransliterationGuide(this);
        connect(transliterationGuideWindow, &QDialog::finished, [this](){
            delete transliterationGuideWindow;
            transliterationGuideWindow = nullptr;
        });
    }
    transliterationGuideWindow->show();
    transliterationGuideWindow->raise(); // Bring to front
    transliterationGuideWindow->activateWindow();//give focus
}
