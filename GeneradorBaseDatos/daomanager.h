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

private slots:
    void on_classnameline_textEdited(const QString &arg1);

    void on_addFieldButton_clicked();

private:
    Ui::Daomanager *ui;
    Generarclassdao classdaomanager;
    QString className;
    std::deque<QString> nombres;
    std::deque<QString> tipos;
};

#endif // DAOMANAGER_H
