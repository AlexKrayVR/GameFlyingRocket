#ifndef ROCKET_H
#define ROCKET_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<QTimer>
#include <Windows.h>
#include<QDebug>

class Rocket : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Rocket(QObject *parent=nullptr);
    void updateRocket();
    void moveRocket();
    void freeze();
    void startRocket();

    int liveCount;
private:

    enum ScaleRocketFire{
        Little,
        Middle,
        Big
    };
    ScaleRocketFire scale1;
    ScaleRocketFire scale2;

    qreal speedRocket;
    QTimer *timer;

};

#endif // ROCKET_H
