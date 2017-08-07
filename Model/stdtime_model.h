#ifndef STDTIME_MODEL_H
#define STDTIME_MODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include "Qt-Utils/json.hpp"
#include "model/json_model.h"
using json = nlohmann::json;

class stdtime_model : public json_model
{
    Q_OBJECT

public:
    explicit stdtime_model(QObject *parent = 0);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData (const QModelIndex& index, const QVariant& value, int role) override;
    void resize (unsigned size) override;
    void clear ();
    void erase_row (unsigned row);
    QString get_std_sum ();


private:
    bool change_company_code (const QModelIndex& index, const QVariant& value);
    bool set_allowance (const QModelIndex& index, const QVariant& value, int role);
    bool paste_allowance (const QModelIndex& index, const QVariant& value);
    bool set_rate (const QModelIndex& index, const QVariant& value, int role);
    bool paste_rate (const QModelIndex& index, const QVariant& value);
    QVariant get_std_time (const QModelIndex& index, int role) const;
    QVariant get_allowance (const QModelIndex& index, int role) const;
    bool set_op_type (const QModelIndex& index, const QVariant& value, int role);
    void resize_helper (unsigned size);
    QVariant get_base_time (const QModelIndex& index, int role) const;


    QVariant increamental_info (const QModelIndex& index) const;
    bool paste_data (const QModelIndex& index, const QVariant& value) override;
private:
    //std::map<QString, stdtime_model::*
};

#endif // STDTIME_MODEL_H
