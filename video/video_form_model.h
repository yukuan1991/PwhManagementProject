﻿#ifndef VIDEO_MODEL_H
#define VIDEO_MODEL_H

#include <QAbstractTableModel>
#include "Qt-Utils/stl_extension.hpp"
#include <QStringList>
#include "model/json_model.h"

class video_form_model final: public json_model
{
    Q_OBJECT
public:
    constexpr static uint32_t max_rows = 10000;
    constexpr static uint32_t max_round = 10;
    constexpr static uint32_t data_col = max_round * 2;
    static const char * const cols[];
public:
    explicit video_form_model(QObject *parent = 0);
    QVariant get_header_info (const QModelIndex&, int) const;
    QString get_std_sum ();


    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData (const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags (const QModelIndex &index) const noexcept override;
    void resize (unsigned len) override;
    void clear ();
private:
    QVariant get_des_header (const QModelIndex&, int) const;
    QVariant get_data_header (const QModelIndex&, int) const;
    QVariant get_result_header (const QModelIndex&, int) const;

    QVariant get_average (int row) const;
    QVariant get_result_table (const QModelIndex& index) const;
    optional<double> get_increment_data (const QModelIndex& index) const;

    QVariant get_data_table (const QModelIndex& index) const;
    bool set_data_table (const QModelIndex& index, const QVariant& value);
    bool set_result_table (const QModelIndex& index, const QVariant& value);

    double get_last_total_time (int row, int col) const;
    QVariant get_std_time (const QModelIndex& index) const;
    QVariant get_base_time (const QModelIndex& index) const;
    QVariant get_result_info (const string& key, int row) const;
    QModelIndex get_result_index (const string& key, int row) const;
    double get_allowance (const QModelIndex& index) const;
    void resize_helper (int len);
    bool paste_data (const QModelIndex& index, const QVariant& value) override;

    bool paste_result_table (const QModelIndex& index, const QVariant& value);
    bool paste_data_table (const QModelIndex& index, const QVariant& value);

private:
    int row_count_ = max_rows;
    double stdtime_sum_ = 0;
};

#endif // VIDEO_MODEL_H
