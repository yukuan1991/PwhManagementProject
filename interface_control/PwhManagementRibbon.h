#ifndef PWHMANAGEMENTRIBBON_H
#define PWHMANAGEMENTRIBBON_H
#include "interface_control/Ribbon.h"

class PwhManagementRibbon : public Ribbon
{
    Q_OBJECT
signals:
    void addClicked();
    void modifyClicked();
    void deleteClicked();

    void detailedInfoClicked();
public:
    PwhManagementRibbon(QWidget* parent = nullptr);
    RibbonTool* add_, *modify_, * delete_;
    RibbonTool* detailedInfo_;
private:
    void initConn();
};

#endif // PWHMANAGEMENTRIBBON_H
