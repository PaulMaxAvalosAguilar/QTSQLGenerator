#include "dbmanager.h"
#include "ui_dbmanager.h"

DbManager::DbManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DbManager)
{
    ui->setupUi(this);
    ui->headerBrowser->setText(dbtextManager.generarTextoHeader(""));
    ui->cppBrowser->setText(dbtextManager.generarTextoSrc());
}

DbManager::~DbManager()
{
    delete ui;
}

void DbManager::on_dbnamelineEdit_textEdited(const QString &arg1)
{
    ui->headerBrowser->setText(dbtextManager.generarTextoHeader(arg1));


}
