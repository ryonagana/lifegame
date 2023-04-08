TEMPLATE += app
CONFIG -= qt


QMAKE_CXXFLAGS += -std=c++14 -Wall -Werror -Wextra -Wunused -Wno-switch

unix: {
    #INCLUDEPATH += /usr/include
    #INCLUDEPATH += -L/usr/include/c++/10
    LIBS += -L/usr/lib64
    LIBS += -lallegro -lallegro_primitives  -lallegro_font -lallegro_ttf -lallegro_image -lallegro_dialog

}

SOURCES += \
    ../Menu.cpp \
    ../MenuHall.cpp \
    ../bigTextLabel.cpp \
    ../button.cpp \
    ../config.cpp \
    ../gameScreenContext.cpp \
    ../hall.cpp \
    ../informationPanel.cpp \
    ../main.cpp

HEADERS += \
    ../Menu.h \
    ../MenuHall.h \
    ../bigTextLabel.h \
    ../button.h \
    ../classCallBack.h \
    ../config.h \
    ../gameScreenContext.h \
    ../hall.h \
    ../informationPanel.h \
    ../interfaceComponent.h
