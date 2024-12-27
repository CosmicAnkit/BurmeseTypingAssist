#ifndef TRANSLITERATIONGUIDE_H
#define TRANSLITERATIONGUIDE_H

#include <QWidget>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QTableWidgetItem>
#include <qdialog.h>

QT_BEGIN_NAMESPACE
namespace Ui { class TransliterationGuide; }
QT_END_NAMESPACE

class TransliterationGuide : public QDialog
{
    Q_OBJECT

public:
    TransliterationGuide(QWidget *parent = nullptr);
    ~TransliterationGuide();

private:
    Ui::TransliterationGuide *ui;
    void loadGuideFromJson(const QString& filePath);
};
#endif // TRANSLITERATIONGUIDE_H
