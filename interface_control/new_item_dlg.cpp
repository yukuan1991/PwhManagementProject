#include "new_item_dlg.h"
#include "ui_new_file.h"

new_item_dlg::new_item_dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_file)
{
    ui->setupUi(this);

    connect (ui->new_filename,&QLineEdit::textChanged,[=]{
        auto content = ui->new_filename->text ();
        if (content.isEmpty())
        {
            ui->confirm->setEnabled (false);
        }
        else
        {
            ui->confirm->setEnabled (true);
        }
    });
}

new_item_dlg::~new_item_dlg()
{
    delete ui;
}

QString new_item_dlg::content()
{
    return ui->new_filename->text ();
}

void new_item_dlg::set_label(const QString& qstr)
{
    ui->label->setText (qstr);
}
