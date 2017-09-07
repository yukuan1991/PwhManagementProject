#include "util.h"
#include <QCoreApplication>

QString Util::exePath()
{
    return QCoreApplication::applicationDirPath();
}

QList<ToolUtil> Util::parse(QVariant data)
{
    QList<ToolUtil> toolList;
    if(data.isNull())
    {
        return toolList;
    }

    const auto treeItemList = data.toMap()["itemList"].toList();
    for(auto & it : treeItemList)
    {
        ToolUtil toolItem;
        toolItem.parentId = it.toMap()["parentId"].toInt();
        toolItem.id = it.toMap()["id"].toInt();
        toolItem.text = it.toMap()["text"].toString();
        toolItem.tooltip = it.toMap ()["tooltip"].toString();
        toolItem.toolicon = it.toMap ()["toolicon"].toString();

        toolList.append(toolItem);
    }

    return toolList;
}
