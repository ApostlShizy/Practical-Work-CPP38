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

    setMinimumSize(500,300);

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
        currentPic = QPixmap(picPath);

        y = ui->displayPic->height();
        x = ui->displayPic->width();

        ui->displayPic->setPixmap(currentPic.scaled(x,y,Qt::KeepAspectRatio));
        ui->displayPic->setMinimumSize(x,y);
        setMinimumSize(x,y+100);
    }
}

void BlurMaker::addBlur(int value)
{
    if(!picPath.isEmpty())
    {
        QImage bluredPic(picPath);
        QGraphicsScene scene;
        QGraphicsPixmapItem item;
        item.setPixmap(QPixmap::fromImage(bluredPic));
        auto blur = new QGraphicsBlurEffect;
        blur->setBlurRadius(value);
        item.setGraphicsEffect(blur);
        scene.addItem(&item);
        QImage result(bluredPic.size(),QImage::Format_ARGB32);
        result.fill(Qt::transparent);
        QPainter painter(&result);
        scene.render(&painter,QRectF(),QRectF(0,0,bluredPic.width(),bluredPic.height()));
        ui->displayPic->setPixmap(QPixmap::fromImage(result).scaled(x,y,Qt::KeepAspectRatio));
    }
}
