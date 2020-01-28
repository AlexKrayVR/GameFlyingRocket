#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QTimer>
#include"asteroidpillar.h"
#include<QDebug>
#include"rocket.h"
class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
   explicit Scene(QObject *parent=nullptr);    

    void startGame();

    bool getGameOn() const;
    void setGameOn(bool value);

    void incrementScore();
private:
    Rocket * rocket;
    QTimer* asteroidPillarTimer;
    QTimer* moveRocketTimer;

    bool gameOn;

    void cleanPillar();
    void freezeScene();
    void setAsteroidPillar();


    int score;
    int bestScore;

    bool checkHit;

};

#endif // SCENE_H
