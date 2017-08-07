#ifndef DETAIL_DLG_H
#define DETAIL_DLG_H

#include <QDialog>
#include "interface_control/data_widget.h"
#include "interface_control/form_widget.h"
#include "interface_control/analysis_detail_widget.h"
#include "Qt-Utils/stl_extension.hpp"
#include "Qt-Utils/json.hpp"

using json = nlohmann::json;

namespace Ui {
class detail_dlg;
}

class detail_dlg : public QDialog
{
    Q_OBJECT

public:
    explicit detail_dlg(QWidget *parent = 0);
    ~detail_dlg();

    void init_info (const json& info);

    void init_pts_window ();
    void init_video_window ();
    void init_stddata_window ();
    void init_tmu ();

    //>>>>>>>>
    //void set_circulation_ordinal_number (int num);

    //>>>>>>>>>
//signals:
//    void video_play_section_changed (long long int start, long long int end);

private:
    void add_pts_window ();
    void add_video_window ();
    void add_stddata_window ();
    int search_widget (const std::string& name);

    const auto& get_tmu ()
    {
        return kv_tmu_;
    }

private:
    Ui::detail_dlg *ui;
    data_widget* pts_view_ = nullptr;
    form_widget* video_view_ = nullptr;
    analysis_detail_widget* stddata_view_ = nullptr;
    std::map <std::string, int> kv_tmu_;
    json current_info_;

    //>>>>>>>>>>>
    //int circulation_ordinal_number_ = -1;
};

#endif // DETAIL_DLG_H
