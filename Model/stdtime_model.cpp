#include "stdtime_model.h"
#include <boost/scope_exit.hpp>
#include "Qt-Utils/stl_extension.hpp"
#include <QDebug>

stdtime_model::stdtime_model(QObject *parent)
    : json_model (parent)
{
    headers_  << "作业内容"<<"公司内部代码" << "标准操作单元作业内容" << "历史来源" /*<< "视频路径"*/
              << "预定工时法总代码" << "标准操作单元基本时间"<< "数量*频次" << "基本时间" << "宽放率" << "标准时间"
              <<"增值/非增值" << "操作分类";

    edit_col_ << "作业内容" << "公司内部代码" << "标准操作单元作业内容" << "历史来源" << "标准操作单元基本时间"
              << "预定工时法总代码" << "数量*频次" << "宽放率" << "操作分类";

    paste_col_ << "作业内容" << "公司内部编码" << "数量*频次" << "基本时间" << "宽放率" << "操作分类";
    resize_helper (12);
}

QVariant stdtime_model::data(const QModelIndex &index, int role) const
{
    QVariant var;

    if (role != Qt::DisplayRole)
    {
        return json_model::data (index, role);
    }

    auto op_header = get_header (index);

    if (!op_header)
    {
        return {};
    }

    if (*op_header == "增值/非增值")
    {
        return increamental_info (index);
    }

    if (*op_header == "宽放率")
    {
        return get_allowance (index, role);
    }

    if (*op_header == "基本时间")
    {
        return get_base_time (index, role);
    }

    if (*op_header == "标准时间")
    {
        return get_std_time (index, role);
    }

    var = json_model::data (index, role);

    if (var.type() == QVariant::Double)
    {
        auto double_var = var.toDouble ();
        var = QString::number (double_var, 'f', 2).toDouble ();
    }

    return var;
}

bool stdtime_model::setData(const QModelIndex &index, const QVariant &value, int role)
{
    BOOST_SCOPE_EXIT_ALL (&)
    {
        emit dataChanged (index, index);
    };

    if (role == paste_role)
    {
        return paste_data (index, value);
    }

    if (role != Qt::EditRole)
    {
        return false;
    }

    auto op_header = get_header (index);
    assert (op_header);
    if (*op_header == "操作分类")
    {
        return set_op_type (index, value, role);
    }

    if (*op_header == "宽放率")
    {
        return set_allowance (index, value, role);
    }

    if (*op_header == "标准操作单元基本时间")
    {
        if (value.isValid ())
        {
            bool is_ok;
            auto double_value = value.toDouble (&is_ok);
            assert (is_ok);
            return json_model::setData (index, double_value, role);
        }
    }

    return json_model::setData (index, value, role);
}

void stdtime_model::resize(unsigned size)
{
    resize_helper (size);
}

void stdtime_model::clear()
{
    resize (0);
}

void stdtime_model::erase_row(unsigned row)
{
    assert (static_cast<int>(row) < rowCount ());

    for (int col = 0; col < columnCount (); col ++)
    {
        auto index = this->index (row, col);
        assert (index.isValid ());
        if (col == get_col_from_name ("操作分类"))
        {
            setData (index, "加工", Qt::EditRole);
        }
        else if (col == get_col_from_name ("宽放率"))
        {
            setData (index, double {0}, Qt::EditRole);
        }
        else if (col == get_col_from_name ("数量*频次"))
        {
            setData (index, 1, Qt::EditRole);
        }
        else if (col == get_col_from_name ("作业内容"))
        {
            continue;
        }
        else
        {
            setData (index, {}, Qt::EditRole);
        }

    }
}

QString stdtime_model::get_std_sum()
{
    auto col = get_col_from_name ("标准时间");
    double sum = 0;
    for (int row = 0; row < rowCount (); ++row)
    {
        auto pos = index (row, col);
        auto vat = data (pos);
        if (vat.isNull ())
        {
            continue;
        }
        else
        {
            auto time = vat.toDouble ();
            sum += time;
        }
    }
    return QString::number(sum, 'f', 2);
}

bool stdtime_model::change_company_code(const QModelIndex &, const QVariant &)
{
    return false;
}

bool stdtime_model::set_allowance(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole)
    {
        if (value.type () == QVariant::Double)
        {
            return json_model::setData (index, value, role);
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool stdtime_model::paste_allowance(const QModelIndex &index, const QVariant &value)
{
    auto value_str = value.toString ();
    auto list = value_str.split (' ');
    if (list.size () == 1)
    {
        auto tmp = list[0];
        list = tmp.split ('%');
    }

    if (!list.empty ())
    {
        bool is_ok;
        auto double_value = list[0].toDouble (&is_ok);
        if (is_ok)
        {
            double_value /= 100;
            return setData (index, double_value, Qt::EditRole);
        }
    }
    return false;
}

QVariant stdtime_model::get_std_time(const QModelIndex &index, int) const
{
    auto col = get_col_from_name ("基本时间");
    auto std_base_index = this->index(index.row (), col); assert (std_base_index.isValid ());

    auto std_base_time = std_base_index.data (Qt::DisplayRole);

    if (!std_base_time.isValid ())
    {
        return {};
    }
    else
    {
        assert (std_base_time.type () == QVariant::Double);
        auto double_std_time = std_base_time.toDouble ();

        col = get_col_from_name ("宽放率");
        assert (col != -1);
        auto allowance_index = this->index (index.row (), col);

        auto allowance_data = json_model::data (allowance_index, Qt::DisplayRole);

        assert (allowance_data.type () == QVariant::Double);

        return double_std_time * (allowance_data.toDouble () + 1);
    }

}

QVariant stdtime_model::get_allowance(const QModelIndex &index, int role) const
{
    auto value = json_model::data (index, role);
    assert (value.type () == QVariant::Double or value.isNull ());

    auto double_value = value.toDouble (); assert (!(double_value < 0));

    return QString::number (double_value * 100, 'f', 1) + " %";
}

bool stdtime_model::set_op_type(const QModelIndex &index, const QVariant &value, int role)
{
    auto str_value = value.toString ();
    if (!(str_value == "加工" or str_value == "等待" or str_value == "检查" or str_value == "搬运")
            and role == Qt::EditRole)
    {
        return false;
    }
    return json_model::setData (index, value, role);
}

void stdtime_model::resize_helper(unsigned size)
{
    auto row_count = rowCount ();

    json_model::resize (size);

    for (unsigned row = row_count; row < size; row ++)
    {
        erase_row (row);
    }
}

QVariant stdtime_model::get_base_time(const QModelIndex &index, int) const
{
    auto col = get_col_from_name ("标准操作单元基本时间");
    assert (col != -1);

    auto std_base_index = this->index(index.row (), col); assert (std_base_index.isValid ());
    auto std_base_time = std_base_index.data (Qt::DisplayRole);
    if (!std_base_time.isValid ())
    {
        return {};
    }
    else
    {
        //assert (std_base_time.type () == QVariant::Double);
        auto double_std_time = std_base_time.toDouble ();

        col = get_col_from_name ("数量*频次");
        assert (col != -1);
        auto rate_index = this->index (index.row (), col);

        auto rate_data = rate_index.data (Qt::DisplayRole);
        assert (rate_data.type () == QVariant::Int);

        return double {double_std_time * rate_data.toInt ()};
    }
}

QVariant stdtime_model::increamental_info(const QModelIndex &index) const
{
    auto col = get_col_from_name ("操作分类");
    auto row = index.row ();
    auto type_index = this->index (row, col); assert (type_index.isValid ());

    auto variant_type = type_index.data (Qt::DisplayRole);
    auto str_type = variant_type.toString ();
    if (str_type == "加工")
    {
        return "增值";
    }
    else
    {
        return "非增值";
    }
}

bool stdtime_model::paste_data(const QModelIndex &index, const QVariant &value)
{
    auto op_header = get_header (index);
    assert (op_header);

    if (*op_header == "宽放率")
    {
        paste_allowance (index, value);
    }

    return json_model::paste_data (index, value);
}
