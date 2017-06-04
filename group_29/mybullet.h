#ifndef MYBULLET_H
#define MYBULLET_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <math.h>

class mybullet : public QWidget
{
    Q_OBJECT
public:
    explicit mybullet(QWidget *parent = 0);
    ~mybullet();

protected:
    void paintEvent(QPaintEvent *);

private:
    QTimer *bulletTimer;
    QString bulletImg;

};
#endif // MYBULLET_H
