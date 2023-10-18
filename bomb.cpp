#include "bomb.h"


Bomb::Bomb()
{
    //将所有的爆炸贴图放入数组中
    for(int i = 0; i <= BOMB_MAX; ++i)
    {
        //str 类似于 ":/res/bomb-%1.png"
        QString str = QString(BOMB_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));
    }

    //坐标
    m_X = 0;
    m_Y = 0;

    //空闲状态
    m_Free = true;

    //当前播放图片下标
    m_index= 0;

    //播放爆炸间隔记录
    m_Recoder = 0;
}

void Bomb::updateInfo()
{
    //空闲状态下爆炸效果直接return
    if(m_Free)
    {
        return;
    }

    m_Recoder++;

    //如果记录爆炸的事件未达到爆炸间隔，不需要切图，直接return
    if(m_Recoder < BOMB_INTERVAL)
    {
        return;
    }

    //重置记录
    m_Recoder = 0;

    //切换爆炸时的图片下标
    m_index++;

    //数组中的下标从0开始计算，最后一个为6
    //计算的下标大于6就重置为0，将爆炸效果置为空闲
    if(m_index > BOMB_MAX - 1)
    {
        m_index = 0;
        m_Free = true;
    }
}
