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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PwhManagement
{
public:
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTreeView *tree_product;
    QFrame *line;
    QWidget *widget_video_player;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_modify;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_add_std;
    QPushButton *button_detail;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_3;
    QLabel *label_12;
    QLabel *label_8;
    QLabel *label_13;
    QLabel *label_4;
    QLabel *label_14;
    QLabel *label_7;
    QLabel *label_15;
    QLabel *label_5;
    QLabel *label_16;
    QLabel *label_6;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;

    void setupUi(QWidget *PwhManagement)
    {
        if (PwhManagement->objectName().isEmpty())
            PwhManagement->setObjectName(QStringLiteral("PwhManagement"));
        PwhManagement->resize(1032, 615);
        horizontalLayout_4 = new QHBoxLayout(PwhManagement);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
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

        widget_video_player = new QWidget(PwhManagement);
        widget_video_player->setObjectName(QStringLiteral("widget_video_player"));

        verticalLayout_2->addWidget(widget_video_player);

        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(3, 1);

        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        button_modify = new QPushButton(PwhManagement);
        button_modify->setObjectName(QStringLiteral("button_modify"));

        horizontalLayout->addWidget(button_modify);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        button_add_std = new QPushButton(PwhManagement);
        button_add_std->setObjectName(QStringLiteral("button_add_std"));
        button_add_std->setEnabled(false);

        horizontalLayout->addWidget(button_add_std);

        button_detail = new QPushButton(PwhManagement);
        button_detail->setObjectName(QStringLiteral("button_detail"));

        horizontalLayout->addWidget(button_detail);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(PwhManagement);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_10 = new QLabel(PwhManagement);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 0, 1, 1, 1);

        label_9 = new QLabel(PwhManagement);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 0, 2, 1, 1);

        label_11 = new QLabel(PwhManagement);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 0, 3, 1, 1);

        label_3 = new QLabel(PwhManagement);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_12 = new QLabel(PwhManagement);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 1, 1, 1, 1);

        label_8 = new QLabel(PwhManagement);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 1, 2, 1, 1);

        label_13 = new QLabel(PwhManagement);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 1, 3, 1, 1);

        label_4 = new QLabel(PwhManagement);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_14 = new QLabel(PwhManagement);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 2, 1, 1, 1);

        label_7 = new QLabel(PwhManagement);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 2, 1, 1);

        label_15 = new QLabel(PwhManagement);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout->addWidget(label_15, 2, 3, 1, 1);

        label_5 = new QLabel(PwhManagement);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        label_16 = new QLabel(PwhManagement);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout->addWidget(label_16, 3, 1, 1, 1);

        label_6 = new QLabel(PwhManagement);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 2, 1, 1);

        label_17 = new QLabel(PwhManagement);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout->addWidget(label_17, 3, 3, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        widget_2 = new QWidget(PwhManagement);
        widget_2->setObjectName(QStringLiteral("widget_2"));

        verticalLayout->addWidget(widget_2);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        horizontalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(PwhManagement);

        QMetaObject::connectSlotsByName(PwhManagement);
    } // setupUi

    void retranslateUi(QWidget *PwhManagement)
    {
        PwhManagement->setWindowTitle(QApplication::translate("PwhManagement", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("PwhManagement", "\344\272\247\345\223\201\344\277\241\346\201\257\347\273\223\346\236\204\346\240\221:", Q_NULLPTR));
        button_modify->setText(QApplication::translate("PwhManagement", "\344\277\256\346\224\271", Q_NULLPTR));
        button_add_std->setText(QApplication::translate("PwhManagement", "\346\267\273\345\212\240\345\210\260\346\240\207\345\207\206\345\267\245\346\227\266", Q_NULLPTR));
        button_detail->setText(QApplication::translate("PwhManagement", "\350\257\246\347\273\206\344\277\241\346\201\257", Q_NULLPTR));
        label_2->setText(QApplication::translate("PwhManagement", "\346\211\200\345\261\236\344\272\247\345\223\201\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_10->setText(QString());
        label_9->setText(QApplication::translate("PwhManagement", "\346\265\213\351\207\217\346\227\245\346\234\237\357\274\232", Q_NULLPTR));
        label_11->setText(QString());
        label_3->setText(QApplication::translate("PwhManagement", "\346\211\200\345\261\236\345\267\245\350\211\272\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_12->setText(QString());
        label_8->setText(QApplication::translate("PwhManagement", "\346\265\213\351\207\217\344\272\272\357\274\232", Q_NULLPTR));
        label_13->setText(QString());
        label_4->setText(QApplication::translate("PwhManagement", "\345\267\245\347\253\231\345\217\267\357\274\232", Q_NULLPTR));
        label_14->setText(QString());
        label_7->setText(QApplication::translate("PwhManagement", "\346\265\213\351\207\217\346\226\271\346\263\225\357\274\232", Q_NULLPTR));
        label_15->setText(QString());
        label_5->setText(QApplication::translate("PwhManagement", "\344\275\234\344\270\232\345\221\230\357\274\232", Q_NULLPTR));
        label_16->setText(QString());
        label_6->setText(QApplication::translate("PwhManagement", "\346\225\260\346\215\256\345\215\225\344\275\215\357\274\232", Q_NULLPTR));
        label_17->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PwhManagement: public Ui_PwhManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PWHMANAGEMENT_H
