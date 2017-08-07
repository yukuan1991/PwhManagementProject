/********************************************************************************
** Form generated from reading UI file 'pwhmanagementmain.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PWHMANAGEMENTMAIN_H
#define UI_PWHMANAGEMENTMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "interface_control/PwhManagementRibbon.h"

QT_BEGIN_NAMESPACE

class Ui_PwhManagementMain
{
public:
    QVBoxLayout *verticalLayout;
    PwhManagementRibbon *rib;
    QMdiArea *mdi;

    void setupUi(QWidget *PwhManagementMain)
    {
        if (PwhManagementMain->objectName().isEmpty())
            PwhManagementMain->setObjectName(QStringLiteral("PwhManagementMain"));
        PwhManagementMain->resize(400, 300);
        verticalLayout = new QVBoxLayout(PwhManagementMain);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        rib = new PwhManagementRibbon(PwhManagementMain);
        rib->setObjectName(QStringLiteral("rib"));

        verticalLayout->addWidget(rib);

        mdi = new QMdiArea(PwhManagementMain);
        mdi->setObjectName(QStringLiteral("mdi"));

        verticalLayout->addWidget(mdi);


        retranslateUi(PwhManagementMain);

        QMetaObject::connectSlotsByName(PwhManagementMain);
    } // setupUi

    void retranslateUi(QWidget *PwhManagementMain)
    {
        PwhManagementMain->setWindowTitle(QApplication::translate("PwhManagementMain", "PwhManagementMain", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PwhManagementMain: public Ui_PwhManagementMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PWHMANAGEMENTMAIN_H
