#include "dbmanager.h"
#include "ui_dbmanager.h"
#include <QScrollBar>

DbManager::DbManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DbManager),
    dbtextManager()
{
    ui->setupUi(this);



    ui->headerBrowser->setText(dbtextManager.generarTextoHeader(""));
    ui->cppBrowser->setText(dbtextManager.generarTextoSrc());
}

DbManager::~DbManager()
{
    delete ui;
}

void DbManager::setWidgetColour()
{
    QPalette pal = palette();
    pal.setColor(QPalette::Background, qRgb(210,216,38));
    setAutoFillBackground(true);
    setPalette(pal);
}

void DbManager::on_dbnamelineEdit_textEdited(const QString &arg1)
{
    QScrollBar *headerscroll = ui->headerBrowser->verticalScrollBar();
    int lastHscrollposition = headerscroll->value();

    ui->headerBrowser->setText(dbtextManager.generarTextoHeader(arg1));

    headerscroll->setValue(lastHscrollposition);
}
