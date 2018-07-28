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
    position(0),
    lcdNumber(0)
{
    ui->setupUi(this);

    setWidgetColour();

    ui->comboBox->addItem("TEXT");
    ui->comboBox->addItem("NUMERIC");
    ui->comboBox->addItem("INTEGER");
    ui->comboBox->addItem("REAL");
    ui->comboBox->addItem("BLOB");

    ui->headerBrowser->setText(classdaomanager.generarTextoHeader("",nombres));
    ui->cppBrowser->setText(classdaomanager.generarTextoSrc("",nombres,tipos));

}

Daomanager::~Daomanager()
{
    delete ui;
}

void Daomanager::editCurFieldTBrowser(double i)
{

    int lastElementposition = nombres.size()-1;

    if(i == 1){
        position = lastElementposition;//Go to last element
        lcdNumber = position + 1;

        updateLCDandTBrowser();

    }else if(i == 1.5){
        //stay in the same place
        updateLCDandTBrowser();

    }else if(i == 2){
        if(position >0){
            position = position -1; //Go upwards
            lcdNumber = position +1;

            updateLCDandTBrowser();
        }

    }else if(i == 3){

        if(position <lastElementposition){
            position = position + 1; //Go downwards
            lcdNumber = position +1;

            updateLCDandTBrowser();
        }
    }

    updateSizeLCD();
}

void Daomanager::updateLCDandTBrowser()
{

        ui->currentfieldTB->setText(nombres.at(position)
                                    + " " +
                                    tipos.at(position));
        ui->lcdNumber->display(lcdNumber);
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

void Daomanager::setWidgetColour()
{

    QPalette pal = palette();
    pal.setColor(QPalette::Background, qRgb(210,216,38));
    setAutoFillBackground(true);
    setPalette(pal);
}



void Daomanager::on_classnameline_textEdited(const QString &arg1)
{

    //GET CURRENT SCROLLBAR POSITIONS
    QScrollBar *headerscroll = ui->headerBrowser->verticalScrollBar();
    int lastHscrollposition = headerscroll->value();

    QScrollBar *cppscroll = ui->cppBrowser->verticalScrollBar();
    int lastSscrollposition = cppscroll->value();
    //GET CURRENT SCROLLBAR POSITIONS


    //CALCULATE TEXT
    ui->headerBrowser->setText(classdaomanager.generarTextoHeader(arg1, nombres));
    ui->cppBrowser->setText(classdaomanager.generarTextoSrc(arg1,nombres,tipos));

    //RESET SCROLLBAR POSITIONS
    headerscroll->setValue(lastHscrollposition);
    cppscroll->setValue(lastSscrollposition);
    //RESET SCROLLBAR POSITIONS

    className = arg1;
}

void Daomanager::on_addFieldButton_clicked()
{
    //Read text and combo box
    QString text = std::move(ui->fieldlineEdit->text());
    QString typetext = std::move(
                ui->comboBox->itemText(ui->comboBox->currentIndex()));


    //GET CURRENT SCROLLBAR POSITIONS
    QScrollBar *headerscroll = ui->headerBrowser->verticalScrollBar();
    int lastHscrollposition = headerscroll->value();

    QScrollBar *cppscroll = ui->cppBrowser->verticalScrollBar();
    int lastSscrollposition = cppscroll->value();
    //GET CURRENT SCROLLBAR POSITIONS

    //Insertion logic
    if(nombres.size() == 0 || position == static_cast<int>(nombres.size()-1)){
        nombres.push_back(text);
        tipos.push_back(typetext);
        editCurFieldTBrowser(1);
    }else{
        std::deque<QString>::iterator iteradorA = nombres.begin();
        auto iteradorEnposicionA = iteradorA +position;

        std::deque<QString>::iterator iteradorB = tipos.begin();
        auto iteradorEnposicionB = iteradorB +position;

        nombres.insert(iteradorEnposicionA, text);
        tipos.insert(iteradorEnposicionB, typetext);

        editCurFieldTBrowser(1.5);

    }


    //CACLULATE TEXT
    ui->headerBrowser->setText(classdaomanager.generarTextoHeader(className, nombres));
    ui->cppBrowser->setText(classdaomanager.generarTextoSrc(className,nombres,tipos));

    //RESET SCROLLBAR POSITIONS
    cppscroll->setValue(lastSscrollposition);
    headerscroll->setValue(lastHscrollposition);
    //RESET SCROLLBAR POSITIONS

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

        //GET CURRENT SCROLLBAR POSITIONS
        QScrollBar *headerscroll = ui->headerBrowser->verticalScrollBar();
        int lastHscrollposition = headerscroll->value();

        QScrollBar *cppscroll = ui->cppBrowser->verticalScrollBar();
        int lastSscrollposition = cppscroll->value();
        //GET CURRENT SCROLLBAR POSITIONS


        //Removal logic
        nombres.erase(posicionDeseadaA);
        tipos.erase(posicionDeseadaB);



        //CALCULATE TEXT
        ui->headerBrowser->setText(classdaomanager.generarTextoHeader(className,nombres));
        ui->cppBrowser->setText(classdaomanager.generarTextoSrc(className,nombres,tipos));

        //RESET SCROLLBAR POSITIONS
        headerscroll->setValue(lastHscrollposition);
        cppscroll->setValue(lastSscrollposition);
        //RESET SCROLLBAR POSITIONS


        //UPDATE LCD SCREENS
        if(nombres.size() != 0){
            position = position-1;//move upwards
            if(position  <0){
                position = 0;
            }

            lcdNumber = position +1;

            updateLCDandTBrowser();

        }else if( nombres.size() == 0){

            cleanLCDandTBrowser();

        }
        updateSizeLCD();
    }
}

void Daomanager::on_removeAllButton_clicked()
{
    nombres.clear();
    tipos.clear();

    position = 0;

    cleanLCDandTBrowser();
    updateSizeLCD();
}
