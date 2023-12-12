QT       += core gui
QT += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    expensedialog.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    monthlyprefixdialog.cpp \
    reportsdialog.cpp \
    signupdialog.cpp \
    transactionsdialog.cpp

HEADERS += \
    expensedialog.h \
    mainmenu.h \
    mainwindow.h \
    monthlyprefixdialog.h \
    reportsdialog.h \
    signupdialog.h \
    transactionsdialog.h

FORMS += \
    expensedialog.ui \
    mainmenu.ui \
    mainwindow.ui \
    monthlyprefixdialog.ui \
    reportsdialog.ui \
    signupdialog.ui \
    transactionsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
