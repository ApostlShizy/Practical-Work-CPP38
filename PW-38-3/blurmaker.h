#ifndef BLURMAKER_H
#define BLURMAKER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class BlurMaker;
}
QT_END_NAMESPACE

class QPixmap;

class BlurMaker : public QMainWindow
{
    Q_OBJECT

public slots:
    void openFileFun();
    void addBlur(int value);
public:
    BlurMaker(QWidget *parent = nullptr);
private:
    QPixmap currentPick;
    QString picPath = "";
    int x = 600;
    int y = 300;
    Ui::BlurMaker *ui;
};
#endif // BLURMAKER_H
