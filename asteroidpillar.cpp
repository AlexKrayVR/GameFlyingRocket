#include "asteroidpillar.h"

AsteroidPillar::AsteroidPillar():
    topPillar(new QGraphicsPixmapItem(QPixmap(":/Images/Asteroid7.png"))),
    bottomPillar(new QGraphicsPixmapItem(QPixmap(":/Images/Asteroid7.png"))),
    past(false)
{

    topPillar->setScale(0.1);
    bottomPillar->setScale(0.1);

    topPillar->setPos(0,-170);
    bottomPillar->setPos(0,340);

    addToGroup(topPillar);
    addToGroup(bottomPillar);

    //random number for set pillar from top to bottom
    yPos=QRandomGenerator::global()->bounded(400)-240;
    qDebug()<<"pillar position:"<<yPos;

    xAnimation=new QPropertyAnimation(this,"x",this);
    xAnimation->setStartValue(1000);
    xAnimation->setEndValue(-100);
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration(4000);

    connect(xAnimation,&QPropertyAnimation::finished,[=](){
        scene()->removeItem(this);
        delete this;
    });
    xAnimation->start();
}

AsteroidPillar::~AsteroidPillar()
{
    delete topPillar;
    delete bottomPillar;
}

qreal AsteroidPillar::x() const
{
    return m_x;
}

void AsteroidPillar::freeze()
{
    xAnimation->stop();
}

void AsteroidPillar::setX(qreal x)
{    
    m_x = x;
    if(x<0&&!past){
        past=true;
        QGraphicsScene *mScene=scene();
        Scene *myScene=dynamic_cast<Scene*>(mScene);
        if(myScene)
        {
            myScene->incrementScore();
        }
    }

    if(collidesWithRocket()){
        qDebug()<<"hit1";
        emit colliderFail();
    }
    setPos(QPointF(x, yPos));
}

//check if our rocket hit first or second asteroid kit
bool AsteroidPillar::collidesWithRocket()
{
    QList<QGraphicsItem*> collidingItems=topPillar->collidingItems();
    collidingItems.append(bottomPillar->collidingItems());

    foreach(QGraphicsItem* item, collidingItems){
        Rocket* rocket=dynamic_cast<Rocket*>(item);
        if(rocket){
            return true;
        }
    }
    return false;
}



