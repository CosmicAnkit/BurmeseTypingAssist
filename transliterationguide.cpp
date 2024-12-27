#include "transliterationguide.h"
#include "ui_transliterationguide.h"
#include <QDebug>

TransliterationGuide::TransliterationGuide(QWidget *parent) :
    QDialog(parent), // Call QDialog constructor
    ui(new Ui::TransliterationGuide)
{
    ui->setupUi(this);
    // loadGuideFromJson("/home/ankit/Desktop/BurmeseTypingAssist/BurmeseTypingAssist/transliteration_guide.json");
    loadGuideFromJson("../../transliteration_guide.json");

    ui->guideTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->guideTable->verticalHeader()->setVisible(false);
    ui->guideTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

TransliterationGuide::~TransliterationGuide()
{
    delete ui;
}

void TransliterationGuide::loadGuideFromJson(const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open JSON file: " << filePath;
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    if (doc.isNull()) {
        qDebug() << "Invalid JSON format.";
        return;
    }

    QJsonArray array = doc.array();
    ui->guideTable->setRowCount(array.size());

    for (int i = 0; i < array.size(); ++i) {
        QJsonObject obj = array[i].toObject();
        QString burmese = obj["burmese"].toString();
        QString english = obj["english"].toString();

        QTableWidgetItem *burmeseItem = new QTableWidgetItem(burmese);
        QTableWidgetItem *englishItem = new QTableWidgetItem(english);

        ui->guideTable->setItem(i, 0, burmeseItem);
        ui->guideTable->setItem(i, 1, englishItem);
    }
}
