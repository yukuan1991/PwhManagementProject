#ifndef NEW_ITEM_DLG_H
#define NEW_ITEM_DLG_H

#include <QDialog>

namespace Ui {
class new_file;
}

class new_item_dlg : public QDialog
{
    Q_OBJECT

public:
    explicit new_item_dlg(QWidget *parent = 0);
    ~new_item_dlg();

    QString content ();
    void set_label (const QString& qstr);

private:
    Ui::new_file *ui;
};

#endif // NEW_FILE_H
