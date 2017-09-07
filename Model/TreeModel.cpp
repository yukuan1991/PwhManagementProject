#include "TreeModel.h"
#include "TreeItem.h"

TreeModel::TreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    QList<QVariant> rootData;
    rootData << "Title";
    rootItem_ = new TreeItem(rootData);
}

TreeModel::~TreeModel()
{
    delete rootItem_;
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant{};
    }

    TreeItem* item = static_cast<TreeItem*>(index.internalPointer());

    ToolUtil toolUtil;
    for(int i = 0; i < toolList_.count(); i++)
    {
        toolUtil = toolList_.at(i);
        if(toolUtil.id == item->data(0))
        {
            break;
        }
    }

    if(role == Qt::DisplayRole)
    {
        return toolUtil.text;
    }
    else if(role == Qt::ToolTipRole)
    {
        return toolUtil.tooltip;
    }
    else
    {
        return QVariant();
    }
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return 0;
    }

    return QAbstractItemModel::flags(index);
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal and role == Qt::DisplayRole)
    {
        return rootItem_->data(section);
    }

    return QVariant{};
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!hasIndex(row, column, parent))
    {
        return QModelIndex();
    }

    TreeItem* parentItem;
    if(!parent.isValid())
    {
        parentItem = rootItem_;
    }
    else
    {
        parentItem = static_cast<TreeItem*>(parent.internalPointer());
    }

    TreeItem* childItem = parentItem->child(row);
    if(childItem)
    {
        return createIndex(row, column, childItem);
    }
    else
    {
        return QModelIndex();
    }
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return QModelIndex();
    }

    TreeItem* childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem* parentItem = childItem->parent();

    if(parentItem == rootItem_)
    {
        return QModelIndex();
    }

    return createIndex(parentItem->row(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem* parentItem;
    if(parent.column() > 0)
    {
        return 0;
    }

    if(!parent.isValid())
    {
        parentItem = rootItem_;
    }
    else
    {
        parentItem = static_cast<TreeItem*>(parent.internalPointer());
    }
    return parentItem->childCount();
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
    {
        return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
    }
    else
    {
        return rootItem_->columnCount();
    }
}

void TreeModel::setJsonData()
{
    QVariantMap value;
    QVariantList itemList;
    QVariantMap map;
    map["parentId"] = -1;
    map["id"] = 1;
    map["text"] = "第一项";
    map["tooltip"] = "这是第一项";
    map["toolicon"] = "MJJT.png";
    itemList.append (map);

    map["parentId"] = 1;
    map["id"] = 10;
    map["text"] = "第一项1";
    map["tooltip"] = "这是第一项1";
    map["toolicon"] = "MJJT.png";
    itemList.append (map);

    map["parentId"] = 1;
    map["id"] = 20;
    map["text"] = "第一项2";
    map["tooltip"] = "这是第一项1";
    map["toolicon"] = "MJJT.png";
    itemList.append(map);

    map["parentId"] = 10;
    map["id"] = 100;
    map["text"] = "第二项1";
    map["tooltip"] = "这是第一项1";
    map["toolicon"] = "MJJT.png";
    itemList.append (map);

    map["parentId"] = 20;
    map["id"] = 200;
    map["text"] = "第二项2";
    map["tooltip"] = "这是第一项1";
    map["toolicon"] = "MJJT.png";
    itemList.append (map);

    value["itemList"] = itemList;
    toolList_ = Util::parse(value);
    setupModelData(rootItem_);
}

void TreeModel::setupModelData(TreeItem *parent)
{
    QList<TreeItem*> parents;
    parents << parent;

    for(int i = 0; i < toolList_.count(); ++i)
    {
        ToolUtil tool = toolList_.at(i);
        QList<QVariant> columnData;
        columnData << tool.id;

        for(int j = 0; j < parents.count(); ++j)
        {
            TreeItem* item = this->item(parents.at(j), tool);
            if(item)
            {
                item->appendChild(new TreeItem(columnData, item));
            }
            else
            {
                parents.last()->appendChild(new TreeItem(columnData, parents.last()));
            }
        }
    }
}

TreeItem *TreeModel::item(TreeItem *item, ToolUtil tool)
{
    TreeItem* treeItem = nullptr;
    if(item == nullptr)
    {
        return treeItem;
    }

    int parentId = tool.parentId;

    if(item->data(0) == parentId)
    {
       treeItem = item;
    }
    else
    {
        for(int j = 0; j < item->childCount(); ++j)
        {
            TreeItem* childItem = item->child(j);
            TreeItem* item2 = this->item(childItem, tool);
            if(item2)
            {
                treeItem = item2;
                break;
            }
        }
    }

    return treeItem;
}


