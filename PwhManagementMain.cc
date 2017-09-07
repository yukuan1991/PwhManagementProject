#include "PwhManagementMain.h"
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

void PwhManagementMain::modifyClicked()
{
    auto w = activeWindow();
    if(w == nullptr)
    {
        return;
    }

    w->on_button_modify_clicked();
}

void PwhManagementMain::addStdDatabase()
{
    auto w = activeWindow();
    if(w == nullptr)
    {
        return;
    }

    w->on_button_addStdDatabase_clicked();
}

void PwhManagementMain::initConn()
{
    connect(ui->rib, &PwhManagementRibbon::fileNew, this, &PwhManagementMain::fileNew);
    connect(ui->rib, &PwhManagementRibbon::detailedInfoClicked, this, &PwhManagementMain::detailedInfo);
    connect(ui->rib, &PwhManagementRibbon::modifyClicked, this, &PwhManagementMain::modifyClicked);
    connect(ui->rib, &PwhManagementRibbon::addStdDatabaseClicked, this, &PwhManagementMain::addStdDatabase);


}

not_null<PwhManagement *> PwhManagementMain::createWindow()
{
    auto ptr_win = make_unique<PwhManagement> ();

    qDebug () << __PRETTY_FUNCTION__ << " " << __LINE__;
    ptr_win->setAttribute(Qt::WA_DeleteOnClose);

    qDebug () << __PRETTY_FUNCTION__ << " " << __LINE__;
    auto w = ui->mdi->addSubWindow(ptr_win.get());

    qDebug () << __PRETTY_FUNCTION__ << " " << __LINE__;
    w->setWindowState(Qt::WindowMaximized);
    qDebug () << __PRETTY_FUNCTION__ << " " << __LINE__;

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
