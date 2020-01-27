#ifndef ASTEROIDPILLAR_H
#define ASTEROIDPILLAR_H

#include <QObject>
#include<QGraphicsItemGroup>
#include<QGraphicsScene>
#include<QRandomGenerator>
#include<QDebug>

#include<QGraphicsPixmapItem>
#include<QPropertyAnimation>

class AsteroidPillar :public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX)
public:
     explicit AsteroidPillar();
    ~AsteroidPillar();
    qreal x() const;
public slots:
    void setX(qreal x);
private:
    qreal m_x;
    int yPos;
    QGraphicsPixmapItem * topPillar;
    QGraphicsPixmapItem * bottomPillar;

    QPropertyAnimation * xAnimation;
};

#endif // ASTEROIDPILLAR_H
