#include "mainscene.h"

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    //调用初始化场景
    initScene();

    //启动游戏
    playGame();
}

MainScene::~MainScene()
{
}

void MainScene::initScene()
{
    //设置窗口固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置标题
    setWindowTitle(GAME_TITLE);

    //加载图标
    setWindowIcon(QIcon(GAME_ICON));

    //定时器设置
    m_Timer.setInterval(GAME_RATE);

    //敌机出场时间间隔初始化
    m_recorder = 0;

    //随机数种子
    srand((unsigned int)time(NULL));

}

void MainScene::playGame()
{
    //启动背景音乐
    QSound::play(SOUND_BACKGROUND);

    //启动定时器
    m_Timer.start();

    //监听定时器发送的信号
    connect(&m_Timer , &QTimer::timeout,[=](){
        //敌机出场
        enemyToScene();

        //更新游戏中元素的坐标
        updatePosition();

        //绘制到频幕中
        update();
        //碰撞检测
        collisionDetection();

    });
}

void MainScene::updatePosition()
{
    if(m_hero.m_Free == false)
    {
        //更新地图坐标
        m_map.mapPosition();

        //英雄飞机发射子弹
        m_hero.shoot();

        //计算所有非空闲子弹的当前坐标
        for(int i = 0; i < BULLET_NUM; i++)
        {
            //如果非空闲，计算发射位置
            if(m_hero.m_bullets[i].m_Free == false)
            {
                m_hero.m_bullets[i].updatePosition();
            }
        }

        //敌机出场
        for(int i = 0; i < ENEMY_NUM; i++)
        {

            if(m_enemys[i].m_Free == false)
            {
                m_enemys[i].EnemyupdatePosition();
            }

            //敌机发射子弹
            m_enemys[i].Enemyshoot();

            //计算所有非空闲子弹的当前坐标
            for(int j = 0; j < ENEMYBULLET_NUM; j++)
            {
                //如果非空闲，计算发射位置
                if(m_enemys[i].m_Enemybullets[j].m_EnemyFree == false)
                {
                    m_enemys[i].m_Enemybullets[j].EnemyupdatePosition();
                }
            }
        }

        //计算爆炸后播放的图片
        for(int i = 0; i < BOMB_NUM; i++)
        {
            if(m_Bombs[i].m_Free == false)
            {
                m_Bombs[i].updateInfo();
            }
        }
    }

    //测试子弹
    //temp_Bullet.m_Free = false;
    //temp_Bullet.updatePosition();
}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //绘制地图
    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);


    if(m_hero.m_Free == false)
    {
        //绘制英雄飞机
        painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.m_Plane);

        //绘制英雄飞机子弹
        for(int i = 0; i < BULLET_NUM; i++)
        {
            //如果非空闲那就绘制
            if(m_hero.m_bullets[i].m_Free == false)
            {
                painter.drawPixmap(m_hero.m_bullets[i].m_X,m_hero.m_bullets[i].m_Y,m_hero.m_bullets[i].m_Bullet);
            }
        }

        //绘制敌机
        for(int i = 0; i < ENEMY_NUM; i++)
        {
            if(m_enemys[i].m_Free == false)
            {
                painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);
            }
        }

        //绘制敌机子弹
        for(int i = 0; i < ENEMY_NUM; i++)
        {
            //绘制敌机子弹
            for(int j = 0; j < ENEMYBULLET_NUM; j++)
            {
                //如果非空闲那就绘制
                if(m_enemys[i].m_Enemybullets[i].m_EnemyFree == false)
                {
                    painter.drawPixmap(m_enemys[i].m_Enemybullets[j].m_X,m_enemys[i].m_Enemybullets[j].m_Y,m_enemys[i].m_Enemybullets[j].m_EnemyBullet);
                }
            }
        }

        //绘制爆炸
        for(int i = 0; i < BOMB_NUM; i++)
        {
            if(m_Bombs[i].m_Free == false)
            {
                painter.drawPixmap(m_Bombs[i].m_X,m_Bombs[i].m_Y,
                                   m_Bombs[i].m_pixArr[m_Bombs[i].m_index]);
            }
        }

        /*//绘制当前分数
        QFont font2("黑体", 20);
        painter.setFont(font2);
        QString text111 = "最终得分为：";
        QString numberString = QString::number(Score); // 将整数转换为字符串
        text111 += numberString; // 将字符串连接起来

        painter.drawText(GAME_HEIGHT, GAME_WIDTH, text111);
        */

    }
    else
    {
        int x = GAME_HEIGHT*0.5-500; // 替换为你想要的x坐标
        int y = GAME_WIDTH*0.5; // 替换为你想要的y坐标

        QFont font("黑体", 40); // 使用黑体字体，字号为20
        painter.setFont(font);
        // 设置画笔颜色为白色
                QPen pen(Qt::white);
                painter.setPen(pen);
        painter.drawText(x, y, "GAME OVER!");

        QFont font1("黑体", 20);
        painter.setFont(font1);
        QString text = "最终得分为：";
        QString numberString = QString::number(Score); // 将整数转换为字符串
        text += numberString; // 将字符串连接起来

        painter.drawText(x+60, y+100, text);
    }
}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x() - m_hero.m_Rect.width() * 0.5;
    int y = event->y() - m_hero.m_Rect.height() * 0.5;

    //边界检测
    borderCheck(&x,&y);

    m_hero.setPosition(x,y);
}

void MainScene::borderCheck(int *x, int *y)
{
    if(*x <= 0)
    {
        *x = 0;
    }
    if(*x >= GAME_WIDTH - m_hero.m_Rect.width())
    {
        *x = GAME_WIDTH - m_hero.m_Rect.width();
    }
    if(*y <= 0)
    {
        *y = 0;
    }
    if(*y >= GAME_HEIGHT - m_hero.m_Rect.height())
    {
        *y = GAME_HEIGHT - m_hero.m_Rect.height();
    }

}

void MainScene::enemyToScene()
{
    m_recorder++;
    //未达到出场间隔就直接return
    if(m_recorder < ENEMY_INTERVAL)
    {
        return;
    }
    m_recorder = 0;

    for(int i = 0; i < ENEMY_NUM; i++)
    {
        //如果是空闲敌机就出场
        if(m_enemys[i].m_Free)
        {
            m_enemys[i].m_Free = false;

            //坐标
            m_enemys[i].m_X = rand()%(GAME_WIDTH - m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
            break;
        }
    }
}

void MainScene::collisionDetection()
{
    //遍历所有非空闲的敌机
    for(int i = 0; i < ENEMY_NUM; i++)
    {
        //如果是空闲敌机就跳转下一次循环
        if(m_enemys[i].m_Free)
        {
            continue;
        }

        //遍历所有非空闲子弹
        for(int j = 0; j < BULLET_NUM; j++)
        {
            //空闲子弹跳转下一次循环
            if(m_hero.m_bullets[j].m_Free)
            {
                continue;
            }

            //如果矩形框和敌机矩形框相交就发生碰撞，同时变为空闲状态
            if(m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
            {
                m_enemys[i].m_Free = true;
                m_hero.m_bullets[j].m_Free = true;

                //播放爆炸效果
                for(int k = 0; k < BOMB_NUM; k++)
                {
                    //播放爆炸音效
                    QSound::play(SOUND_BOMB);
                    //空闲的爆炸，可以播放矢量了
                    m_Bombs[k].m_Free = false;
                    //更新爆炸坐标
                    m_Bombs[k].m_X = m_enemys[i].m_X;
                    m_Bombs[k].m_Y = m_enemys[i].m_Y;
                    Score++;
                    break;
                }
            }
        }
    }

    //如果英雄飞机与敌机相撞就爆炸
    for(int i = 0; i <= ENEMY_NUM; i++)
    {
        //如果是空闲敌机就跳转下一次循环
        if(m_enemys[i].m_Free)
        {
            continue;
        }

        if(m_hero.m_Rect.intersects(m_enemys[i].m_Rect))
        {
            m_hero.m_Free = true;
        }
    }

    //如果英雄飞机与敌机子弹相撞就爆炸
    //遍历所有非空闲的敌机
    for(int i = 0; i < ENEMY_NUM; i++)
    {
        //如果是空闲敌机就跳转下一次循环
        if(m_enemys[i].m_Free)
        {
            continue;
        }

        //遍历所有非空闲子弹
        for(int j = 0; j < ENEMYBULLET_NUM; j++)
        {
            //空闲子弹跳转下一次循环
            if(m_hero.m_bullets[j].m_Free)
            {
                continue;
            }

            //如果矩形框和yingxiong机矩形框相交就发生碰撞，同时变为空闲状态
            if(m_hero.m_Rect.intersects(m_enemys[i].m_Enemybullets[j].m_EnemyRect))
            {
                m_hero.m_Free = true;
            }
        }
    }
}


