#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QTimer>
#include"asteroidpillar.h"

#include"rocket.h"
class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
   explicit Scene(QObject *parent=nullptr);

private:
    Rocket * rocket;
    QTimer* asteroidPillarTimer;

    void setAsteroidPillar();

};

#endif // SCENE_H
