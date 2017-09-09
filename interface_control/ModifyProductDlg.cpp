#include "ModifyProductDlg.h"
#include "ui_modifyproductdlg.h"
#include <QDebug>

ModifyProductDlg::ModifyProductDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyProductDlg)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());

    connect(ui->button_confirm, &QPushButton::clicked, this, &ModifyProductDlg::accept);

    connect(ui->button_cancel, &QPushButton::clicked, this, &ModifyProductDlg::reject);
}

ModifyProductDlg::~ModifyProductDlg()
{
    delete ui;
}

void ModifyProductDlg::load(const QVariant &data)
{
    if(data.isNull())
    {
        return;
    }

    const auto station = data.toMap()["工站号"].toString();
    const auto taskMan = data.toMap()["作业员"].toString();
    const auto measureDate = data.toMap()["测量日期"].toString();
    const auto measureMan = data.toMap()["测量人"].toString();
    const auto dataUnit = data.toMap()["数据单位"].toString();

    ui->editStation->setText(station);
    ui->editTaskMan->setText(taskMan);
    ui->dateEdit->setDate(QDate::fromString(measureDate, Qt::ISODate));
    ui->editMeasureMan->setText(measureMan);
    ui->comboBox->setCurrentText(dataUnit);

}

QVariant ModifyProductDlg::dump()
{
    qDebug() << "dump";
    currentInfo_.clear();

    currentInfo_["工站号"] = ui->editStation->text();
    currentInfo_["作业员"] = ui->editTaskMan->text();
    currentInfo_["测量日期"] = ui->dateEdit->date().toString(Qt::ISODate);
    currentInfo_["测量人"] = ui->editMeasureMan->text();
    currentInfo_["数据单位"] = ui->comboBox->currentText();

    qDebug() << currentInfo_;

    return currentInfo_;
}

