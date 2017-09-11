#include "PwhManagementMain.h"
#include <QApplication>
#include <boost/filesystem.hpp>
#include <boost/range/adaptors.hpp>
#include <base/io/file/file.hpp>
#include "interface_control/ModifyProductDlg.h"
#include "interface_control/DetailedInfoTable.h"
#include <QFile>
#include <QJsonDocument>

void setStyle ()
{
    using namespace boost::filesystem;

    auto rng = boost::make_iterator_range (directory_iterator ("."), directory_iterator ());

    std::string qss;
    for (auto & it : rng)
    {
        if (it.path ().extension ().string () == ".css")
        {
            auto res = file::read_all (it.path ().string ().data ());
            if (res)
            {
                qss += res.value ();
            }
        }
    }
    qApp->setStyleSheet (QString::fromStdString (qss));
    qApp->setFont (QFont ("宋体", 11));
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setStyle();

    PwhManagementMain w;
    w.show();

//    ModifyProductDlg dlg;
//    dlg.show();
    DetailedInfoTable d;
    QFile file("1.modaf");
    file.open(QIODevice::ReadOnly);
    const auto data = file.readAll();
    QJsonParseError error;
    auto document = QJsonDocument::fromJson(data, &error);
    if(error.error == QJsonParseError::NoError)
    {
        const auto formData = document.toVariant();
        d.load("预定工时法", formData);
    }

    d.show();

    return a.exec();
}
