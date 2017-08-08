#ifndef MODIFY_PRODUCT_DLG_H
#define MODIFY_PRODUCT_DLG_H

#include <QString>
#include <QDialog>
#include <memory>
#include "model/product_structure_model.h"
#include <map>

namespace Ui {
class modify_product_dlg;
}

class modify_product_dlg : public QDialog
{
    Q_OBJECT

public:
    explicit modify_product_dlg(QWidget *parent = 0);
    ~modify_product_dlg();
    void set_product_path (const QString& path);
    void set_info (const std::map<QString, QString>& info);
    const std::map<QString, QString>& get_info ();
    QString get_path ();

private slots:
    void on_combo_product_currentIndexChanged(int index);

    void on_button_ok_clicked();

    void on_button_add_capp_clicked();

    void on_button_add_product_clicked();

private:
    void combo_index_changed (const QString& text);
    void update_info ();
    void set_combo_on_loaded (const QString& product, const QString& capp);
    bool ask_override (const QString&, const QString&, const QString&);

private:
    Ui::modify_product_dlg *ui;
    std::unique_ptr<product_structure_model> product_model_ = std::make_unique<product_structure_model> ();
    std::unique_ptr<product_structure_model> capp_model_ = std::make_unique<product_structure_model> ();
    std::map<QString, QString> current_info_;
    std::shared_ptr<bool> alive_ = std::make_shared<bool> (true);

    QString path_;
    QString current_product_;
    QString current_capp_;
};

#endif // MODIFY_PRODUCT_DLG_H
