/********************************************************************************
** Form generated from reading UI file 'generator.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATOR_H
#define UI_GENERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Generator
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_12;
    QTextBrowser *textBrowser_3;
    QTextBrowser *textBrowser_7;
    QTextBrowser *textBrowser_11;
    QTextBrowser *textBrowser_8;
    QTextBrowser *textBrowser_6;
    QTextBrowser *textBrowser_5;
    QTextBrowser *textBrowser_10;
    QTextBrowser *textBrowser_9;
    QTextBrowser *textBrowser_14;
    QTextBrowser *textBrowser_13;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit;
    QTextBrowser *textBrowser_4;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Generator)
    {
        if (Generator->objectName().isEmpty())
            Generator->setObjectName(QStringLiteral("Generator"));
        Generator->resize(513, 270);
        gridLayout = new QGridLayout(Generator);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(Generator);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 970, 392));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textBrowser = new QTextBrowser(scrollAreaWidgetContents);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout_2->addWidget(textBrowser, 2, 0, 1, 1);

        textBrowser_2 = new QTextBrowser(scrollAreaWidgetContents);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));

        gridLayout_2->addWidget(textBrowser_2, 3, 0, 1, 1);

        textBrowser_12 = new QTextBrowser(scrollAreaWidgetContents);
        textBrowser_12->setObjectName(QStringLiteral("textBrowser_12"));

        gridLayout_2->addWidget(textBrowser_12, 0, 9, 1, 1);

        textBrowser_3 = new QTextBrowser(scrollAreaWidgetContents);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));

        gridLayout_2->addWidget(textBrowser_3, 4, 0, 1, 1);

        textBrowser_7 = new QTextBrowser(scrollAreaWidgetContents);
        textBrowser_7->setObjectName(QStringLiteral("textBrowser_7"));

        gridLayout_2->addWidget(textBrowser_7, 0, 11, 1, 1);

        textBrowser_11 = new QTextBrowser(scrollAreaWidgetContents);
        textBrowser_11->setObjectName(QStringLiteral("textBrowser_11"));

        gridLayout_2->addWidget(textBrowser_11, 0, 2, 1, 1);

        textBrowser_8 = new QTextBrowser(scrollAreaWidgetContents);
        textBrowser_8->setObjectName(QStringLiteral("textBrowser_8"));

        gridLayout_2->addWidget(textBrowser_8, 0, 12, 1, 1);

        textBrowser_6 = new QTextBrowser(scrollAreaWidgetContents);
        textBrowser_6->setObjectName(QStringLiteral("textBrowser_6"));

        gridLayout_2->addWidget(textBrowser_6, 0, 6, 1, 1);

        textBrowser_5 = new QTextBrowser(scrollAreaWidgetContents);
        textBrowser_5->setObjectName(QStringLiteral("textBrowser_5"));

        gridLayout_2->addWidget(textBrowser_5, 0, 5, 1, 1);

        textBrowser_10 = new QTextBrowser(scrollAreaWidgetContents);
        textBrowser_10->setObjectName(QStringLiteral("textBrowser_10"));

        gridLayout_2->addWidget(textBrowser_10, 0, 4, 1, 1);

        textBrowser_9 = new QTextBrowser(scrollAreaWidgetContents);
        textBrowser_9->setObjectName(QStringLiteral("textBrowser_9"));

        gridLayout_2->addWidget(textBrowser_9, 0, 10, 1, 1);

        textBrowser_14 = new QTextBrowser(scrollAreaWidgetContents);
        textBrowser_14->setObjectName(QStringLiteral("textBrowser_14"));

        gridLayout_2->addWidget(textBrowser_14, 0, 7, 1, 1);

        textBrowser_13 = new QTextBrowser(scrollAreaWidgetContents);
        textBrowser_13->setObjectName(QStringLiteral("textBrowser_13"));

        gridLayout_2->addWidget(textBrowser_13, 0, 8, 1, 1);

        textEdit_2 = new QTextEdit(scrollAreaWidgetContents);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        gridLayout_2->addWidget(textEdit_2, 1, 0, 1, 1);

        textEdit = new QTextEdit(scrollAreaWidgetContents);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout_2->addWidget(textEdit, 0, 0, 1, 1);

        textBrowser_4 = new QTextBrowser(scrollAreaWidgetContents);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));

        gridLayout_2->addWidget(textBrowser_4, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(Generator);

        QMetaObject::connectSlotsByName(Generator);
    } // setupUi

    void retranslateUi(QWidget *Generator)
    {
        Generator->setWindowTitle(QApplication::translate("Generator", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Generator: public Ui_Generator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATOR_H
