#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "generardatabasemanager.h"
#include <QDebug>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->textBrowser->setText(data.generarTextoHeader(""));
    ui->textBrowser_2->setText(data.generarTextoSrc());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    ui->textBrowser->setText(data.generarTextoHeader(arg1));


}
