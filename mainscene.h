#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
#include <QWidget>
#include <QTimer>
#include "map.h"
#include "heroplane.h"
#include "config.h"
#include "bullet.h"
#include "enemyplane.h"
#include <ctime>
#include "bomb.h"
#include <QSound>
#include <QFont>

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //初始化场景
    void initScene();

    //启动游戏
    void playGame();

    //更新游戏中所有元素的坐标
    void updatePosition();

    //绘制到屏幕中
    void paintEvent(QPaintEvent *);

    //重新鼠标移动事件  (函数名称不可改)
    void mouseMoveEvent(QMouseEvent *event);
    //边缘检测
    void borderCheck(int *x,int *y);

    //敌机出场
    void enemyToScene();

    //碰撞检测
    void collisionDetection();

    //敌机数组
    EnemyPlane m_enemys[ENEMY_NUM];

    //敌机出场间隔记录
    int m_recorder;

    //地图对象
    Map m_map;

    //飞机对象
    HeroPlane m_hero;

    //定时器
    QTimer m_Timer;

    //爆炸数组
    Bomb m_Bombs[BOMB_NUM];

    //得分
    int Score = 0;

    //子弹对象
    //Bullet temp_Bullet;

};
#endif // MAINSCENE_H
