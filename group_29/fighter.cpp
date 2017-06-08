#include "fighter.h"
#include <QPainter>
#include <QPixmap>

fighter::fighter(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(230,210);
    i=0;
    j=1;
    fighterImg[0]=":/Image/fighter1.png";
    fighterImg[1]=":/Image/fighter2.png";
    fighterImg[2]=":/Image/fighter3.png";
    //fighteeTimer= new QTimer(this);
    //connect(fighterTimer, SIGNAL(timeout()), this,SLOT(update()));
    //fightTimer->start(1000);
}

void fighter::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(fighterImg[i]);
    painter.drawPixmap(0,0,230,210,pix);
    painter.drawRect(0,0,229,209);
    if(j==4)
        i++;
    else if(j==5)
        i++;
    else
    {
        if(j>6)
        {
            i=0;
            j=0;
        }
    }
    j++;
}

fighter::~fighter()
{

}
