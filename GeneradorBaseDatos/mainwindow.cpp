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
}

MainWindow::~MainWindow()
{
    delete ui;
}




