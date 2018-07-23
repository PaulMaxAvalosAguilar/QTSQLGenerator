#include "daomanager.h"
#include "ui_daomanager.h"
#include <QDebug>
#include <QScrollBar>
#include <deque>

Daomanager::Daomanager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Daomanager),
    classdaomanager(),
    className(),
    position()
{
    ui->setupUi(this);

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

    int lastElementposition = nombres.size()-1;

    if(i == 1){
        position = lastElementposition;//Go to last element

        updateLCDandTBrowser(position, position+1);

    }else if(i == 2){

        if(position >0){
            position = position -1; //Go upwards

            updateLCDandTBrowser(position, position+1);
        }

    }else if(i == 3){

        if(position <lastElementposition){
            position = position + 1; //Go downwards

            updateLCDandTBrowser(position, position +1 );
        }
    }

    updateSizeLCD();
}

void Daomanager::updateLCDandTBrowser(int positionText, int numberToDisplayLCD)
{

        ui->currentfieldTB->setText(nombres.at(positionText)
                                    + " " +
                                    tipos.at(positionText));
        ui->lcdNumber->display(numberToDisplayLCD);
}

void Daomanager::cleanLCDandTBrowser()
{
    ui->currentfieldTB->setText("");
    ui->lcdNumber->display(0);
}

void Daomanager::updateSizeLCD()
{
    int i = nombres.size();

    ui->elementslcd->display(i);
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
    editCurFieldTBrowser(3);
}

void Daomanager::on_removeButton_clicked()
{
    if(nombres.size() != 0){

        std::deque<QString>::iterator a = nombres.begin();
        auto posicionDeseadaA = a + position;

        std::deque<QString>::iterator b = tipos.begin();
        auto posicionDeseadaB = b + position;

        nombres.erase(posicionDeseadaA);
        tipos.erase(posicionDeseadaB);

        //RECALCULATE TEXT
        //GET CURRENT SCROLLBAR POSITIONS
        QScrollBar *cppscroll = ui->cppBrowser->verticalScrollBar();
        int lastSscrollposition = cppscroll->value();
        //GET CURRENT SCROLLBAR POSITIONS

        ui->cppBrowser->setText(classdaomanager.generarTextoSrc(className,nombres,tipos));

        //RESET SCROLLBAR POSITIONS
        cppscroll->setValue(lastSscrollposition);
        //RESET SCROLLBAR POSITIONS


        //UPDATE LCD SCREEN
        if(nombres.size() != 0){
            position = position-1;//move upwards
            if(position  <0){
                position = 0;
            }

            updateLCDandTBrowser(position, position + 1);

        }else if( nombres.size() == 0){

            cleanLCDandTBrowser();

        }
        updateSizeLCD();
    }
}
