#ifndef FORM_WIDGET_H
#define FORM_WIDGET_H

#include <QWidget>
#include "video/video_delegate.h"
#include <QTableView>
#include "Qt-Utils/stl_extension.hpp"
#include "view/table_view.h"
#include <memory>
#include <QTableWidgetItem>
#include <vector>
#include "video/video_form_split.h"
#include <memory>
#include "Qt-Utils/json.hpp"
#include <QModelIndex>

using json = nlohmann::json;

namespace Ui {
class form_widget;
}

class form_widget : public QWidget
{
    Q_OBJECT
public:
    static constexpr int max_row = 12;
public:
    explicit form_widget(QWidget *parent = 0);
    ~form_widget();
    void mark (long long time_val);
    int row ();
    void set_row (int num);
    void add_row (int num);
    void reduce_row (int num);
    bool task_content_check ();
    void scroll_to_index (const QModelIndex& index);

    void on_paste ();
    void on_copy ();
    void on_cut ();
    void on_del ();

    void load_task (const json& task);
    void load_data (const json& data);
    void load_result (const json& result);
    void set_editable (bool b);

private:
    void set_views ();
    void set_des_view ();
    void set_data_view ();
    void set_result_view ();
    optional<QModelIndex> get_next_index (const QModelIndex&) const;

    void set_models ();
    void set_des_model ();
    void set_data_model ();
    void set_result_model ();
    void table_clicked (const QModelIndex&);
    json task_data ();
    json observation_time ();
    json result_data ();
    json map_to_json (const std::map <QString,QString>& map);
    json info_pandect (const json& json_data, const std::string& video_path);
    void save_task (const QString& filename, const std::map <QString,QString>& info,const json &data);
    void set_scrolls ();

public:
    json export_data ();
    void save_file (const std::map <QString, QString>& dlg_info, std::vector <unsigned long long >& invalid_vec);
    void clear ();

signals:
    void line_exists (bool yes_or_no);
    void bar_move (int value);
    void total_time_changed (const QString& sum);

private:
    Ui::form_widget *ui;
    int total_round_ = 10;
    unique_ptr<video_form_model> src_model_ = make_unique<video_form_model> ();
    unique_ptr<video_form_split> model_des_ = make_unique<video_form_split> ();
    unique_ptr<video_form_split> model_data_ = make_unique<video_form_split> ();
    unique_ptr<video_form_split> model_result_ = make_unique<video_form_split> ();
    unique_ptr<video_delegate> des_delegate_ = make_unique<video_delegate> ();

    std::vector<QTableView*> views_;
    table_view* current_view_ = nullptr;
};

#endif // FORM_WIDGET_H
