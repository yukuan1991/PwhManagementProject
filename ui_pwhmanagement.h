/********************************************************************************
** Form generated from reading UI file 'pwhmanagement.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PWHMANAGEMENT_H
#define UI_PWHMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "interface_control/JsonTree.h"
#include "interface_control/global_widget.h"
#include "interface_control/widget.h"
#include "video/video_widget.h"

QT_BEGIN_NAMESPACE

class Ui_PwhManagement
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTreeView *tree_product;
    QFrame *line;
    JsonTree *treeWidget;
    video_widget *widget_video_player;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_product;
    QLabel *label_9;
    QLabel *label_date;
    QLabel *label_3;
    QLabel *label_capp;
    QLabel *label_8;
    QLabel *label_measure;
    QLabel *label_4;
    QLabel *label_station;
    QLabel *label_7;
    QLabel *label_measurement;
    QLabel *label_5;
    QLabel *label_operator;
    QLabel *label_6;
    QLabel *label_unit;
    QSpacerItem *horizontalSpacer_2;
    global_widget *widget_global;
    Widget *widget;

    void setupUi(QWidget *PwhManagement)
    {
        if (PwhManagement->objectName().isEmpty())
            PwhManagement->setObjectName(QStringLiteral("PwhManagement"));
        PwhManagement->resize(1032, 615);
        horizontalLayout = new QHBoxLayout(PwhManagement);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(PwhManagement);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        tree_product = new QTreeView(PwhManagement);
        tree_product->setObjectName(QStringLiteral("tree_product"));

        verticalLayout_2->addWidget(tree_product);

        line = new QFrame(PwhManagement);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        treeWidget = new JsonTree(PwhManagement);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout_2->addWidget(treeWidget);


        horizontalLayout->addLayout(verticalLayout_2);

        widget_video_player = new video_widget(PwhManagement);
        widget_video_player->setObjectName(QStringLiteral("widget_video_player"));

        horizontalLayout->addWidget(widget_video_player);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(PwhManagement);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_product = new QLabel(PwhManagement);
        label_product->setObjectName(QStringLiteral("label_product"));
        label_product->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(label_product, 0, 1, 1, 1);

        label_9 = new QLabel(PwhManagement);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 0, 2, 1, 1);

        label_date = new QLabel(PwhManagement);
        label_date->setObjectName(QStringLiteral("label_date"));
        label_date->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(label_date, 0, 3, 1, 1);

        label_3 = new QLabel(PwhManagement);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_capp = new QLabel(PwhManagement);
        label_capp->setObjectName(QStringLiteral("label_capp"));

        gridLayout->addWidget(label_capp, 1, 1, 1, 1);

        label_8 = new QLabel(PwhManagement);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 1, 2, 1, 1);

        label_measure = new QLabel(PwhManagement);
        label_measure->setObjectName(QStringLiteral("label_measure"));

        gridLayout->addWidget(label_measure, 1, 3, 1, 1);

        label_4 = new QLabel(PwhManagement);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_station = new QLabel(PwhManagement);
        label_station->setObjectName(QStringLiteral("label_station"));

        gridLayout->addWidget(label_station, 2, 1, 1, 1);

        label_7 = new QLabel(PwhManagement);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 2, 1, 1);

        label_measurement = new QLabel(PwhManagement);
        label_measurement->setObjectName(QStringLiteral("label_measurement"));

        gridLayout->addWidget(label_measurement, 2, 3, 1, 1);

        label_5 = new QLabel(PwhManagement);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        label_operator = new QLabel(PwhManagement);
        label_operator->setObjectName(QStringLiteral("label_operator"));

        gridLayout->addWidget(label_operator, 3, 1, 1, 1);

        label_6 = new QLabel(PwhManagement);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 2, 1, 1);

        label_unit = new QLabel(PwhManagement);
        label_unit->setObjectName(QStringLiteral("label_unit"));

        gridLayout->addWidget(label_unit, 3, 3, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        widget_global = new global_widget(PwhManagement);
        widget_global->setObjectName(QStringLiteral("widget_global"));

        verticalLayout->addWidget(widget_global);

        widget = new Widget(PwhManagement);
        widget->setObjectName(QStringLiteral("widget"));

        verticalLayout->addWidget(widget);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(PwhManagement);

        QMetaObject::connectSlotsByName(PwhManagement);
    } // setupUi

    void retranslateUi(QWidget *PwhManagement)
    {
        PwhManagement->setWindowTitle(QApplication::translate("PwhManagement", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("PwhManagement", "\344\272\247\345\223\201\344\277\241\346\201\257\347\273\223\346\236\204\346\240\221:", Q_NULLPTR));
        label_2->setText(QApplication::translate("PwhManagement", "\346\211\200\345\261\236\344\272\247\345\223\201\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_product->setText(QString());
        label_9->setText(QApplication::translate("PwhManagement", "\346\265\213\351\207\217\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        label_date->setText(QString());
        label_3->setText(QApplication::translate("PwhManagement", "\346\211\200\345\261\236\345\267\245\350\211\272\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_capp->setText(QString());
        label_8->setText(QApplication::translate("PwhManagement", "\346\265\213\351\207\217\344\272\272\357\274\232", Q_NULLPTR));
        label_measure->setText(QString());
        label_4->setText(QApplication::translate("PwhManagement", "\345\267\245\347\253\231\345\217\267\357\274\232", Q_NULLPTR));
        label_station->setText(QString());
        label_7->setText(QApplication::translate("PwhManagement", "\346\265\213\351\207\217\346\226\271\346\263\225\357\274\232", Q_NULLPTR));
        label_measurement->setText(QString());
        label_5->setText(QApplication::translate("PwhManagement", "\344\275\234\344\270\232\345\221\230\357\274\232", Q_NULLPTR));
        label_operator->setText(QString());
        label_6->setText(QApplication::translate("PwhManagement", "\346\225\260\346\215\256\345\215\225\344\275\215\357\274\232", Q_NULLPTR));
        label_unit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PwhManagement: public Ui_PwhManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PWHMANAGEMENT_H
