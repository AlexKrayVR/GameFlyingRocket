#include "scene.h"

Scene::Scene(QObject *parent): QGraphicsScene(parent)
{
setAsteroidPillar();

    QGraphicsPixmapItem *pixmap=new QGraphicsPixmapItem(QPixmap(":/Images/Space.jpg"));
    addItem(pixmap);
    pixmap->setPos(QPointF(0,0));

//    QGraphicsPixmapItem *asteroid=new QGraphicsPixmapItem(QPixmap(":/Images/Asteroid5.png"));
//    addItem(asteroid);
//    asteroid->setPos(QPointF(200,200));
//    asteroid->setScale(0.1);
//    asteroid->setFlag(QGraphicsItem::ItemIsMovable);

    rocket=new Rocket(this);
    rocket->setPos(50,this->height()/2);

    addItem(rocket);

    QTimer *timer=new QTimer(this);
    connect(timer,&QTimer::timeout,[=](){
        rocket->moveRocket();
    });
   timer->start(20);


    addLine(width()/2,0,width()/2,height(),QPen(Qt::blue));
    addLine(0,height()/2,width(),height()/2,QPen(Qt::blue));

}

void Scene::setAsteroidPillar()
{
    asteroidPillarTimer=new QTimer(this);

    connect(asteroidPillarTimer,&QTimer::timeout,[=](){

    AsteroidPillar* pillarItem=new AsteroidPillar();

    addItem(pillarItem);

    });

    asteroidPillarTimer->start(3000);
}
