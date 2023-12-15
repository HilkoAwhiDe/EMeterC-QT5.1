QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    EMeter.cpp \
    calculator.cpp \
    controler.cpp \
    digitalclock.cpp \
    filesource.cpp \
    inedel.cpp \
    main.cpp \
    nedel.cpp \
    skala.cpp \
    skaladimention.cpp \
    ITaValueObserver.cpp \
    ITaValueSubject.cpp \
    tcpsource.cpp

HEADERS += \
    EMeter.h \
    calculator.h \
    controler.h \
    digitalclock.h \
    filesource.h \
    inedel.h \
    nedel.h \
    skala.h \
    skaladimention.h \
    ITaValueSubject.h \
    ITaValueObserver.h \
    tcpsource.h

FORMS += \
    EMeter.ui

TRANSLATIONS += \
    EMeter_de_DE.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    recource.qrc


HEADERS += \
    EMeter.h \
    nedel.h

FORMS += \
    EMeter.ui

TRANSLATIONS += \
    EMeter_de_DE.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    recource.qrc
