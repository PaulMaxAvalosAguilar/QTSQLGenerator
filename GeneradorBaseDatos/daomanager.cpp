#include "daomanager.h"
#include "ui_daomanager.h"
#include <QDebug>
#include <QScrollBar>

Daomanager::Daomanager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Daomanager),
    classdaomanager()
{
    ui->setupUi(this);

    ui->headerBrowser->setText(classdaomanager.generarTextoHeader(""));
    ui->cppBrowser->setText(classdaomanager.generarTextoSrc(""));
}

Daomanager::~Daomanager()
{
    delete ui;
}



void Daomanager::on_classnameline_textEdited(const QString &arg1)
{
    QScrollBar *headerscroll = ui->headerBrowser->verticalScrollBar();
    int lastHscrollposition = headerscroll->value();

    QScrollBar *cppscroll = ui->cppBrowser->verticalScrollBar();
    int lastSscrollposition = cppscroll->value();

    ui->headerBrowser->setText(classdaomanager.generarTextoHeader(arg1));
    ui->cppBrowser->setText(classdaomanager.generarTextoSrc(arg1));

    headerscroll->setValue(lastHscrollposition);
    cppscroll->setValue(lastSscrollposition);
}
