#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QWidget>
#include <generardatabasemanager.h>

namespace Ui {
class DbManager;
}

class DbManager : public QWidget
{
    Q_OBJECT

public:
    explicit DbManager(QWidget *parent = 0);
    ~DbManager();

private:
    void setWidgetColour();

private slots:
    void on_dbnamelineEdit_textEdited(const QString &arg1);

private:
    Ui::DbManager *ui;
    GenerarDatabaseManager dbtextManager;
};

#endif // DBMANAGER_H
