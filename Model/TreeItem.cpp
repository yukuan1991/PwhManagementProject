#include "TreeItem.h"

TreeItem::TreeItem(const QList<QVariant> &data, TreeItem *parent)
{
    parentItem_ = parent;
    itemData_ = data;
}

TreeItem::~TreeItem()
{
    qDeleteAll(childItems_);
}

void TreeItem::appendChild(TreeItem *child)
{
    childItems_.append(child);
}

TreeItem *TreeItem::child(int row)
{
    return childItems_.value(row);
}

int TreeItem::childCount() const
{
    return childItems_.count();
}

int TreeItem::columnCount() const
{
    return itemData_.count();
}

QVariant TreeItem::data(int column) const
{
    return itemData_.value(column);
}

int TreeItem::row() const
{
    if(parentItem_)
    {
        return parentItem_->childItems_.indexOf(const_cast<TreeItem*>(this));
    }

    return 0;
}

TreeItem *TreeItem::parent()
{
    return parentItem_;
}


