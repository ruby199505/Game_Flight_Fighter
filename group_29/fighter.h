#ifndef FIGHTER_H
#define FIGHTER_H

#include <QWidget>

class fighter : public QWidget
{
    Q_OBJECT
public:
    explicit fighter(QWidget *parent = 0);
    ~fighter();

protected:
    void paintEvent(QPaintEvent *);

signals:

public slots:
private:
    int i;
    int j;
    QString fighterImg[3];
};

#endif // FIGHTER_H
