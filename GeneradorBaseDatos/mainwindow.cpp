#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "generardatabasemanager.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dbmanagerui(new DbManager)
{
    ui->setupUi(this);
    ui->dbManagertab->layout()->addWidget(dbmanagerui);
}

MainWindow::~MainWindow()
{
    delete ui;
}




