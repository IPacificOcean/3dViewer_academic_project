QT       += core gui opengl openglwidgets widgets

#LIBS += -lopengl32 -lglu32
#LIBS += -glut
LIBS += -framework GLUT


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../../../../Downloads/C8_3DViewer_v1.0-1-develop-src/src/parser_2.0.c \
    main.cpp \
    glviewer.cpp

HEADERS += \
    ../../../../../Downloads/C8_3DViewer_v1.0-1-develop-src/src/parser.h \
    glviewer.h

FORMS += \
    glviewer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../cube.obj
