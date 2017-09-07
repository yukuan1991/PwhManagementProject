#ifndef ADDTOSTDDATABASEDLG_H
#define ADDTOSTDDATABASEDLG_H

#include <QDialog>

namespace Ui {
class AddtoStdDatabaseDlg;
}

class AddtoStdDatabaseDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddtoStdDatabaseDlg(QWidget *parent = 0);
    ~AddtoStdDatabaseDlg();

private:
    Ui::AddtoStdDatabaseDlg *ui;
};

#endif // ADDTOSTDDATABASEDLG_H
