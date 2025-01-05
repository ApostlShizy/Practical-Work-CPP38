#include "blurmaker.h"
#include "ui_blurmaker.h"

#include <QPixmap>
#include <QFileDialog>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPainter>

BlurMaker::BlurMaker(QWidget *parent) : QMainWindow(parent), ui(new Ui::BlurMaker)
{
    ui->setupUi(this);

    ui->blurSlider->setMinimum(0);
    ui->blurSlider->setMaximum(100);

    connect(ui->openFileButton,&QPushButton::clicked,this,&BlurMaker::openFileFun);
    connect(ui->blurSlider,&QSlider::valueChanged,this,&BlurMaker::addBlur);
}

void BlurMaker::openFileFun()
{
    auto tempPath = QFileDialog::getOpenFileName(
        nullptr,
        "Open pick",
        "C:/",
        "pick files (*.jpg , *.png)");

    if(!tempPath.isEmpty())
    {
        picPath = tempPath;
        currentPick = QPixmap(picPath);
        y = ui->displayPick->height();
        x = ui->displayPick->width();
        ui->displayPick->setPixmap(currentPick.scaled(x,y,Qt::KeepAspectRatio));
    }
}

void BlurMaker::addBlur(int value)
{
    if(!picPath.isEmpty())
    {
        QImage bluredPick(picPath);
        QGraphicsScene scene;
        QGraphicsPixmapItem item;
        item.setPixmap(QPixmap::fromImage(bluredPick));
        auto blur = new QGraphicsBlurEffect;
        blur->setBlurRadius(value);
        item.setGraphicsEffect(blur);
        scene.addItem(&item);
        QImage result(bluredPick.size(),QImage::Format_ARGB32);
        result.fill(Qt::transparent);
        QPainter painter(&result);
        scene.render(&painter,QRectF(),QRectF(0,0,bluredPick.width(),bluredPick.height()));
        ui->displayPick->setPixmap(QPixmap::fromImage(result).scaled(x,y,Qt::KeepAspectRatio));
    }
}
