#ifndef PWHMANAGEMENT_H
#define PWHMANAGEMENT_H

#include <QWidget>
#include <memory>
#include "Model/product_structure_model.h"
#include "Qt-Utils/json.hpp"
#include "interface_control/detail_dlg.h"

namespace Ui {
class PwhManagement;
}

class QLabel;
using nlohmann::json;

class PwhManagement : public QWidget
{
    Q_OBJECT

public:
    explicit PwhManagement(QWidget *parent = 0);
    ~PwhManagement();
public:
    void on_button_detail_clicked();
    void on_button_modify_clicked();
    void on_button_addStdDatabase_clicked();
private slots:
    void on_tree_product_clicked(const QModelIndex& index);
    void onTreeProductClicked(const QVariant&);
private:
    void data_extraction (const QString&);
    bool video_update ();
    std::vector <unsigned long long>  make_invalid_time_container (const json& invalid_array);
    void show_data (const json& data, const QString& path);
    void show_attachment (const json& data);
    static void set_label_for_data (const json& data, const char* name, QLabel* label);
    void refresh_global_info (const json& global_data, const QString& method);

    void clear_info();

    void write_to_file (const QString& path, const std::map<QString, QString>&);
    void refresh_data();

    void set_video_section (const QModelIndex& index);

private:
    std::unique_ptr<product_structure_model> fs_model_ { new product_structure_model };

    const std::shared_ptr<bool> alive_ = std::make_shared<bool> (true);
    QString current_path_;
    json current_info_;
    QString current_file_name_;
    QString current_method_;
    detail_dlg dlg_;
    int circulation_ordinal_number_ = -1;
private:
    Ui::PwhManagement *ui;
};

#endif // PWHMANAGEMENT_H
