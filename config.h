#ifndef CONFIG_H
#define CONFIG_H

/************ 游戏配置数据 **************/
#define GAME_WIDTH  1024  //宽度
#define GAME_HEIGHT 1536  //高度
#define GAME_TITLE "飞机大战 V1.0 —— 作者：Matt（2022214168）"
#define GAME_RES_PATH "./plane.rcc"
#define GAME_ICON ":/res/app.ico"//页面图标
#define GAME_RATE 5 //单位：毫秒 游戏刷新速度

/************ 地图配置数据 **************/
#define MAP_PATH ":/res/img_bg_level_5.jpg" //地图路径
#define MAP_SCROLL_SPEED 2 //地图滚动速度

/************ 飞机配置数据 **************/
#define HERO_PATH ":/res/app.ico"  //飞机贴图路径

/************ 子弹配置数据 **************/
#define BULLET_PATH ":/res/hero_bullet_7.png"  //子弹贴图路径
#define BULLET_SPEED 5 //子弹速度配置
#define BULLET_NUM 40  //弹匣中子弹个数
#define BULLET_INTERVAL 10 //子弹发射间隔

/************ 敌机配置数据 **************/
#define ENEMY_PATH ":/res/game.ico"  //敌机贴图路径
#define ENEMY_SPEED 3
#define ENEMY_NUM 10 //敌机数量
#define ENEMY_INTERVAL 30 //敌机出厂时间间隔
#define ENEMYBULLET_NUM 1
#define ENEMYBULLET_INTERVAL 300
#define ENEMYBULLET_SPEED 4
#define ENEMYBULLET_PATH ":/res/bullet_3.png"

/************ Boss配置数据 **************/
#define BOSS_PATH ":/res/BOSS.png"
#define BOSS_SPEED 0
#define BOSS_NUM 1
#define BOSS_INTERVAL 1000
#define BOSS_BULLET_SPEED 3
#define BOSS_BULLET_NUM 25
#define BOSS_BULLET_INTERVAL 20
#define BOSS_BULLET_PATH ":/res/bullet_5.png"

/************ 爆炸配置数据 **************/
#define BOMB_PATH ":/res/bomb-%1.png"
#define BOMB_NUM 10 //爆炸数量
#define BOMB_MAX 3 //爆炸图片最大索引
#define BOMB_INTERVAL 20 //爆炸切换时间间隔

/************ 音效配置数据 **************/
#define SOUND_BACKGROUND ":/res/bg.wav"
#define SOUND_BOMB ":/res/bomb.wav"

#endif // CONFIG_H
