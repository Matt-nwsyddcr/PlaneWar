#ifndef BOSS_H
#define BOSS_H

#include "config.h"
#include <QPixmap>

class Boss
{
public:
    Boss();

    //更新坐标
    void BossupdatePosition();

public:
    //敌机资源对象
    QPixmap m_boss;

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
    void Bossshoot();

    //发射时间间隔
    int m_recorder = 0;
};

#endif // BOSS_H
