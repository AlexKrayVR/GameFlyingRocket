#include "rocket.h"

Rocket::Rocket(QObject *parent):QObject(parent),scale1(ScaleRocketFire::Middle),
    scale2(ScaleRocketFire::Middle),
    speedRocket(70.0)
{

    setPixmap(QPixmap(":/Images/rocketMiddleSize.png"));
    setScale(0.12);
    QTimer *timer=new QTimer(this);
    connect(timer,&QTimer::timeout,[=](){
        updateRocket();
    });
    timer->start(50);
}

void Rocket::updateRocket()
{
    if(scale1==ScaleRocketFire::Middle)
    {
        if(scale2==ScaleRocketFire::Middle)
        {
            //Big
            setPixmap(QPixmap(":/Images/rocketBig.png"));
            scale1=ScaleRocketFire::Big;
            scale2=ScaleRocketFire::Big;
        }else
        {
            //Little
            setPixmap(QPixmap(":/Images/rocketLittle.png"));
            scale1=ScaleRocketFire::Little;
            scale2=ScaleRocketFire::Middle;
        }
    }else
    {
        setPixmap(QPixmap(":/Images/rocketMiddleSize.png"));
        scale1=ScaleRocketFire::Middle;
    }
}

void Rocket::moveRocket()
{
    if(GetAsyncKeyState(VK_LEFT)){
        setPos(mapToScene(-speedRocket,0));
    }
    if(GetAsyncKeyState(VK_RIGHT)){
         setPos(mapToScene(speedRocket,0));
    }

    if(GetAsyncKeyState(VK_UP)){
        setPos(mapToParent(0,-speedRocket));
    }

    if(GetAsyncKeyState(VK_DOWN)){
        setPos(mapToParent(0,speedRocket));
    }

    if(this->x()<20){
        this->setX(20);
    }
    if(this->x()>300){
        this->setX(300);
   }

    if(this->y()<10){
        this->setY(10);
    }
    if(this->y()>420){
        this->setY(420);
    }
}
