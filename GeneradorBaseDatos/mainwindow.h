#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbmanager.h"
#include "daomanager.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setTabsColours();

private slots:

private:
    Ui::MainWindow *ui;
    DbManager *dbmanagerui;
    Daomanager *classdaomanager;
};

#endif // MAINWINDOW_H
