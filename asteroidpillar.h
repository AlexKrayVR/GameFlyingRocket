#ifndef ASTEROIDPILLAR_H
#define ASTEROIDPILLAR_H

#include <QObject>
#include<QGraphicsItemGroup>
#include<QGraphicsScene>
#include<QRandomGenerator>
#include<QDebug>
#include"rocket.h"
#include<QGraphicsPixmapItem>
#include<QPropertyAnimation>
#include"scene.h"
class AsteroidPillar :public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX)
public:
     explicit AsteroidPillar();
    ~AsteroidPillar();
    qreal x() const;
    QPropertyAnimation * xAnimation;

    void freeze();



public slots:
    void setX(qreal x);

signals:
    void colliderFail();


private:

    bool collidesWithRocket();

    qreal m_x;
    int yPos;

    QGraphicsPixmapItem * topPillar;
    QGraphicsPixmapItem * bottomPillar;

    bool past;

};

#endif // ASTEROIDPILLAR_H
