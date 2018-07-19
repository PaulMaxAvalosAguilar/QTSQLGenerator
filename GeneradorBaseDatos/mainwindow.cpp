#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "generardatabasemanager.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->textBrowser->setText(data.generarTextoHeader(""));
    ui->textBrowser_2->setText(data.generarTextoSrc());

    /*
    ui->textBrowser->setParent(0);
    ui->textBrowser_2->setParent(0);
    ui->label->setParent(0);
    ui->lineEdit->setParent(0);

    ui->centralWidget->layout()->addWidget(&generatorUi);
    */

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    ui->textBrowser->setText(data.generarTextoHeader(arg1));

    QTextCursor cursor = ui->textBrowser->textCursor();
    cursor.setPosition(12);
    ui->textBrowser->setTextCursor(cursor);
}
