#include "global_widget.h"
#include "ui_global_widget.h"


global_widget::global_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::global_widget)
{
    ui->setupUi(this);
}

global_widget::~global_widget()
{
    delete ui;
}

void global_widget::update_table_data (const json &data)
{
    //video_path_ = extract_video_path (data);

    product_info_model_->clear ();
    product_info_model_->load_json (data);
}

void global_widget::refresh_table()
{
    ui->table_global->setModel (nullptr);
    ui->table_global->setModel (product_info_model_.get ());
}

void global_widget::hide_table_column(int column)
{
    ui->table_global->hideColumn (column);
}

bool global_widget::hide_table_column(const QString &header)
{
    auto column = product_info_model_->get_col_from_name (header);
    if (column < 0)
    {
        return false;
    }
    else
    {
        ui->table_global->hideColumn (column);
        return true;
    }
}

QAbstractItemModel *global_widget::model()
{
    return ui->table_global->model();
}

void global_widget::set_model(QAbstractItemModel *model)
{
    ui->table_global->setModel(model);
}

QModelIndex global_widget::current_index()
{
    return ui->table_global->currentIndex();
}

int global_widget::row_count()
{
    auto model = ui->table_global->model ();
    return model->rowCount ();
}

void global_widget::on_table_global_clicked(const QModelIndex &index)
{
    if (product_info_model_->get_header (index))
    {
        emit table_clicked (index);
    }
}
