#include "asteroidpillar.h"

AsteroidPillar::AsteroidPillar():
    topPillar(new QGraphicsPixmapItem(QPixmap(":/Images/Asteroid5.png"))),
    bottomPillar(new QGraphicsPixmapItem(QPixmap(":/Images/Asteroid5.png")))
{

    topPillar->setScale(0.1);
    bottomPillar->setScale(0.1);

    topPillar->setPos(0,-230);
    bottomPillar->setPos(0,170);

    addToGroup(topPillar);
    addToGroup(bottomPillar);

    yPos=QRandomGenerator::global()->bounded(300);
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

}

qreal AsteroidPillar::x() const
{
    return m_x;
}

void AsteroidPillar::setX(qreal x)
{
    //if (qFuzzyCompare(m_x, x))
        //return;
    m_x = x;
    setPos(QPointF(x,yPos));
}
