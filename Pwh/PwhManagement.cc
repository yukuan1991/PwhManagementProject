#include "PwhManagement.h"
#include "ui_pwhmanagement.h"
#include <boost/filesystem.hpp>
#include <Qt-Utils/qt.hpp>
#include <Qt-Utils/krys_application.hpp>
#include <boost/scope_exit.hpp>
#include "data_veryfication.h"
#include "arithmetic_resource.hpp"

#include <QDebug>

PwhManagement::PwhManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PwhManagement)
{
    ui->setupUi(this);

    ui->tree_product->setModel (fs_model_.get());
    assert (boost::filesystem::exists (PRODUCT_PATH));
    fs_model_->setRootPath(PRODUCT_PATH);
    ui->tree_product->setRootIndex(fs_model_->index(PRODUCT_PATH));
    fs_model_->set_master(PRODUCT_PATH);
    ui->tree_product->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tree_product->header()->hide();
}

PwhManagement::~PwhManagement()
{
    delete ui;
}

void PwhManagement::on_tree_product_clicked(const QModelIndex &index)
{
    qDebug() << "on_tree_product_clicked";
    const auto path = index.data (QFileSystemModel::FilePathRole);
    assert (path.type () == QVariant::String);

    QFileInfo finfo {path.toString ()};
    if (!finfo.isFile ())
    {
        return;
    }

    ui->widget_video_player->setEnabled (false);

    const auto qstr_path = path.toString ();
    QFileInfo info (qstr_path);
    const auto capp_dir = info.dir ();
    auto product_dir = capp_dir;
    bool is_ok;
    is_ok = product_dir.cdUp (); assert (is_ok);
    auto master_dir = product_dir;
    is_ok = master_dir.cdUp (); assert (is_ok);

    auto master_gbk = unicode_to_system (master_dir.absolutePath ().toStdString ());
    auto product_gbk = unicode_to_system (PRODUCT_PATH);

    if (boost::filesystem::equivalent (master_gbk, product_gbk))
    {
        clear_info ();
        current_file_name_ = info.baseName ();
        current_path_ = std::move (qstr_path);
        data_extraction (current_path_);
    }

}

void PwhManagement::show_data(const nlohmann::json &data, const QString &path)
{
    QFileInfo path_info {path};
    auto capp_path = path_info.dir ();
    QFileInfo capp_info {capp_path.absolutePath ()};
    QString capp_name = capp_info.fileName ();
    auto product_dir = capp_info.dir ();
    QFileInfo product_info {product_dir.absolutePath ()};
    QString product_name = product_info.fileName ();

    ui->label_capp->setText (capp_name);
    ui->label_product->setText (product_name);
    const auto& json_attachment = data["附加信息"];

    show_attachment (json_attachment);

    auto method = get_method (data);
    current_method_ = method;

    const auto& json_chart = data["表"];
    assert (!json_chart.is_null ());
    refresh_global_info (json_chart["信息总览"], method);
}

void PwhManagement::data_extraction(const QString &path)
{
    assert (QFile::exists (path));
    std::string system_path = unicode_to_system (path.toStdString ());
    std::weak_ptr<bool> wp = alive_;

    go [=] ()
    {
        std::function<void ()> response;
        BOOST_SCOPE_EXIT_ALL (&)
        {
            call_after response;
        };

        auto data_json = krys::read_all (system_path);
        assert (data_json);

        auto j_file = stdtime_data_veryfication(data_json->data ());

        response = [] ()
        {
        };

        if (!j_file)
        {
            return;
        }

        current_info_ = *j_file;

        auto tmp = [=] (json _j_file, QString _path)
        {
            if (wp.expired ()) return;
//            ui->button_modify->setEnabled (true);
//            ui->button_detail->setEnabled (true);
//            ui->button_add_to_std->setEnabled (true);
            if (video_update ())
            {
                this->show_data (_j_file, _path);
            }
        };

        response = std::bind (tmp, std::move (*j_file), std::move (path));
    };
}

void PwhManagement::show_attachment(const nlohmann::json &data)
{
    struct name_map
    {
        QLabel* label;
        const char* key;
    };

    name_map name_label_map [] =
    {
        {ui->label_station, "工站号"},
        {ui->label_operator, "作业员"},
        {ui->label_unit, "数据单位"},
        {ui->label_measure, "测量人"},
        {ui->label_measurement, "测量方法"},
        {ui->label_date, "测量日期"}
    };

    for (auto& iter : name_label_map)
    {
        set_label_for_data (data, iter.key, iter.label);
    }
}

void PwhManagement::set_label_for_data(const nlohmann::json &data, const char *name, QLabel *label)
{
    assert (name); assert (label);
    const auto& sub_data = data[name];
    assert (sub_data.is_string ());

    std::string str_data = sub_data;
    label->setText (str_data.data ());
}

void PwhManagement::refresh_global_info(const nlohmann::json &global_data, const QString &method)
{
    ui->widget_global->update_table_data (global_data);
    ui->widget_global->refresh_table ();

    if (method == "视频分析法")
    {
        assert (ui->widget_global->hide_table_column ("预定工时法总代码"));
        assert (ui->widget_global->hide_table_column ("数量*频次"));
        assert (ui->widget_global->hide_table_column ("公司内部代码"));
    }
    else if (method == "预定工时法")
    {
        assert (ui->widget_global->hide_table_column ("测量时间"));
        assert (ui->widget_global->hide_table_column ("公司内部代码"));
    }
    else if (method == "标准资料法")
    {
        assert (ui->widget_global->hide_table_column ("测量时间"));
        assert (ui->widget_global->hide_table_column ("预定工时法总代码"));
        assert (ui->widget_global->hide_table_column ("评比系数"));
        assert (ui->widget_global->hide_table_column ("增值/非增值"));
        assert (ui->widget_global->hide_table_column ("操作分类"));
    }
}

void PwhManagement::clear_info()
{
    ui->widget_global->set_model (nullptr);
    ui->label_capp->clear ();
    ui->label_date->clear ();
    ui->label_measure->clear ();
    ui->label_measurement->clear ();
    ui->label_operator->clear ();
    ui->label_unit->clear ();
    ui->label_product->clear ();
    ui->label_station->clear ();
}

bool PwhManagement::video_update()
{

}
