QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    MainWindow.cpp \
    toolwindowmanager/ToolWindowManager.cpp \
    toolwindowmanager/ToolWindowManagerArea.cpp \
    toolwindowmanager/ToolWindowManagerSplitter.cpp \
    toolwindowmanager/ToolWindowManagerTabBar.cpp \
    toolwindowmanager/ToolWindowManagerWrapper.cpp

HEADERS += \
    MainWindow.h \
    toolwindowmanager/ToolWindowManager.h \
    toolwindowmanager/ToolWindowManagerArea.h \
    toolwindowmanager/ToolWindowManagerSplitter.h \
    toolwindowmanager/ToolWindowManagerTabBar.h \
    toolwindowmanager/ToolWindowManagerWrapper.h

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Books/Qt5_9CDeveloperGuide/release/ -lQt5_9CDeveloperGuide
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Books/Qt5_9CDeveloperGuide/debug/ -lQt5_9CDeveloperGuide
else:unix:!macx: LIBS += -L$$OUT_PWD/../Books/Qt5_9CDeveloperGuide/ -lQt5_9CDeveloperGuide

INCLUDEPATH += $$PWD/../Books/Qt5_9CDeveloperGuide
DEPENDPATH += $$PWD/../Books/Qt5_9CDeveloperGuide

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Draws/DrawsDll/release/ -lDrawsDll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Draws/DrawsDll/debug/ -lDrawsDll
else:unix: LIBS += -L$$OUT_PWD/../Draws/DrawsDll/ -lDrawsDll

INCLUDEPATH += $$PWD/../Draws/DrawsDll
DEPENDPATH += $$PWD/../Draws/DrawsDll
