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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Generator
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Generator)
    {
        if (Generator->objectName().isEmpty())
            Generator->setObjectName(QStringLiteral("Generator"));
        Generator->resize(400, 300);
        verticalLayout = new QVBoxLayout(Generator);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(6);
        pushButton = new QPushButton(Generator);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(Generator);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(Generator);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 0, 2, 1, 1);

        pushButton_3 = new QPushButton(Generator);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 0, 1, 3);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(Generator);

        QMetaObject::connectSlotsByName(Generator);
    } // setupUi

    void retranslateUi(QWidget *Generator)
    {
        Generator->setWindowTitle(QApplication::translate("Generator", "Form", nullptr));
        pushButton->setText(QApplication::translate("Generator", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("Generator", "PushButton", nullptr));
        pushButton_4->setText(QApplication::translate("Generator", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("Generator", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Generator: public Ui_Generator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATOR_H
