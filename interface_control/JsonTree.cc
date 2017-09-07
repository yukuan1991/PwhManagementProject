#include "JsonTree.h"
#include <QStringList>
#include<QTreeWidgetItem>
#include <base/lang/range.hpp>
#include <boost/range/counting_range.hpp>
#include <QMessageBox>
#include <QInputDialog>
#include <QMouseEvent>
#include <QAction>
#include <QMenu>

#include <QDebug>

using std::make_unique;
using namespace boost;
using namespace boost::adaptors;

JsonTree::JsonTree(QWidget *parent)
    :QTreeWidget (parent)
{
    connect (this, &JsonTree::treeDataChanged, this, &JsonTree::resetTree);
    connect (this, &JsonTree::treeHeaderChanged, this, &JsonTree::resetHeader);
    connect (this, &JsonTree::itemSelectionChanged, this, &JsonTree::onSelectionChanged);

    setSelectionMode(QAbstractItemView::SingleSelection);
}

void JsonTree::resetHeader()
{
    QStringList header;
    treeHeader ().toList ()
            | execute ([&] (auto && c) { header << c.toString (); });

    setColumnCount (header.size ());
    setHeaderItem (new QTreeWidgetItem (header));

    resetTree ();
}

void JsonTree::resetTree()
{
    const auto data = treeData ();
    for (auto & it : data.toList ())
    {
        auto top = setupItem (it);
        if (top)
        {
            addTopLevelItem (top.release ());
        }
    }
}

JsonTree::~JsonTree()
{

}

std::unique_ptr<QTreeWidgetItem> JsonTree::setupItem (const QVariant &data)
{
    if (data.type () != QVariant::Map)
    {
        return null;
    }

    auto map = data.toMap ();
    auto ret = make_unique<QTreeWidgetItem> ();

    const auto header = headerItem ();
    counting_range (0, header->columnCount ())
            | transformed ([&] (auto && c) { return header->text (c); })
            | indexed (int {0})
            | execute ([&] (auto && c) { ret->setText (static_cast<int> (c.index ()), map [c.value ()].toString ()); });

    if (map["name"].toString ().trimmed ().isEmpty ())
    {
        return null;
    }

    ret->setText (0, map ["name"].toString ());

    const auto content = map ["content"];

    for (auto & child : content.toList ())
    {
        auto childItem = setupItem (child);
        if (childItem == null)
        {
            continue;
        }

        ret->addChild (childItem.release ());
    }

    return ret;
}

void JsonTree::onSelectionChanged()
{
    const auto selectedItems = this->selectedItems();
    if(selectedItems.size() == 0)
    {
        return;
    }
    const auto selectedItem = selectedItems.at(0);
    const auto name = selectedItem->text(0);

    QStringList list;
    list << name;
    auto parentItem = selectedItem->parent();
    auto parentItemType = selectedItem->text(1);
    while(parentItem)
    {
        list.prepend(parentItem->text(0));
        parentItemType = selectedItem->text(1);
        parentItem = parentItem->parent();
    }

    const auto totalData = treeData();
    for(int i = 0; i < list.count(); i++)
    {
        if(totalData.type() == QVariant::Map)
        {
            emit itemClicked(totalData);
        }
        else if(totalData.type() == QVariant::List)
        {
            for(int j = 0; j < totalData.toList().size(); j++)
            {
                if(totalData.toList().at(j).toMap()["name"].toString() == list.at(i))
                {
                    emit totalData.toList().at(j);
                }
            }
        }
    }

}



