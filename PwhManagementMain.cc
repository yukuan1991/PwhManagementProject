﻿#include "PwhManagementMain.h"
#include "ui_pwhmanagementmain.h"
#include "Pwh/PwhManagement.h"
#include <memory>
#include <QMdiSubWindow>

using namespace std;
PwhManagementMain::PwhManagementMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PwhManagementMain)
{
    ui->setupUi(this);
    ui->mdi->setViewMode(QMdiArea::TabbedView);

    initConn();
}

PwhManagementMain::~PwhManagementMain()
{
    delete ui;
}

void PwhManagementMain::fileNew()
{
    createWindow();
}

void PwhManagementMain::detailedInfo()
{
    qDebug() << "detailedInfo";
    auto w = activeWindow();
    if(w == nullptr)
    {
        return;
    }

    w->on_button_detail_clicked();
}

void PwhManagementMain::initConn()
{
    connect(ui->rib, &PwhManagementRibbon::fileNew, this, &PwhManagementMain::fileNew);
    connect(ui->rib, &PwhManagementRibbon::detailedInfoClicked, this, &PwhManagementMain::detailedInfo);

}

not_null<PwhManagement *> PwhManagementMain::createWindow()
{
    auto ptr_win = make_unique<PwhManagement> ();
    ptr_win->setAttribute(Qt::WA_DeleteOnClose);
    auto w = ui->mdi->addSubWindow(ptr_win.get());
    w->setWindowState(Qt::WindowMaximized);
    return ptr_win.release();
}

PwhManagement *PwhManagementMain::activeWindow()
{
    if(QMdiSubWindow* activeSubWindow = ui->mdi->activeSubWindow())
    {
        auto w = dynamic_cast<PwhManagement*>(activeSubWindow->widget());
        return w;
    }
    else
    {
        return nullptr;
    }
}
