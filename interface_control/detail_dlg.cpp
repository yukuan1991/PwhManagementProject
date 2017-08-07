#include "detail_dlg.h"
#include "ui_detail_dlg.h"
#include "arithmetic_resource.hpp"

detail_dlg::detail_dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detail_dlg)
{
    ui->setupUi(this);

    init_tmu ();

    add_pts_window ();
    add_video_window ();
    add_stddata_window ();

}

detail_dlg::~detail_dlg()
{
    delete ui;
}

void detail_dlg::init_info(const json &info)
{
    current_info_ = info;
    auto extra_info = current_info_.find ("附加信息");
    assert (extra_info != current_info_.end ());
    assert (extra_info->is_object ());

    auto measure_method = extra_info->find ("测量方法");
    assert (measure_method != extra_info->end ());
    assert (measure_method->is_string ());
    std::string method = (*measure_method);

    if (method == "预定工时法")
    {
        init_pts_window ();
        auto index = search_widget ("data_widget");
        assert (index >= 0);
        ui->info_pages->setCurrentIndex (index);
    }
    else if (method == "视频分析法")
    {
        init_video_window ();
        auto index = search_widget ("form_widget");
        assert (index >= 0);
        ui->info_pages->setCurrentIndex (index);
    }
    else if (method == "标准资料法")
    {
        init_stddata_window ();
        auto index = search_widget ("analysis_detail_widget");
        assert (index >= 0);
        ui->info_pages->setCurrentIndex (index);
    }
}

void detail_dlg::add_pts_window()
{
    ui->info_pages->addWidget (new data_widget);
    int index = search_widget ("data_widget");
    pts_view_ = dynamic_cast <data_widget*> (ui->info_pages->widget(index)); assert (pts_view_);
    pts_view_->set_no_editable ();
}

void detail_dlg::add_video_window()
{
    ui->info_pages->addWidget (new form_widget);
    int index = search_widget ("form_widget");
    video_view_ = dynamic_cast <form_widget*> (ui->info_pages->widget(index)); assert (video_view_);
    video_view_->set_editable (false);
}

void detail_dlg::add_stddata_window()
{
    ui->info_pages->addWidget (new analysis_detail_widget);
    int index = search_widget ("analysis_detail_widget");
    stddata_view_ = dynamic_cast <analysis_detail_widget*> (ui->info_pages->widget(index)); assert (stddata_view_);
    stddata_view_->set_editable (false);
}

int detail_dlg::search_widget(const std::string &name)
{
    for (int i=0; ui->info_pages->widget (i); ++i)
    {
        if (name == ui->info_pages->widget (i)->metaObject ()->className ())
        {
            return i;
        }
    }
    return -1;
}

void detail_dlg::init_pts_window()
{
    assert (pts_view_);

    auto iter_sheet = current_info_.find ("表");
    assert (iter_sheet != current_info_.end());
    assert (iter_sheet->is_object ());
    const json& sheet = *iter_sheet;
    auto iter_pts = sheet.find ("预定工时法详细信息");
    assert (iter_pts != sheet.end());
    assert (iter_pts->is_object ());
    const json&pts = *iter_pts;

    auto iter_method = pts.find ("方法");
    assert (iter_method != pts.end());
    assert (iter_method->is_string ());
    std::string method = *iter_method;
    pts_view_->set_unit (method == "MOD" ? 0.129 : 0.036);

    auto iter_left = pts.find ("左手");
    assert (iter_left != pts.end());
    assert (iter_left->is_array ());
    pts_view_->load_left(*iter_left);
    pts_view_->set_row (iter_left->size ());

    auto iter_right = pts.find ("右手");
    assert (iter_right != pts.end());
    assert (iter_right->is_array ());
    pts_view_->load_right(*iter_right);

    auto iter_result = pts.find ("总计");
    assert (iter_result != pts.end());
    assert (iter_result->is_array ());
    pts_view_->load_result(*iter_result);
}

void detail_dlg::init_video_window()
{
    assert (video_view_);
    auto iter_sheet = current_info_.find ("表");
    assert (iter_sheet != current_info_.end());
    assert (iter_sheet->is_object ());
    const json& sheet = *iter_sheet;
    auto iter_video = sheet.find ("视频分析法详细信息");
    assert (iter_video != sheet.end());
    assert (iter_video->is_object ());
    const json&video = *iter_video;

    auto iter_task = video.find ("作业内容");
    assert (iter_task != video.end () and iter_task->is_array ());
    video_view_->load_task (*iter_task);
    video_view_->set_row (iter_task->size ());

    auto iter_data = video.find ("观测时间");
    assert (iter_data != video.end () and iter_data->is_array ());
    video_view_->load_data (*iter_data);

    auto iter_result = video.find ("结果");
    assert (iter_result != video.end () and iter_result->is_array ());
    video_view_->load_result (*iter_result);
}

void detail_dlg::init_stddata_window()
{
    auto iter_sheet = current_info_.find ("表");
    assert (iter_sheet != current_info_.end()); assert (iter_sheet->is_object ());
    const json& sheet = *iter_sheet;
    auto iter_stddetail = sheet.find ("标准资料法详细信息");
    assert (iter_stddetail != sheet.end ());
    assert (iter_stddetail->is_object ());

    auto iter_detail = iter_stddetail->find ("详细信息");
    assert (iter_detail != iter_stddetail->end ());
    assert (iter_detail->is_array ());
    assert (stddata_view_ != nullptr);
    stddata_view_->load_detail (*iter_detail);
}

void detail_dlg::init_tmu()
{
    std::tie (kv_tmu_, std::ignore, std::ignore, std::ignore) = read_tmu_data ();
}

