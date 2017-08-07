#ifndef GLOBAL_WIDGET_H
#define GLOBAL_WIDGET_H

#include <QWidget>
#include "model/product_info_model.h"
#include <QAbstractItemModel>
#include <QTableView>

namespace Ui {
class global_widget;
}

class global_widget : public QWidget
{
    Q_OBJECT

public:
    explicit global_widget(QWidget *parent = 0);
    ~global_widget();

    void update_table_data (const json& data);
    void refresh_table ();
    void hide_table_column (int column);
    bool hide_table_column (const QString& header);
    QAbstractItemModel* model ();
    void set_model (QAbstractItemModel* model);
    QModelIndex current_index ();
    int row_count ();

private slots:
    void on_table_global_clicked(const QModelIndex &index);

signals:
    void table_clicked (const QModelIndex& index);

private:
    Ui::global_widget *ui;
    std::unique_ptr<product_info_model> product_info_model_ {new product_info_model};
};

#endif // GLOBAL_WIDGET_H
