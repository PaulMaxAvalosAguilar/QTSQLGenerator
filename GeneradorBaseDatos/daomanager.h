#ifndef DAOMANAGER_H
#define DAOMANAGER_H

#include <QWidget>
#include <generarclassdao.h>
#include <deque>

namespace Ui {
class Daomanager;
}

class Daomanager : public QWidget
{
    Q_OBJECT

public:
    explicit Daomanager(QWidget *parent = 0);
    ~Daomanager();

private:
    void editCurFieldTBrowser(double i);
    void updateLCDandTBrowser();
    void cleanLCDandTBrowser();
    void updateSizeLCD();
    void setWidgetColour();


private slots:
    void on_classnameline_textEdited(const QString &arg1);
    void on_addFieldButton_clicked();

    void on_downButton_clicked();

    void on_upButton_clicked();
    void on_removeButton_clicked();


    void on_removeAllButton_clicked();

private:
    Ui::Daomanager *ui;
    Generarclassdao classdaomanager;
    QString className;
    std::deque<QString> nombres;
    std::deque<QString> tipos;
    int position;
    int lcdNumber;
};

#endif // DAOMANAGER_H
