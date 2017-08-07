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

void PwhManagementMain::initConn()
{
    connect(ui->rib, &PwhManagementRibbon::fileNew, this, &PwhManagementMain::fileNew);
}

not_null<PwhManagement *> PwhManagementMain::createWindow()
{
    auto ptr_win = make_unique<PwhManagement> ();
    ptr_win->setAttribute(Qt::WA_DeleteOnClose);
    auto w = ui->mdi->addSubWindow(ptr_win.get());
    w->setWindowState(Qt::WindowMaximized);
    return ptr_win.release();
}
