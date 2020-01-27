#ifndef ROCKET_H
#define ROCKET_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<QTimer>
#include <Windows.h>

class Rocket : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Rocket(QObject *parent=nullptr);
    void updateRocket();
    void moveRocket();
private:

    enum ScaleRocketFire{
        Little,
        Middle,
        Big
    };
    ScaleRocketFire scale1;
    ScaleRocketFire scale2;

    qreal speedRocket;



    // QGraphicsItem interface
public:
    //QRectF boundingRect() const;
};

#endif // ROCKET_H
