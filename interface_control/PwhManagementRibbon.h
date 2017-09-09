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

    void addStdDatabaseClicked();
    void detailedInfoClicked();
    void exportPDFClicked();
    void reportHeaderClicked();
public:
    PwhManagementRibbon(QWidget* parent = nullptr);
    RibbonTool* add_, *modify_, * delete_;
    RibbonTool* addStdDatabase_;
    RibbonTool* detailedInfo_;
    RibbonTool* exportPDF_;
    RibbonTool* reportHeader_;
private:
    void initConn();
};

#endif // PWHMANAGEMENTRIBBON_H
