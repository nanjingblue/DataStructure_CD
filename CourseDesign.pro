QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Hash/include/keywords_process.cpp \
    biweight.cpp \
    cmpweight.cpp \
    global.cpp \
    hashweight.cpp \
    main.cpp \
    mainweight.cpp \
    widget.cpp

HEADERS += \
    Hash/include/bi_procress.h \
    Hash/include/hash.h \
    Hash/include/hash_procress.h \
    Hash/include/keywords_process.h \
    Hash/include/quick_sort.h \
    biweight.h \
    cmpweight.h \
    global.h \
    hashweight.h \
    mainweight.h \
    widget.h

FORMS += \
    biweight.ui \
    cmpweight.ui \
    hashweight.ui \
    mainweight.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
