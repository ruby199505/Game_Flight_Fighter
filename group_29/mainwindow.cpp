#include "mainwindow.h"
#include <ctime>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>
#include <QLabel>
#include <QDialog>
#include <iostream>
#include"fighter.h"
QSet<int> pressedKeys;

int i = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    win_width = 760;
    win_height = 900;
    this->setFixedSize(win_width,win_height);	//視窗大小
    this->setWindowIcon(QIcon(":/Image/player1.png"));
    this->setWindowTitle("Fight Flighter");

    setStyleSheet("background-color: black;");
//    //create player
//    player=new ROLE(this);
//    playerTimer = new QTimer(this);

//    connect(playerTimer, SIGNAL(timeout()), this, SLOT(playerAction()));
//    playerTimer->start(100);

//    int i;
//    for(i=0;i<24;i++) bullet[i]=new mybullet(this);
//    bulletTimer = new QTimer(this);
//    connect(bulletTimer, SIGNAL(timeout()), this, SLOT(mybulletAction()));
//    bulletTimer->start(2);
    fighters= new fighter(this);
    fighters->move(0,220);
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(fighterAction()));
    timer->start(1000);
    i=55;

    //Music
    bgm =new easyMusic("musicFile/bg_music.mp3",80,1);
    jump_sound = new easyMusic("musicFile/jumpSound.mp3",100,0);
    hit_music = new easyMusic("musicFile/sfx_hit.wav",100,0);
    createBackground();
    //遊戲初始模式
//    gameRedy();

    //遊戲開始
//    gameStart();
}

void MainWindow::paintEvent(QPaintEvent *)		//繪圖事件, 用来產生背景
{
    // 可以在這裡新增背景圖片

//    QPainter painter(this);
//    QPixmap bgImg;
//    bgImg.load(":/Image/background.gif");

//    painter.drawPixmap(0, 0, 760, 900, bgImg);
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // 在這裡設定按下鍵盤要觸發的功能
    if(event->key()==Qt::Key_Left)
    {
        if(gamemod!=lose) moving('L');
    }
    if(event->key()==Qt::Key_Right)
    {
        if(gamemod!=lose) moving('R');
    }
    if(event->key()==Qt::Key_Up)
    {
        if(gamemod!=lose) moving('U');
    }
    if(event->key()==Qt::Key_Down)
    {
        if(gamemod!=lose) moving('D');
    }
    // shooting
    if(event->key()==Qt::Key_Space)
    {
        if(gamemod!=lose) myshoot();
    }

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // 在這裡設定按下滑鼠要觸發的功能
}


void MainWindow::createPlayer(){

    player->move(0,0);
    playerTimer=new QTimer(this);
    connect(playerTimer,SIGNAL(timeout()),this,SLOT(playerAction()));
    timedata=8;
}

void MainWindow::moving(char cmd)
{
    if(cmd=='L')
    {
        if(player->pos().x()>-300) player->move(player->pos().x()-20,player->pos().y());
    }
    if(cmd=='R')
    {
        if(player->pos().x()<320) player->move(player->pos().x()+20,player->pos().y());
    }
    if(cmd=='U')
    {
        if(player->pos().y()>-720) player->move(player->pos().x(),player->pos().y()-20);
    }
    if(cmd=='D')
    {
        if(player->pos().y()<0) player->move(player->pos().x(),player->pos().y()+20);
    }
}

void MainWindow::myshoot()
{
    bullet[i++]->move(player->pos().x()+357,player->pos().y()+740);
    if(i==24) i=0;
}

void MainWindow::mybulletAction()
{
    bullet[i]->move(bullet[i]->pos().x(),bullet[i]->pos().y()-40);
    i++;
    if(i==24) i = 0;
}


void MainWindow::playerAction()
{

}

void MainWindow::collisDete()
{
    //水管碰撞偵測

}
void MainWindow::gameRedy()
{
    gamemod=redy;
    createPlayer();
}
void MainWindow::gameLose()
{
    gamemod=lose;
}
void MainWindow::gameStart()
{
    gamemod=start;
    playerTimer->start(timedata);
    bgm->play();
}
void MainWindow::createBackground()

{

    QMovie* movie = new QMovie(":/Image/start.gif");

    if (!movie->isValid())

    {

        std::cout << "Something wrong" << std::endl;

    }

    QLabel* label = new QLabel(this);

    label->setGeometry(0,0,720,900);
    label->setMovie(movie);

    movie->start();

}
void MainWindow::fighterAction()
{
    int step_lenghth=55;

    if(i<=step_lenghth*4)
    {
        fighters->move(i,220);
        i=i+step_lenghth;
    }
    else
    {
        i=0;
    }
}
