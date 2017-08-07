#include "stdtime_delegate.h"
#include <QLineEdit>
#include <QDoubleSpinBox>
#include "Qt-Utils/stl_extension.hpp"
#include <QSpinBox>
#include <QComboBox>

stdtime_delegate::stdtime_delegate(QObject* parent)
    :QStyledItemDelegate (parent)
{

}

QWidget *stdtime_delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &index) const
{
    auto model = index.model (); assert (model);

    auto var = model->headerData (index.column (), Qt::Horizontal, Qt::DisplayRole);
    assert (var.type () == QVariant::String);

    QString header = var.toString ();

    if (header == "作业内容")
    {
        return new QLineEdit {parent};
    }
    else if (header == "数量*频次")
    {
        QSpinBox* spin_box = new QSpinBox {parent};
        spin_box->setRange (1,10);
        return spin_box;
    }
    else if (header == "宽放率")
    {
        return new QLineEdit {parent};
    }
    else if (header == "操作分类")
    {
        QComboBox* combo = new QComboBox {parent};
        QStringList items;
        items << "加工" << "检查" << "搬运" << "等待";
        combo->addItems (items);
        return combo;
    }

    return nullptr;
}

void stdtime_delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    auto model = index.model (); assert (model);
    auto var = model->headerData (index.column (), Qt::Horizontal, Qt::DisplayRole);
    assert (var.type () == QVariant::String);

    QString header = var.toString ();
    assert (editor);
    QVariant cell_data = index.data ();

    if (header == "作业内容")
    {
        if (cell_data.type () == QVariant::String)
        {
            auto line_edit = dynamic_cast<QLineEdit*>(editor); assert (line_edit);
            line_edit->setText (index.data ().toString ());
        }
    }
    else if (header == "数量*频次")
    {
        auto spin_box = dynamic_cast<QSpinBox*>(editor); assert (spin_box);
        if (cell_data.type () == QVariant::Int)
        {
            spin_box->setValue (index.data().toInt());
        }
        else
        {
            spin_box->setValue (1);
        }
    }
    else if (header == "宽放率")
    {
        auto line_edit = dynamic_cast<QLineEdit*>(editor); assert (line_edit);
        if (cell_data.type () == QVariant::String)
        {
            line_edit->setText (delete_percent (index.data().toString()));
        }
        else
        {
            line_edit->setText (QString("0"));
        }
    }
    else if (header == "操作分类")
    {
        auto comb = dynamic_cast<QComboBox*>(editor); assert (comb);
        if (cell_data.type () == QVariant::String)
        {
            comb->setEditable (false);
            comb->setCurrentIndex (comb->findText (index.data ().toString ()));
        }
    }

    return;
}

void stdtime_delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    assert (model);
    auto var = model->headerData (index.column (), Qt::Horizontal, Qt::DisplayRole);
    assert (var.type () == QVariant::String);

    QString header = var.toString ();
    assert (editor);

    if (header == "作业内容")
    {
        auto line_edit = dynamic_cast<QLineEdit*>(editor); assert (line_edit);
        model->setData (index, line_edit->text ());
    }
    else if (header == "数量*频次")
    {
        auto spin_box = dynamic_cast<QSpinBox*>(editor); assert (spin_box);
        model->setData (index, spin_box->value());
    }
    else if (header == "宽放率")
    {
        auto line_edit = dynamic_cast<QLineEdit*>(editor); assert (line_edit);
        bool is_ok;
        auto val = line_edit->text().toDouble (&is_ok);
        if (is_ok)
        {
            model->setData (index, val / 100, Qt::EditRole);
            return;
        }
        else
        {
            return;
        }
    }
    else if (header == "操作分类")
    {
        auto comb = dynamic_cast<QComboBox*>(editor); assert (comb);
        model->setData (index, comb->currentText());
    }

    return;
}

void stdtime_delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &) const
{
    editor->setGeometry (option.rect);
}

stdtime_delegate::~stdtime_delegate()
{

}

QString stdtime_delegate::delete_percent(const QString &qstr)
{
    auto str = qstr.toStdString ();
    auto pos = str.find_first_of (' ');
    assert (pos != std::string::npos);
    str.erase(pos);
    return str.data ();
}
