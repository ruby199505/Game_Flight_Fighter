#include "mainwindow.h"
#include <ctime>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>
#include <QLabel>
#include <QDialog>
QSet<int> pressedKeys;

int i = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    win_width = 760;
    win_height = 900;
    this->setFixedSize(win_width,win_height);	//視窗大小
    this->setWindowIcon(QIcon(":/Image/bird1.png"));
    this->setWindowTitle("Fight Flighter");


    //創建鳥
    birds=new ROLE(this);
    birdTimer = new QTimer(this);

    connect(birdTimer, SIGNAL(timeout()), this, SLOT(birdAction()));
    birdTimer->start(100);

    //Music
    bgm =new easyMusic("musicFile/bg_music.mp3",80,1);
    jump_sound = new easyMusic("musicFile/jumpSound.mp3",100,0);
    hit_music = new easyMusic("musicFile/sfx_hit.wav",100,0);

    //遊戲初始模式
    gameRedy();

    //遊戲開始
    gameStart();
}

void MainWindow::paintEvent(QPaintEvent *)		//繪圖事件, 用来產生背景
{
    // 可以在這裡新增背景圖片

    QPainter painter(this);
    QPixmap bgImg;
    bgImg.load(":/Image/background.gif");

    painter.drawPixmap(0, 0, 760, 900, bgImg);
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

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // 在這裡設定按下滑鼠要觸發的功能
}
void MainWindow::createPipe()		//初始化水管，依序排在視窗外
{

}

void MainWindow::createBird(){

    birds->move(60,250);
    //鳥的上下速度
    //-3 -4 -3 -2 -1 -1 -1 0 1 1 2 2 2 3 3
    this->birdV_array[0]=0;
    this->birdV_array[1]=0;
    this->birdV_array[2]=0;
    this->birdV_array[3]=0;
    this->birdV_array[4]=0;
    this->birdV_array[5]=0;
    this->birdV_array[6]=0;
    this->birdV_array[7]=0;
    this->birdV_array[8]=0;
    this->birdV_array[9]=0;
    this->birdV_array[10]=0;
    this->birdV_array[11]=0;
    this->birdV_array[12]=0;
    this->birdV_array[13]=0;
    this->birdV_array[14]=0;

    this->index_birdV=0;

    birdV=0;

    birdTimer=new QTimer(this);
    connect(birdTimer,SIGNAL(timeout()),this,SLOT(birdAction()));
    timedata=8;
}

void MainWindow::moving(char cmd)
{
    if(cmd=='L')
    {
        if(birds->pos().x()>-260) birds->move(birds->pos().x()-20,birds->pos().y());
    }
    if(cmd=='R')
    {
        if(birds->pos().x()<360) birds->move(birds->pos().x()+20,birds->pos().y());
    }
    if(cmd=='U')
    {
        if(birds->pos().y()>-480) birds->move(birds->pos().x(),birds->pos().y()-20);
    }
    if(cmd=='D')
    {
        if(birds->pos().y()<240) birds->move(birds->pos().x(),birds->pos().y()+20);
    }
}

void MainWindow::birdAction()
{
    //鳥的運動
    // 每次觸發這個function都會更改鳥的位置，x軸不變, y軸加上 birdV成為新的位置
    // XX->pos().x() and XX->pos().y() 是QWidget物件的函式，可以用來取得xy座標位置
    birds->move(birds->pos().x(),birds->pos().y()+birdV);


    if(index_birdV<14.0)
        index_birdV+=0.2;
    else
        index_birdV=14.0;

    birdV=birdV_array[int(index_birdV)];

    // 這邊做一個地板碰撞偵測
    /*if(birds->pos().y()+birds->height()>=win_height+10)
    {
        if (i == 0) { // Hit Sound will play once only
            hit_music->play();
            i++;
        }
        birds->move(birds->pos().x(),win_height-birds->height()+10); // XX->height可用來取得物件高度
        birdTimer->stop();        
        gameLose();
    }*/
}

void MainWindow::collisDete()
{
//    //水管碰撞偵測

}
void MainWindow::gameRedy()
{
    gamemod=redy;
    createBird();
//    createPipe();
}
void MainWindow::gameLose()
{
    gamemod=lose;
//    pipeTimer->stop();
}
void MainWindow::gameStart()
{
    gamemod=start;
    birdTimer->start(timedata);
    //pipeTimer->start(pipeTValue);
    bgm->play();
}
