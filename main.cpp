#include <QtGui/QApplication>
#include "spellcheckerwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpellCheckerWindow w;
    w.show();

    return a.exec();
}
