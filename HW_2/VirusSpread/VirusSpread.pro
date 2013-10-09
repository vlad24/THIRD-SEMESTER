TEMPLATE = app
CONFIG += console
CONFIG += qt
CONFIG += qtestlib

SOURCES += main.cpp \
    Computer.cpp \
    Graph.cpp \
    LocalNet.cpp \
    WindowsOS.cpp \
    MacOS.cpp \
    LinuxOS.cpp \
    OperatingSystem.cpp \
    BasicRandomiser.cpp \
    ZeroRandomiser.cpp \
    OneRandomiser.cpp

HEADERS += \
    Computer.h \
    OperatingSystem.h \
    LocalNet.h \
    Graph.h \
    WindowsOS.h \
    MacOS.h \
    LinuxOS.h \
    LocalNetTester.h \
    GraphTester.h \
    BasicRandomiser.h \
    Randomiser.h \
    ZeroRandomiser.h \
    OneRandomiser.h \
    BasicRandomiserTester.h

