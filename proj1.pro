QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addfunction.cpp \
    adminui.cpp \
    auctionbuygood.cpp \
    buyer.cpp \
    buygood.cpp \
    file.cpp \
    good.cpp \
    info.cpp \
    launchgood.cpp \
    list.cpp \
    logindlg.cpp \
    main.cpp \
    mainwindow.cpp \
    manual.cpp \
    modify.cpp \
    order.cpp \
    recharge.cpp \
    register.cpp \
    remove.cpp \
    search.cpp \
    seller.cpp \
    test.cpp \
    user.cpp \
    userui.cpp

HEADERS += \
    addfunction.h \
    adminui.h \
    auctionbuygood.h \
    buyer.h \
    buygood.h \
    file.h \
    good.h \
    info.h \
    launchgood.h \
    list.h \
    logindlg.h \
    mainwindow.h \
    manual.h \
    modify.h \
    order.h \
    recharge.h \
    register.h \
    remove.h \
    search.h \
    seller.h \
    test.h \
    user.h \
    userui.h

FORMS += \
    addfunction.ui \
    adminui.ui \
    auctionbuygood.ui \
    buyer.ui \
    buygood.ui \
    info.ui \
    launchgood.ui \
    logindlg.ui \
    mainwindow.ui \
    manual.ui \
    modify.ui \
    recharge.ui \
    register.ui \
    remove.ui \
    search.ui \
    seller.ui \
    userui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    myResources.qrc
