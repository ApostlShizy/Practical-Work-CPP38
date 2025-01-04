#include <QTimer>
#include "soundbutton.h"

SoundButton::SoundButton(QWidget * parent)
{
    setParent(parent);
    setFixedSize(300,300);    

    soundPlay.setAudioOutput(&soundOutput);
    soundPlay.setSource(QUrl("qrc:/sourceFiles/mp3/Voicy.mp3"));
    soundOutput.setVolume(1);

    setFocusPolicy(Qt::StrongFocus);

    buttonDown = QPixmap(":/sourceFiles/png/SetDown.png");
    buttonUp = QPixmap(":/sourceFiles/png/SETUP.png");
    buttonCurrent = buttonUp;

    setGeometry(buttonCurrent.rect());

    QObject::connect(this,&QPushButton::clicked,this,&SoundButton::setDown);
}

// void SoundButton::keyPressEvent(QKeyEvent * e)
// {
//     setDown();
// }

void SoundButton:: setDown()
{
    buttonCurrent = buttonDown;
    soundPlay.play();
    update();
    QTimer::singleShot(100,this,&SoundButton::setUp);
}

void SoundButton::setUp()
{
    buttonCurrent = buttonUp;
    update();
}

void SoundButton::paintEvent(QPaintEvent * e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(),buttonCurrent);
}
