#ifndef SOUNDBUTTON_H
#define SOUNDBUTTON_H

#include <QPushButton>
#include <QMediaPlayer>
#include <QAudioOutput>

#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QKeyEvent>

class SoundButton : public QPushButton
{
    Q_OBJECT
public:
    // void keyPressEvent(QKeyEvent * e) override;
    SoundButton(QWidget * parent = nullptr);
    void paintEvent(QPaintEvent * e) override;
public slots:
    void setUp();
    void setDown();
private:
    QPixmap buttonUp;
    QPixmap buttonDown;
    QPixmap buttonCurrent;
    QMediaPlayer soundPlay;
    QAudioOutput soundOutput;
};

#endif // SOUNDBUTTON_H
