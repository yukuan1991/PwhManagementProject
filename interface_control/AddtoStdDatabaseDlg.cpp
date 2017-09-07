#include "AddtoStdDatabaseDlg.h"
#include "ui_addtostddatabasedlg.h"

AddtoStdDatabaseDlg::AddtoStdDatabaseDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddtoStdDatabaseDlg)
{
    ui->setupUi(this);
}

AddtoStdDatabaseDlg::~AddtoStdDatabaseDlg()
{
    delete ui;
}
