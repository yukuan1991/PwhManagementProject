#include "modify_product_dlg.h"
#include "ui_modify_product_dlg.h"
//#include "global_app_info.h"
#include "interface_control/new_item_dlg.h"
#include <QMessageBox>
#include <QFile>
#include "Qt-Utils/stl_extension.hpp"
#include "Qt-Utils/qt.hpp"
#include <boost/filesystem.hpp>
#include <boost/scope_exit.hpp>
#include "Qt-Utils/json.hpp"
#include <QDebug>
#include "Qt-Utils/krys_application.hpp"
#include <QDir>
#include <QFileInfo>
#include <QPalette>
#include <QDebug>
using json = nlohmann::json;

modify_product_dlg::modify_product_dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modify_product_dlg)
{
    ui->setupUi(this);
    connect (ui->combo_product, &QComboBox::currentTextChanged, this, &modify_product_dlg::combo_index_changed);
    connect (ui->combo_capp, &QComboBox::currentTextChanged, this, &modify_product_dlg::combo_index_changed);
    ui->date_edit->setDate(QDate::currentDate());
}

modify_product_dlg::~modify_product_dlg()
{
    delete ui;
}

void modify_product_dlg::set_product_path(const QString &path)
{
    path_ = std::move (path);
    QFileInfo file_product {path_};
    auto capp_dir = file_product.dir ();
    current_capp_ = capp_dir.dirName ();

    auto product_dir = capp_dir;
    bool is_ok;
    is_ok = product_dir.cdUp (); assert (is_ok);
    current_product_ = product_dir.dirName ();

    auto master_dir = product_dir;
    is_ok = master_dir.cdUp (); assert (is_ok);

    auto master_gbk = unicode_to_system (master_dir.absolutePath ().toStdString ());
    auto product_gbk = unicode_to_system (PRODUCT_PATH);

    assert (boost::filesystem::equivalent (master_gbk, product_gbk));

    capp_model_->setRootPath (product_dir.path ());
    ui->combo_capp->setModel (capp_model_.get ());
    capp_model_->setFilter (QDir::AllDirs | QDir::NoDotAndDotDot);
    ui->combo_capp->setRootModelIndex (capp_model_->index (product_dir.path ()));

    product_model_->setRootPath (master_dir.path ());
    ui->combo_product->setModel (product_model_.get ());
    product_model_->setFilter (QDir::AllDirs | QDir::NoDotAndDotDot);
    ui->combo_product->setRootModelIndex (product_model_->index (master_dir.path ()));

    set_combo_on_loaded (product_dir.dirName (), capp_dir.dirName ());
}

void modify_product_dlg::set_info(const std::map<QString, QString> &info)
{
    const auto iter_path = info.find ("路径");
    assert (iter_path != info.end ());
    set_product_path (iter_path->second);

    const auto iter_station = info.find ("工站号");
    assert (iter_station != info.end ());
    ui->edit_station->setText (iter_station->second);

    const auto iter_measure = info.find ("测量人");
    assert (iter_measure != info.end ());
    ui->edit_mesure->setText (iter_measure->second);

    const auto iter_measurement = info.find ("测量方法");
    ui->edit_measurement->setText (iter_measurement->second);

    const auto iter_operator = info.find ("作业员");
    assert (iter_operator != info.end ());
    ui->edit_operator->setText (iter_operator->second);

    const auto iter_date = info.find ("测量日期");
    assert (iter_date != info.end ());
    ui->date_edit->setDate (QDate::fromString (iter_date->second, Qt::ISODate));
}

const std::map<QString, QString>& modify_product_dlg::get_info()
{
    update_info ();
    return current_info_;
}

void modify_product_dlg::update_info()
{
    current_info_.clear ();

    current_info_["作业员"] = ui->edit_operator->text ();
    current_info_["测量人"] = ui->edit_mesure->text ();
    current_info_["工站号"] = ui->edit_station->text ();
    current_info_["数据单位"] = ui->combo_unit->currentText ();
    current_info_["测量日期"] = ui->date_edit->date ().toString (Qt::ISODate);
}

QString modify_product_dlg::get_path()
{
    auto product = ui->combo_product->currentText ();
    auto capp = ui->combo_capp->currentText ();
    QDir master_dir {PRODUCT_PATH};
    auto list_product = master_dir.entryInfoList ();

    for (const auto& iter : list_product)
    {
        if (iter.fileName () == product)
        {
            QDir product_dir {iter.filePath ()};
            auto list_capp = product_dir.entryInfoList ();
            for (const auto& iter_ : list_capp)
            {
                if (iter_.fileName () == capp)
                {
                    assert (iter_.isDir ());
                    return iter_.filePath ();
                }
            }
            assert (false);
        }
    }
    assert (false);
    return {};
}

void modify_product_dlg::set_combo_on_loaded(const QString &product, const QString &capp)
{
    auto conn = std::make_shared<QMetaObject::Connection> ();
    *conn = connect (product_model_.get (), &product_structure_model::directoryLoaded, [=] (const QString&)
    {
        for (int i = 0; i < ui->combo_product->count (); i++)
        {
            if (ui->combo_product->itemText (i) == product)
            {
                ui->combo_product->setCurrentIndex (i);
                return;
            }
        }
    });

    conn = std::make_shared<QMetaObject::Connection> ();
    *conn = connect (capp_model_.get (), &product_structure_model::directoryLoaded, [=] (const QString& )
    {
        for (int i = 0; i < ui->combo_capp->count (); i++)
        {
            if (ui->combo_capp->itemText (i) == capp)
            {
                ui->combo_capp->setCurrentIndex (i);
                return;
            }
        }
    });
}

bool modify_product_dlg::ask_override(const QString& product, const QString& capp, const QString& file)
{
    auto sys_old_path = boost::filesystem::path {unicode_to_system (path_.toStdString ())};

    auto sys_master = unicode_to_system (PRODUCT_PATH);
    auto sys_product = unicode_to_system (product.toStdString ());
    auto sys_capp = unicode_to_system (capp.toStdString ());
    auto sys_file = unicode_to_system (file.toStdString ());
    auto sys_new_path = boost::filesystem::path {sys_master};
    sys_new_path = sys_new_path / sys_product / sys_capp / sys_file;

    return boost::filesystem::exists (sys_new_path) and !boost::filesystem::equivalent (sys_new_path, sys_old_path);
}

void modify_product_dlg::on_combo_product_currentIndexChanged(int)
{
    auto var = ui->combo_product->currentData (QFileSystemModel::FilePathRole);
    auto path = var.toString ();

    this->capp_model_->setRootPath (path);
    ui->combo_capp->setRootModelIndex (capp_model_->index (path));
    ui->combo_capp->setCurrentIndex (0);
}

void modify_product_dlg::combo_index_changed(const QString &)
{
    auto obj_sender = sender (); assert (obj_sender);
    auto combo_sender = dynamic_cast<QComboBox*>(obj_sender); assert (combo_sender); (void)combo_sender;

    if (ui->combo_capp->currentText ().isEmpty () or ui->combo_product->currentText ().isEmpty ())
    {
        ui->button_ok->setEnabled (false);
        return;
    }

    ui->button_ok->setEnabled (true);
}

void modify_product_dlg::on_button_ok_clicked()
{
    auto product = ui->combo_product->currentText ();
    auto capp = ui->combo_capp->currentText ();
    assert (!path_.isEmpty ());
    QFileInfo info {path_};
    auto file_name = info.fileName ();

    if (ask_override (product, capp, file_name))
    {
        auto ret = QMessageBox::question (this, "覆盖", "新的工艺下有相同名称的内容,是否覆盖");
        if (ret == QMessageBox::Yes)
        {
            accept ();
        }
    }
    else
    {
        accept ();
    }
}

void modify_product_dlg::on_button_add_capp_clicked()
{
    new_item_dlg dlg;
    dlg.setWindowTitle ("新建工艺");
    dlg.set_label ("工艺名称");
    auto ret = dlg.exec();
    if (ret == QDialog::Accepted)
    {
        auto capp_name = dlg.content ();
        QDir dir {PRODUCT_PATH};
        bool is_ok;
        is_ok = dir.cd(ui->combo_product->currentText()); assert (is_ok);
        dir.mkdir(capp_name);
    }
}

void modify_product_dlg::on_button_add_product_clicked()
{
    new_item_dlg dlg;
    dlg.setWindowTitle ("新建产品");
    dlg.set_label ("产品名称");
    auto ret = dlg.exec();
    if (ret == QDialog::Accepted)
    {
        auto product_name = dlg.content ();
        QDir dir {PRODUCT_PATH};
        dir.mkdir(product_name);
    }
}
