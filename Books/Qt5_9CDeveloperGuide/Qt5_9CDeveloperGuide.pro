QT += widgets

TEMPLATE = lib
DEFINES += QT5_9CDEVELOPERGUIDE_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DGTreeModel.cpp \
    Qt5_9CDeveloperGuideWidget.cpp \
    SampDialog.cpp \
    chap13Thead/samp13_1ThreadSignal/dialog13_1.cpp \
    chap13Thead/samp13_1ThreadSignal/qdicethread13_1.cpp \
    chap13Thead/samp13_2QMutex/dialog13_2.cpp \
    chap13Thead/samp13_2QMutex/qdicethread13_2.cpp \
    chap13Thead/samp13_5Semaphore/dialog13_5.cpp \
    chap13Thead/samp13_5Semaphore/qmythread13_5.cpp

HEADERS += \
    DGTreeModel.h \
    Qt5_9CDeveloperGuideWidget.h \
    Qt5_9CDeveloperGuide_global.h \
    SampDialog.h \
    chap13Thead/samp13_1ThreadSignal/dialog13_1.h \
    chap13Thead/samp13_1ThreadSignal/qdicethread13_1.h \
    chap13Thead/samp13_2QMutex/dialog13_2.h \
    chap13Thead/samp13_2QMutex/qdicethread13_2.h \
    chap13Thead/samp13_5Semaphore/dialog13_5.h \
    chap13Thead/samp13_5Semaphore/qmythread13_5.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    Qt5_9CDeveloperGuideWidget.ui \
    chap13Thead/samp13_1ThreadSignal/dialog13_1.ui \
    chap13Thead/samp13_2QMutex/dialog13_2.ui \
    chap13Thead/samp13_5Semaphore/dialog13_5.ui
RESOURCES += \
    Resources.qrc

SUBDIRS += \
    chap13Thead/samp13_5Semaphore/samp13_5.pro \
    chap13Thead/samp13_5Semaphore/samp13_5.pro
