#include "modified_spider.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    modified_spider w;
    w.show();

    return a.exec();
}
