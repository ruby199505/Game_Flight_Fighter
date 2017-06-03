#include "role.h"
#include "mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QString>

ROLE::ROLE(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(194,259);
    roleImg[0]=":/Image/role.png";
    roleImg[1]=":/Image/role.png";
    roleImg[2]=":/Image/role.png";
    roleTimer = new QTimer(this);

    connect(roleTimer, SIGNAL(timeout()), this, SLOT(update()));
    roleTimer->start(1000);
}

ROLE::~ROLE()
{

}

void ROLE::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

    if(i == 1){
        pix.load(roleImg[0]);
        painter.drawPixmap(0,0,194,259,pix);
        j=j+30;
        if(j>=200)
            i++;
    }
    else if(i == 2){
        pix.load(roleImg[1]);
        painter.drawPixmap(0,0,194,259,pix);
        i++;
    }
    else {
        pix.load(roleImg[2]);
        painter.drawPixmap(0,0,194,259,pix);
        i=1;
        j=1;
    }
}

