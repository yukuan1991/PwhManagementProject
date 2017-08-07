#ifndef ANALYSIS_DETAIL_WIDGET_H
#define ANALYSIS_DETAIL_WIDGET_H

#include <QWidget>
#include "Model/stdtime_model.h"
#include "delegate/stdtime_delegate.h"
#include <memory>
#include "Qt-Utils/json.hpp"

using json = nlohmann::json;

namespace Ui {
class analysis_detail_widget;
}

class analysis_detail_widget : public QWidget
{
    Q_OBJECT

public:
    explicit analysis_detail_widget(QWidget *parent = 0);
    ~analysis_detail_widget();

    void set_editable (bool b);
    void load_detail (const json& detail);

private:
    Ui::analysis_detail_widget *ui;
    std::unique_ptr<stdtime_model> stdtime_model_ {new stdtime_model};
    std::unique_ptr<stdtime_delegate> stdtime_delegate_ {new stdtime_delegate};
};

#endif // ANALYSIS_DETAIL_WIDGET_H
