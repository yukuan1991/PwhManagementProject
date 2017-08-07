#ifndef DELEGATE_RIGHT_H
#define DELEGATE_RIGHT_H

#include <QStyledItemDelegate>


class delegate_right : public QStyledItemDelegate
{
public:
    delegate_right (QObject* parent);

    QWidget *createEditor (QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData (QWidget* editor, const QModelIndex& index) const override;
    void setModelData (QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry (QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
    ~ delegate_right () override;
};
#endif // DELEGATE_RIGHT_H
