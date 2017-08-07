#include "analysis_detail_widget.h"
#include "ui_analysis_detail_widget.h"
#include "Qt-Utils/stl_extension.hpp"

analysis_detail_widget::analysis_detail_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::analysis_detail_widget)
{
    ui->setupUi(this);

    ui->table_std->setModel (stdtime_model_.get ());
    ui->table_std->setItemDelegate (stdtime_delegate_.get ());
}

analysis_detail_widget::~analysis_detail_widget()
{
    delete ui;
}

void analysis_detail_widget::set_editable(bool b)
{
    if (b == true)
    {
        ui->table_std->setEditTriggers (QAbstractItemView::AllEditTriggers);
    }
    else
    {
        ui->table_std->setEditTriggers (QAbstractItemView::NoEditTriggers);
    }
}

void analysis_detail_widget::load_detail(const json &detail)
{
    assert (stdtime_model_ != nullptr);

    stdtime_model_->load_json (detail);
    ui->table_std->setModel (nullptr);
    ui->table_std->setModel (stdtime_model_.get ());
}

