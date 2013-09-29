TEMPLATE = app
CONFIG += console
CONFIG += qt
CONFIG += qtestlib

SOURCES += main.cpp \
    Graph.cpp \
    RobotDestroyer.cpp \
    PointerList.cpp

HEADERS += \
    Graph.h \
    RobotDestroyer.h \
    RobotDestroyerTester.h \
    PointerList.h \
    PointerListTester.h \
    GraphTester.h

