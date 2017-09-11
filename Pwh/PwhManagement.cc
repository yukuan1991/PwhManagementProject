#include "PwhManagement.h"
#include "ui_pwhmanagement.h"
#include <boost/filesystem.hpp>
#include <Qt-Utils/qt.hpp>
#include <Qt-Utils/krys_application.hpp>
#include <boost/scope_exit.hpp>
#include "data_veryfication.h"
#include "arithmetic_resource.hpp"
#include "interface_control/modify_product_dlg.h"
#include <QMessageBox>
#include <QJsonDocument>
#include "interface_control/ModifyProductDlg.h"
#include "interface_control/AddtoStdDatabaseDlg.h"
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QInputDialog>

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

    dlg_.setWindowTitle("详细信息");

    ui->widget_video_player->setEnabled(false);

    connect (ui->widget_global, &global_widget::table_clicked, [=] (const QModelIndex& index)
    {
        if (current_method_ == "视频分析法")
        {
            set_video_section (index);
        }
    });

    connect (ui->widget_video_player, &video_widget::stepped_into_invalid, [=] (qint64, qint64 end)
    {
        ui->widget_video_player->set_position(end);
    });

//    JsonTree tree;
//    tree.show ();
    QVariantList list;
    list << "名称" << "类型";
    ui->treeWidget->setTreeHeader (list);
    QFile file ("test.json");
    file.open (QFile::ReadOnly);
    const auto arr = file.readAll ();
    ui->treeWidget->setTreeData (QJsonDocument::fromJson (arr).toVariant ());

//    onTreeProductClicked();
}

PwhManagement::~PwhManagement()
{
    delete ui;
}

void PwhManagement::on_tree_product_clicked(const QModelIndex &index)
{
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

void PwhManagement::onTreeProductClicked(const QVariant& data)
{
    if(data.isNull())
    {
        return;
    }
/////////////////////////////////////////////////////
    if(data.toMap()["类型"].toString() == "视频分析法")
    {
//        ui->tableWidget->setRowCount(10);
//        ui->tableWidget->setColumnCount(8);
//        QStringList list;
//        list << "作业内容" << "测量时间" << "评比系数" << "基本时间" << "宽放率" << "标准时间" << "增值/非增值" << "操作分类";
//        ui->tableWidget->setHorizontalHeaderLabels(list);
//        const auto jsonData = data.toMap()["content"];
//        const auto workdata = jsonData.toMap()["form"].toMap()["作业内容"].toList();
//        const auto
//                for(int i = 0; i < ui->tableWidget->rowCount(); i++)
//        {
//            for(int j = 0; j < ui->tableWidget->columnCount(); j++)
//            {

//            }
//        }
    }
//    else if(QVariant.toMap()["类型"].toString() == "预定工时法")
//    {
//          ui->tableWidget->setRowCount(10);
//          ui->tableWidget->setColumnCount(8);
//          list << "作业内容" << "预定工时法总代码" << "数量*频次" << "评比系数" << "基本时间" << "宽放率"
//               << "标准时间" << "增值/非增值" << "操作分类";

//          ui->tableWidget->setHorizontalHeaderLabels(list);

//    }
//    else if(QVariant.toMap()["类型"].toString() == "标准资料法")
//    {
//          list << "作业内容" << "公司内部代码" << "数量*频次" << "基本时间" << "宽放率"
//               << "标准时间";
//    }
}

void PwhManagement::on_button_detail_clicked()
{
//    dlg_.init_info (current_info_);

//    dlg_.exec ();
      detailedInfoTable_.show();

}

void PwhManagement::on_button_modify_clicked()
{
    ModifyProductDlg dlg;

    if(QDialog::Accepted == dlg.exec())
    {
        qDebug() << dlg.dump();
    }
//    modify_product_dlg dlg;
//    std::map<QString, QString> map_info
//    {
//        {
//            {"路径", current_path_},
//            {"工站号", ui->label_station->text ()},
//            {"测量人", ui->label_measure->text ()},
//            {"测量方法", ui->label_measurement->text ()},
//            {"测量日期", ui->label_date->text ()},
//            {"作业员", ui->label_operator->text ()}
//        }
//    };

//    dlg.set_info(map_info);
//    if (QDialog::Accepted == dlg.exec())
//    {
//        auto info = dlg.get_info();
//        auto path = dlg.get_path();
//        write_to_file (path, info);
//        refresh_data();
    //    }
}

void PwhManagement::on_button_addStdDatabase_clicked()
{
    AddtoStdDatabaseDlg dlg;

    if(QDialog::Accepted == dlg.exec())
    {
        dlg.dump();
    }
}

void PwhManagement::on_button_exportDF_clicked()
{
    const auto saveFileName = QFileDialog::getSaveFileName(nullptr, "生成PDF", "PwhContrast File", "*.pdf");
    if(saveFileName.isEmpty())
    {
        return;
    }

    QPrinter printerPixmap(QPrinter::HighResolution);
    printerPixmap.setPageSize(QPrinter::A4);  //设置纸张大小为A4
    printerPixmap.setOutputFormat(QPrinter::PdfFormat);  //设置输出格式为pdf
    printerPixmap.setOutputFileName(saveFileName);   //设置输出路径
    QPixmap pixmap = ui->reportWidget->grab();

    QPainter painterPixmap;
    painterPixmap.begin(&printerPixmap);
    QRect rect = painterPixmap.viewport();
    int multiple = rect.width()/pixmap.width();
    painterPixmap.scale(multiple, multiple); //将图像(所有要画的东西)在pdf上放大multiple-1倍
    painterPixmap.drawPixmap(0, 0, pixmap);  //画图
    painterPixmap.end();
}

void PwhManagement::on_button_reportHeader_clicked()
{
    const auto oldTitle = ui->reportWidget->reportHeader();
    QInputDialog dlg;
    dlg.setWindowTitle("表头设置");
    dlg.setLabelText("请输入表头数据:");
    dlg.setTextValue(oldTitle);


    if(QDialog::Accepted == dlg.exec())
    {
        if(dlg.textValue().isEmpty())
        {
            QMessageBox::information(this, "提示", "报表名称为空！");
            return;
        }

        ui->reportWidget->setReportHeader(dlg.textValue());
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

    auto data_json = krys::read_all (system_path);

    auto j_file = stdtime_data_veryfication(data_json->data ());

    if (j_file)
    {
        current_info_ = *j_file;
        if(video_update())
        {
            this->show_data (j_file.value (), path);
        }
    }
}

void PwhManagement::refresh_data()
{
    auto list = ui->tree_product->selectionModel ()->selectedIndexes ();
    assert (!list.isEmpty ());

    ui->tree_product->clearSelection ();
    clear_info ();
}

void PwhManagement::set_video_section(const QModelIndex &index)
{
    ui->widget_video_player->setEnabled (true);
    int index_row = index.row ();
    auto iter_sheet = current_info_.find ("表"); assert (iter_sheet != current_info_.end () and iter_sheet->is_object ());
    auto iter_detail = iter_sheet->find ("视频分析法详细信息"); assert (iter_detail != iter_sheet->end () and iter_detail->is_object ());

    auto iter_observation  = iter_detail->find ("观测时间"); assert (iter_observation != iter_detail->end () and iter_observation->is_array ());
    auto& observation_data = *iter_observation; assert (observation_data.is_array ());

    assert (circulation_ordinal_number_ > 0 and circulation_ordinal_number_ <= static_cast<int>(observation_data.size ()));
    auto& cir_data = observation_data [circulation_ordinal_number_ - 1]; assert (cir_data.is_array ());
    assert (index_row < static_cast<int>(cir_data.size ()));
    auto& source_tr = cir_data [index_row]; assert (source_tr.is_object ());
    auto iter_t = source_tr.find ("T"); assert (iter_t != source_tr.end () and iter_t->is_number ());
    double t = *iter_t;

    auto& invalid_vec = ui->widget_video_player->retrieve_invalid ();

    unsigned long long real_t,real_last_t;

    if (index_row == 0)
    {
        if (circulation_ordinal_number_ > 1)
        {
            auto& last_cir_data = observation_data [circulation_ordinal_number_ - 2];
            assert (last_cir_data.is_array ());
            auto& last_source_tr = last_cir_data [last_cir_data.size ()-1];
            assert (last_source_tr.is_object ());
            auto last_iter_t = last_source_tr.find ("T");
            assert (last_iter_t != last_source_tr.end () and last_iter_t->is_number ());
            double last_t = *last_iter_t;

            real_t = calculation_video_time (t*1000, invalid_vec);
            real_last_t = calculation_video_time (last_t*1000, invalid_vec);
        }
        else
        {
            real_last_t = 0;
            real_t = calculation_video_time (t*1000, invalid_vec);
        }
    }
    else
    {
        auto& last_source_tr = cir_data [index_row - 1];
        assert (last_source_tr.is_object ());
        auto last_iter_t = last_source_tr.find ("T");
        assert (last_iter_t != last_source_tr.end () and last_iter_t->is_number ());
        double last_t = *last_iter_t;

        real_t = calculation_video_time (t*1000, invalid_vec);
        real_last_t = calculation_video_time (last_t*1000, invalid_vec);
    }

    ui->widget_video_player->clear_section ();
    ui->widget_video_player->add_section (real_last_t, real_t);
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

void PwhManagement::write_to_file(const QString &path, const std::map<QString, QString> &info)
{
    auto current_path = current_path_.toStdString ();
    QFileInfo f_info {current_path_};

    auto file_name = f_info.fileName ().toStdString ();

    go [=] ()
    {
        QString response = "更改信息成功";
        BOOST_SCOPE_EXIT_ALL (&)
        {
            call_after [_response = std::move (response)]
            {
                QMessageBox::information (nullptr, "保存", _response);
            };
        };

        try
        {
            auto system_path_src = unicode_to_system (current_path);
            auto parent_dir = boost::filesystem::path {unicode_to_system (path.toStdString ())};
            parent_dir /= unicode_to_system (file_name);


            auto system_path_des = parent_dir.string ();

            auto json_from_file = krys::read_all (system_path_src);
            assert (json_from_file);

            auto json_obj = json::parse (*json_from_file);

            auto& json_attachment = json_obj["附加信息"];

            for (const auto& iter : info)
            {
                json_attachment[iter.first.toStdString ()] = iter.second.toStdString ();
            }

            auto is_ok = krys::write_buffer (system_path_src, json_obj.dump (4)); assert (is_ok); (void)is_ok;
            boost::filesystem::rename (system_path_src, system_path_des);

        }
        catch (std::exception& e)
        {
            qDebug () << e.what ();
            response = "保存失败,文件数据格式损坏";
            return;
        }
    };
}

bool PwhManagement::video_update()
{
    auto iter_extra = current_info_.find ("附加信息");
    assert (iter_extra != current_info_.end () and iter_extra->is_object ());
    auto iter_method = iter_extra->find ("测量方法");
    assert (iter_method != iter_extra->end () and iter_method->is_string ());
    std::string method = *iter_method;
    if (method == "视频分析法")
    {
        auto iter_sheet = current_info_.find ("表");
        assert (iter_sheet != current_info_.end () and iter_sheet->is_object ());
        auto iter_detail = iter_sheet->find ("视频分析法详细信息");
        assert (iter_detail != iter_sheet->end () and iter_detail->is_object ());
        auto iter_path = iter_detail->find ("视频路径");
        assert (iter_path != iter_detail->end () and iter_path->is_string ());
        std::string path = *iter_path;
        ui->widget_video_player->set_file (QString (path.data ()));
        ui->widget_video_player->open_section_function (true);

        auto iter_invalid_time = iter_detail->find ("无效时间段");
        assert (iter_invalid_time != iter_detail->end () and iter_invalid_time->is_array ());
        auto invalid_vec = make_invalid_time_container (*iter_invalid_time);
        ui->widget_video_player->set_invalid (invalid_vec);

        auto iter_circulation = iter_detail->find ("循环");
        assert (iter_circulation != iter_detail->end () and iter_circulation->is_number_integer ());
        circulation_ordinal_number_ = *iter_circulation;
    }
    else
    {
        ui->widget_video_player->open_section_function (false);
        ui->widget_video_player->setEnabled (false);
        circulation_ordinal_number_ = -1;
    }
    return true;
}

std::vector<unsigned long long> PwhManagement::make_invalid_time_container(const json &invalid_array)
{
    std::vector <unsigned long long> vec;
    assert (invalid_array.is_array ());

    for (size_t i = 0; i<invalid_array.size (); ++i)
    {
        unsigned long long sec = invalid_array [i];
        vec.push_back (sec);
    }

    return vec;
}
