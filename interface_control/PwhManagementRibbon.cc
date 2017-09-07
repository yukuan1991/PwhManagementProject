#include "PwhManagementRibbon.h"
#include <base/lang/move.hpp>

PwhManagementRibbon::PwhManagementRibbon(QWidget *parent)
    : Ribbon(parent)
{
    {
        std::array<UiGroup, 1> edit;

        ButtonCell b;

//        b.add("新增", QPixmap("png/新增.png"), add_);
        b.add("修改", QPixmap("png/修改.png"), modify_);
//        b.add("删除", QPixmap("png/删除.png"), delete_);
        b.add("添加到标准工时", QPixmap("png/修改.png"), addStdDatabase_);
        b.set_title("报表管理");

        edit[0] = ::move(b);


        setupTab(edit, "编辑");
    }

    {
        std::array<UiGroup, 1> info;

        ButtonCell b;

        b.add("详细信息", QPixmap("png/详细信息.png"), detailedInfo_);
        b.set_title("信息");

        info[0] = ::move(b);

        setupTab(info, "查看");
    }

    initConn();
}

void PwhManagementRibbon::initConn()
{
//    connect(add_, &RibbonTool::clicked, this, &PwhManagementRibbon::addClicked);
    connect(modify_, &RibbonTool::clicked, this, &PwhManagementRibbon::modifyClicked);
//    connect(delete_, &RibbonTool::clicked, this, &PwhManagementRibbon::deleteClicked);
    connect(detailedInfo_, &RibbonTool::clicked, this, &PwhManagementRibbon::detailedInfoClicked);
    connect(addStdDatabase_, &RibbonTool::clicked, this, &PwhManagementRibbon::addStdDatabaseClicked);

}
