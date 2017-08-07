#ifndef STDTIME_DELEGATE_H
#define STDTIME_DELEGATE_H
#include <QStyledItemDelegate>


class stdtime_delegate : public QStyledItemDelegate
{
public:
    stdtime_delegate(QObject* parent = nullptr);

    QWidget *createEditor (QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData (QWidget* editor, const QModelIndex& index) const override;
    void setModelData (QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry (QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
    ~ stdtime_delegate () override;

    static QString delete_percent (const QString& qstr);
};

#endif // STDTIME_DELEGATE_H
