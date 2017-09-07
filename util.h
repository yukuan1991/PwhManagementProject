#ifndef UTIL_H
#define UTIL_H

#include <QString>
#include <QVariant>

struct ToolUtil
{
    int parentId; //父节点的ID
    int id; //自己的ID
    QString text; //名字
    QString tooltip; //提示信息
    QString toolicon; //图片

};

class Util
{

public:
    static QString exePath();
    static QList<ToolUtil> parse(QVariant data);
};

#endif // UTIL_H
