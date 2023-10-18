#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "config.h"
#include <QPixmap>

class EnemyBullet
{
public:
    EnemyBullet();

    //更新子弹坐标
    void EnemyupdatePosition();

public:

    //子弹资源对象
    QPixmap m_EnemyBullet;

    //子弹坐标
    int m_X;
    int m_Y;

    //子弹移动速度
    int m_EnemySpeed;

    //子弹是否闲置
    bool m_EnemyFree;

    //子弹矩形边框
    QRect m_EnemyRect;
};

#endif // ENEMYBULLET_H
