#include "enemybullet.h"

EnemyBullet::EnemyBullet()
{
    //加载子弹资源
    m_EnemyBullet.load(ENEMYBULLET_PATH);

    //子弹坐标
    m_X = GAME_WIDTH * 0.5 - m_EnemyBullet.width() * 0.5;
    m_Y = GAME_HEIGHT;

    //子弹状态，默认空闲
    m_EnemyFree = true;

    //子弹速度
    m_EnemySpeed = ENEMYBULLET_SPEED;

    //子弹边框
    m_EnemyRect.setWidth(m_EnemyBullet.width());
    m_EnemyRect.setHeight(m_EnemyBullet.height());
    m_EnemyRect.moveTo(m_X,m_Y);
}

void EnemyBullet::EnemyupdatePosition()
{
    //空闲状态下的子弹，不需用计算坐标
    if(m_EnemyFree)
    {
        return;
    }

    //子弹向下移动
    m_Y += m_EnemySpeed;
    m_EnemyRect.moveTo(m_X,m_Y);

    //子弹位置如果超出屏幕，那么就重新变为空闲状态
    if(m_Y >= GAME_HEIGHT + m_EnemyBullet.height())
    {
        m_EnemyFree = true;
    }
}
