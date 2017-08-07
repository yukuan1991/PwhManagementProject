#ifndef DELEGATE_LEFT_H
#define DELEGATE_LEFT_H


#include <QStyledItemDelegate>


class delegate_left : public QStyledItemDelegate
{
public:
    delegate_left (QObject* parent);

    QWidget *createEditor (QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData (QWidget* editor, const QModelIndex& index) const override;
    void setModelData (QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry (QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
    ~ delegate_left () override;
};


#endif // DELEGATE_LEFT_H
