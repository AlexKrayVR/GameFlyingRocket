#include "scene.h"

Scene::Scene(QObject *parent): QGraphicsScene(parent),gameOn(false),
    score(0),bestScore(0),checkHit(false)
{    
    setAsteroidPillar();

    //set background of scene
    QGraphicsPixmapItem *pixmap=new QGraphicsPixmapItem(QPixmap(":/Images/Space.jpg"));
    addItem(pixmap);
    pixmap->setPos(QPointF(0,0));

    //set rocket on scene
    rocket=new Rocket(this);
    rocket->setPos(50,this->height()/2);
    addItem(rocket);
    moveRocketTimer=new QTimer(this);
    connect(moveRocketTimer,&QTimer::timeout,[=](){
        rocket->moveRocket();
    });

    //set auxiliary lines on scene through center
    addLine(width()/2,0,width()/2,height(),QPen(Qt::blue));
    addLine(0,height()/2,width(),height()/2,QPen(Qt::blue));
}
// clean scene from pillars and start
void Scene::startGame()
{
    if(!asteroidPillarTimer->isActive()){
        cleanPillar();

        rocket->startRocket();
        moveRocketTimer->start(20);

        setGameOn(true);
        asteroidPillarTimer->start(3000);
    }
}

bool Scene::getGameOn() const
{
    return gameOn;
}

void Scene::setGameOn(bool value)
{
    gameOn = value;
}

void Scene::incrementScore()
{
    score++;
    if(score>bestScore){
        bestScore=score;
    }
    qDebug()<<"Score:"<<score;
    qDebug()<<"BestScore:"<<bestScore;
}


void Scene::cleanPillar()
{
    QList<QGraphicsItem*> sceneItems=items();
    foreach(QGraphicsItem* item, sceneItems){
        AsteroidPillar* pillarItem=dynamic_cast<AsteroidPillar*>(item);
        if(pillarItem){
            removeItem(pillarItem);
            delete pillarItem;
        }
    }
}
//freezeScene if hit pillar
void Scene::freezeScene()
{
    rocket->freeze();
    asteroidPillarTimer->stop();
    moveRocketTimer->stop();
    QList<QGraphicsItem*> sceneItems=items();
    foreach(QGraphicsItem* item, sceneItems){
        AsteroidPillar* pillarItem=dynamic_cast<AsteroidPillar*>(item);
        if(pillarItem){
            pillarItem->freeze();
        }
    }
}
// create asteroidpillars dynamically
void Scene::setAsteroidPillar()
{    
    asteroidPillarTimer=new QTimer(this);

    connect(asteroidPillarTimer,&QTimer::timeout,[=](){
        checkHit=false;
        AsteroidPillar* pillarItem=new AsteroidPillar();
        addItem(pillarItem);
        connect(pillarItem, &AsteroidPillar::colliderFail,[=](){
            checkHit=true;
            rocket->liveCount--;
            qDebug()<<"liveCount="<<rocket->liveCount;
            score=0;
            freezeScene();
            setGameOn(false);
        });
    });
}
