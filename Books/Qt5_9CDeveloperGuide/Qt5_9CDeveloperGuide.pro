QT += widgets

TEMPLATE = lib
DEFINES += QT5_9CDEVELOPERGUIDE_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DGTreeModel.cpp \
    Qt5_9CDeveloperGuideWidget.cpp

HEADERS += \
    DGTreeModel.h \
    Qt5_9CDeveloperGuideWidget.h \
    Qt5_9CDeveloperGuide_global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    Qt5_9CDeveloperGuideWidget.ui
