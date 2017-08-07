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
private slots:
    void on_tree_product_clicked(const QModelIndex& index);
    void on_button_detail_clicked();
private:
    void show_data (const json& data, const QString& path);
    void data_extraction (const QString&);

    void show_attachment (const json& data);
    static void set_label_for_data (const json& data, const char* name, QLabel* label);

    void refresh_global_info (const json& global_data, const QString& method);
    void clear_info();

    bool video_update ();
private:
    std::unique_ptr<product_structure_model> fs_model_ { new product_structure_model };

    const std::shared_ptr<bool> alive_ = std::make_shared<bool> (true);
    QString current_path_;
    json current_info_;
    QString current_file_name_;
    QString current_method_;
    detail_dlg dlg_;
private:
    Ui::PwhManagement *ui;
};

#endif // PWHMANAGEMENT_H
