QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += resources_big

SOURCES += \
    bomb.cpp \
    boss.cpp \
    bullet.cpp \
    enemybullet.cpp \
    enemyplane.cpp \
    heroplane.cpp \
    main.cpp \
    mainscene.cpp \
    map.cpp

HEADERS += \
    bomb.h \
    boss.h \
    bullet.h \
    config.h \
    enemybullet.h \
    enemyplane.h \
    heroplane.h \
    mainscene.h \
    map.h

RESOURCES += \
    res.qrc

