#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "generardatabasemanager.h"
#include "generator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_lineEdit_textEdited(const QString &arg1);


private:
    Ui::MainWindow *ui;
    GenerarDatabaseManager data;
    Generator generatorUi;
};

#endif // MAINWINDOW_H
