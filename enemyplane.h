#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include <QPixmap>
#include "config.h"
#include "enemybullet.h"

class EnemyPlane
{
public:
    EnemyPlane();

    //更新坐标
    void EnemyupdatePosition();

public:
    //敌机资源对象
    QPixmap m_enemy;

    //位置
    int m_X;
    int m_Y;

    //敌机的矩形边框
    QRect m_Rect;

    //状态
    bool m_Free;

    //速度
    int m_Speed;

    //发射子弹
    void Enemyshoot();

    //弹匣
    EnemyBullet m_Enemybullets[ENEMYBULLET_NUM];

    //发射时间间隔
    int m_recorder = 0;

};

#endif // ENEMYPLANE_H
