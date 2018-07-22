#include "daomanager.h"
#include "ui_daomanager.h"
#include <QDebug>
#include <QScrollBar>

Daomanager::Daomanager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Daomanager),
    classdaomanager(),
    className()
{
    ui->setupUi(this);


/*
    nombres.push_back("nombre");
    tipos.push_back("text");
    nombres.push_back("edad");
    tipos.push_back("integer");
    nombres.push_back("experiencia");
    tipos.push_back("integer");
*/

    ui->comboBox->addItem("TEXT");
    ui->comboBox->addItem("NUMERIC");
    ui->comboBox->addItem("INTEGER");
    ui->comboBox->addItem("REAL");
    ui->comboBox->addItem("BLOB");

    ui->headerBrowser->setText(classdaomanager.generarTextoHeader(""));
    ui->cppBrowser->setText(classdaomanager.generarTextoSrc("",nombres,tipos));

}

Daomanager::~Daomanager()
{
    delete ui;
}

void Daomanager::editCurFieldTBrowser(int i)
{
    int lastposition = nombres.size()-1;
    static int vecesOprimidasbA;
    int position;

    if(i == 1){
        position = lastposition;
        ui->currentfieldTB->setText(nombres.at(position)
                                    + " " +
                                    tipos.at(position));
        vecesOprimidasbA = 1;
    }else if(i == 2){

        position = lastposition -vecesOprimidasbA;
        if(position >=0){
            ui->currentfieldTB->setText(nombres.at(position)
                                        + " " +
                                        tipos.at(position));
            vecesOprimidasbA++;
        }
    }else if(i == 3){

    }
}



void Daomanager::on_classnameline_textEdited(const QString &arg1)
{

    //GET CURRENT SCROLLBAR POSITIONS
    QScrollBar *headerscroll = ui->headerBrowser->verticalScrollBar();
    int lastHscrollposition = headerscroll->value();

    QScrollBar *cppscroll = ui->cppBrowser->verticalScrollBar();
    int lastSscrollposition = cppscroll->value();
    //GET CURRENT SCROLLBAR POSITIONS

    ui->headerBrowser->setText(classdaomanager.generarTextoHeader(arg1));
    ui->cppBrowser->setText(classdaomanager.generarTextoSrc(arg1,nombres,tipos));

    //RESET SCROLLBAR POSITIONS
    headerscroll->setValue(lastHscrollposition);
    cppscroll->setValue(lastSscrollposition);
    //RESET SCROLLBAR POSITIONS

    className = arg1;
}

void Daomanager::on_addFieldButton_clicked()
{
    //GET CURRENT SCROLLBAR POSITIONS
    QScrollBar *cppscroll = ui->cppBrowser->verticalScrollBar();
    int lastSscrollposition = cppscroll->value();
    //GET CURRENT SCROLLBAR POSITIONS

    QString text = std::move(ui->fieldlineEdit->text());
    QString typetext = std::move(
                ui->comboBox->itemText(ui->comboBox->currentIndex()));

    nombres.push_back(text);
    tipos.push_back(typetext);


    ui->headerBrowser->setText(classdaomanager.generarTextoHeader(className));
    ui->cppBrowser->setText(classdaomanager.generarTextoSrc(className,nombres,tipos));

    //RESET SCROLLBAR POSITIONS
    cppscroll->setValue(lastSscrollposition);
    //RESET SCROLLBAR POSITIONS


    editCurFieldTBrowser(1);

}


void Daomanager::on_upButton_clicked()
{
    editCurFieldTBrowser(2);
}

void Daomanager::on_downButton_clicked()
{

}
