#ifndef PWHMANAGEMENTMAIN_H
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
    void initConn();
private:
    not_null<PwhManagement*> createWindow();
private:
    Ui::PwhManagementMain *ui;
};

#endif // PWHMANAGEMENTMAIN_H
