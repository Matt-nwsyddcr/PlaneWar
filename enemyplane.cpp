#include "enemyplane.h"

EnemyPlane::EnemyPlane()
{
    //敌机资源加载
    m_enemy.load(ENEMY_PATH);

    //敌机位置
    m_X = 0;
    m_Y = 0;

    //敌机状态
    m_Free = true;

    //敌机速度
    m_Speed = ENEMY_SPEED;

    //敌机矩形边框（碰撞判定）
    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(m_X,m_Y);

}

void EnemyPlane::EnemyupdatePosition()
{
    //空闲状态敌机不计算坐标
    if(m_Free)
    {
        return;
    }



    m_Y += m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    //如果超出屏幕那就重置空闲状态
    if(m_Y >= GAME_HEIGHT + m_Rect.height())
    {
        m_Free = true;
    }
}

void EnemyPlane::Enemyshoot()
{
    //累加时间间隔记录变量
    m_recorder++;

    //如果记录的数字未达到记录的时间间隔，直接return，不发射子弹
    if(m_recorder < ENEMYBULLET_INTERVAL)
    {
        return;
    }

    //如果达到发射时间
    m_recorder= 0;

    //发射子弹
    for(int i = 0; i < ENEMYBULLET_NUM; i++)
    {
        //如果是空闲的子弹就发射
        if(m_Enemybullets[i].m_EnemyFree)
        {
            //将空闲状态改位假
            m_Enemybullets[i].m_EnemyFree = false;

            //设置子弹坐标
            m_Enemybullets[i].m_X = m_X + m_Rect.width() * 0.5 - 10;
            m_Enemybullets[i].m_Y = m_Y + 60;
            break;
        }
    }
}
