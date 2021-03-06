﻿#ifndef PWHMANAGEMENTMAIN_H
#define PWHMANAGEMENTMAIN_H

#include <QWidget>
#include <base/lang/not_null.h>
namespace Ui {
class PwhManagementMain;
}

class PwhManagement;

class PwhManagementMain : public QWidget
{
    Q_OBJECT

public:
    explicit PwhManagementMain(QWidget *parent = 0);
    ~PwhManagementMain();

private:
    void fileNew();
private:
    void detailedInfo();
    void modifyClicked();
private:
    void initConn();
private:
    not_null<PwhManagement*> createWindow();
    PwhManagement* activeWindow();
private:
    Ui::PwhManagementMain *ui;
};

#endif // PWHMANAGEMENTMAIN_H
