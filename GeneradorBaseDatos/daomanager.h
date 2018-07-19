#ifndef DAOMANAGER_H
#define DAOMANAGER_H

#include <QWidget>
#include <generarclassdao.h>

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

private:
    Ui::Daomanager *ui;
    Generarclassdao classdaomanager;
};

#endif // DAOMANAGER_H
