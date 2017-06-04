#include "mybullet.h"
#include "mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QString>

mybullet::mybullet(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(760,900);
    bulletImg=":/Image/bullet.png";
    bulletTimer = new QTimer(this);

    connect(bulletTimer, SIGNAL(timeout()), this, SLOT(update()));
    bulletTimer->start(1000);
}

mybullet::~mybullet() {}

void mybullet::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

    pix.load(bulletImg);
    painter.drawPixmap(0,0,13,13,pix);
}
