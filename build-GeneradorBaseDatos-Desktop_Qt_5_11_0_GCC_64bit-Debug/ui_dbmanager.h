/********************************************************************************
** Form generated from reading UI file 'dbmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBMANAGER_H
#define UI_DBMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DbManager
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *dblabel;
    QLineEdit *dbnamelineEdit;
    QTextBrowser *headerBrowser;
    QTextBrowser *cppBrowser;

    void setupUi(QWidget *DbManager)
    {
        if (DbManager->objectName().isEmpty())
            DbManager->setObjectName(QStringLiteral("DbManager"));
        DbManager->resize(662, 391);
        verticalLayout = new QVBoxLayout(DbManager);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(14);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        dblabel = new QLabel(DbManager);
        dblabel->setObjectName(QStringLiteral("dblabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dblabel->sizePolicy().hasHeightForWidth());
        dblabel->setSizePolicy(sizePolicy);
        dblabel->setMinimumSize(QSize(0, 0));
        dblabel->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(dblabel);

        dbnamelineEdit = new QLineEdit(DbManager);
        dbnamelineEdit->setObjectName(QStringLiteral("dbnamelineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dbnamelineEdit->sizePolicy().hasHeightForWidth());
        dbnamelineEdit->setSizePolicy(sizePolicy1);
        dbnamelineEdit->setMinimumSize(QSize(0, 0));
        dbnamelineEdit->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(dbnamelineEdit);


        verticalLayout->addLayout(horizontalLayout);

        headerBrowser = new QTextBrowser(DbManager);
        headerBrowser->setObjectName(QStringLiteral("headerBrowser"));
        headerBrowser->setEnabled(true);

        verticalLayout->addWidget(headerBrowser);

        cppBrowser = new QTextBrowser(DbManager);
        cppBrowser->setObjectName(QStringLiteral("cppBrowser"));

        verticalLayout->addWidget(cppBrowser);


        retranslateUi(DbManager);

        QMetaObject::connectSlotsByName(DbManager);
    } // setupUi

    void retranslateUi(QWidget *DbManager)
    {
        DbManager->setWindowTitle(QApplication::translate("DbManager", "Form", nullptr));
        dblabel->setText(QApplication::translate("DbManager", "Database Name:", nullptr));
        dbnamelineEdit->setText(QApplication::translate("DbManager", "Enter your text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DbManager: public Ui_DbManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBMANAGER_H
