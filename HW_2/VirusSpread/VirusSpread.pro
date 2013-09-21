TEMPLATE = app
CONFIG += console
CONFIG += qt
CONFIG += qtestlib

SOURCES += main.cpp \
    Computer.cpp \
    Graph.cpp \
    LocalNet.cpp \
    Randomiser.cpp \
    WindowsOS.cpp \
    MacOS.cpp \
    LinuxOS.cpp \
    OperatingSystem.cpp

HEADERS += \
    Computer.h \
    OperatingSystem.h \
    LocalNet.h \
    Graph.h \
    Randomiser.h \
    WindowsOS.h \
    MacOS.h \
    LinuxOS.h \
    RandomiserTester.h \
    LocalNetTester.h \
    GraphTester.h

