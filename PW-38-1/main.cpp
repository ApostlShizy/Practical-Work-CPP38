#include <QApplication>
#include <QPushButton>
#include "soundbutton.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SoundButton w(nullptr);
    w.show();
    return a.exec();
}
