#-------------------------------------------------
#
# Project created by QtCreator 2022-04-27T10:37:24
#
#-------------------------------------------------

QT          += core gui network xml
CONFIG      += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CouplingDocking
TEMPLATE = app


SOURCES     += $$PWD/*.cpp \
    tcp/MyClient.cpp \
    tcp/MyRecognize.cpp

HEADERS     += $$PWD/*.h \
    tcp/MyClient.h \
    tcp/MyRecognize.h

FORMS       += $$PWD/*.ui
RC_ICONS = openpilotgcscsg.ico

win32 {
LIBS += -L$$PWD/hcnetsdk/lib/win32/ -lHCNetSDK -lPlayCtrl -lAudioRender -lSuperRender -lAnalyzeData -lHCCore -lHCPreview -lHCDisplay  -lHCGeneralCfgMgr -lHCAlarm -lGdiPlus
}

linux-* {
LIBS += -L$$PWD/hcnetsdk/lib/linux64/ -lhcnetsdk -lPlayCtrl -lAudioRender -lSuperRender
}
