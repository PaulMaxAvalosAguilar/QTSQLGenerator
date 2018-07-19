#include "daomanager.h"
#include "ui_daomanager.h"
#include <QDebug>

Daomanager::Daomanager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Daomanager),
    classdaomanager()
{
    ui->setupUi(this);
    ui->headerBrowser->setText(classdaomanager.generarTextoHeader(""));

}

Daomanager::~Daomanager()
{
    delete ui;
}



void Daomanager::on_classnameline_textEdited(const QString &arg1)
{
    ui->headerBrowser->setText(classdaomanager.generarTextoHeader(arg1));
}
