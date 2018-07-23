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

    void editCurFieldTBrowser(int i);

private slots:
    void on_classnameline_textEdited(const QString &arg1);
    void on_addFieldButton_clicked();

    void on_downButton_clicked();

    void on_upButton_clicked();
    void on_removeButton_clicked();


private:
    Ui::Daomanager *ui;
    Generarclassdao classdaomanager;
    QString className;
    std::deque<QString> nombres;
    std::deque<QString> tipos;
    int position;
};

#endif // DAOMANAGER_H
