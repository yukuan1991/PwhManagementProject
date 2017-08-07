#ifndef DELEGATE_RESULT_H
#define DELEGATE_RESULT_H
#include <QStyledItemDelegate>
#include "stl_extension.hpp"


class delegate_result : public QStyledItemDelegate
{
public:
    delegate_result (QObject* parent);

    QWidget *createEditor (QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData (QWidget* editor, const QModelIndex& index) const override;
    void setModelData (QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry (QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
    ~ delegate_result () override;
};

#endif // DELEGATE_RESULT_H
