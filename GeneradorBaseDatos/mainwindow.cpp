#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "generardatabasemanager.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dbmanagerui(new DbManager),
    classdaomanager(new Daomanager)
{
    ui->setupUi(this);
    ui->dbManagertab->layout()->addWidget(dbmanagerui);
    ui->classdaotab->layout()->addWidget(classdaomanager);

    setTabsColours();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTabsColours()
{
    QPalette paltb1 = ui->dbManagertab->palette();

    paltb1.setColor(QPalette::Background, qRgb(210,216,38));
    ui->dbManagertab->setAutoFillBackground(true);
    ui->dbManagertab->setPalette(paltb1);


    QPalette paltb2 = ui->classdaotab->palette();
    paltb2.setColor(QPalette::Background, qRgb(210,216,38));
    ui->classdaotab->setAutoFillBackground(true);
    ui->classdaotab->setPalette(paltb2);
    ui->classdaotab->show();

}




