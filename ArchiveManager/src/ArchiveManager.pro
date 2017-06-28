#-------------------------------------------------
#
# Project created by QtCreator 2017-04-02T10:32:48
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ArchiveManager
TEMPLATE = app

LIBS += -lws2_32

INCLUDEPATH += $$PWD

RESOURCES += \
    ../res/resources.qrc

RC_FILE += \
    ../res/archive_manager.rc

DISTFILES += \
    ../res/archive_manager.rc

FORMS += \
    mainfrm.ui \
    common/sdialog.ui \
    common/ssqltablefrm.ui \
    sys/changepasswordfrm.ui \
    sys/loginfrm.ui \
    sys/netconfigfrm.ui \
    aj/ajdetailsfrm.ui \
    gdwj/gdwjdetailsfrm.ui \
    jnwj/jnwjdetailsfrm.ui \
    qz/qzdetailsfrm.ui \
    qz/createqzfrm.ui \
    qz/searchqzfrm.ui \
    aj/createajfrm.ui \
    aj/searchajfrm.ui \
    gdwj/creategdwjfrm.ui \
    gdwj/searchgdwjfrm.ui \
    jnwj/createjnwjfrm.ui \
    jnwj/searchjnwjfrm.ui \
    log/searchlogfrm.ui

HEADERS += \
    MainDlg.h \
    aj/ajadddlg.h \
    aj/ajkeydlg.h \
    aj/ajsqltablefrm.h \
    aj/ajsqltablemodel.h \
    common/archivecontenttreewidget.h \
    common/clientsocket.h \
    common/dbhandler.h \
    common/dbtypes.h \
    common/deletebuttoncombobox.h \
    common/guidetreewidget.h \
    common/iniloader.h \
    common/sdialog.h \
    common/ssqltablefrm.h \
    common/ssqltablemodel.h \
    gdwj/gdwjadddlg.h \
    gdwj/gdwjkeydlg.h \
    gdwj/gdwjsqltablefrm.h \
    gdwj/gdwjsqltablemodel.h \
    jnwj/jnwjadddlg.h \
    jnwj/jnwjkeydlg.h \
    jnwj/jnwjsqltablefrm.h \
    jnwj/jnwjsqltablemodel.h \
    log/logsqltablefrm.h \
    log/logsqltablemodel.h \
    qz/qzadddlg.h \
    qz/qzkeydlg.h \
    qz/qzsqltablefrm.h \
    qz/qzsqltablemodel.h \
    sys/changepassworddlg.h \
    sys/LoginDlg.h \
    sys/loginthread.h \
    sys/netconfigdlg.h \
    aj/ajdetailsfrm.h \
    gdwj/gdwjdetailsfrm.h \
    jnwj/jnwjdetailsfrm.h \
    qz/qzdetailsfrm.h \
    qz/createqzfrm.h \
    qz/searchqzfrm.h \
    aj/createajfrm.h \
    aj/searchajfrm.h \
    gdwj/creategdwjfrm.h \
    gdwj/searchgdwjfrm.h \
    jnwj/createjnwjfrm.h \
    jnwj/searchjnwjfrm.h \
    log/searchlogfrm.h

SOURCES += \
    main.cpp \
    maindlg.cpp \
    aj/ajadddlg.cpp \
    aj/ajkeydlg.cpp \
    aj/ajsqltablefrm.cpp \
    aj/ajsqltablemodel.cpp \
    common/archivecontenttreewidget.cpp \
    common/clientsocket.cpp \
    common/dbhandler.cpp \
    common/dbtypes.cpp \
    common/deletebuttoncombobox.cpp \
    common/guidetreewidget.cpp \
    common/iniloader.cpp \
    common/sdialog.cpp \
    common/ssqltablefrm.cpp \
    common/ssqltablemodel.cpp \
    gdwj/gdwjadddlg.cpp \
    gdwj/gdwjkeydlg.cpp \
    gdwj/gdwjsqltablefrm.cpp \
    gdwj/gdwjsqltablemodel.cpp \
    jnwj/jnwjadddlg.cpp \
    jnwj/jnwjkeydlg.cpp \
    jnwj/jnwjsqltablefrm.cpp \
    jnwj/jnwjsqltablemodel.cpp \
    log/logsqltablefrm.cpp \
    log/logsqltablemodel.cpp \
    qz/qzadddlg.cpp \
    qz/qzkeydlg.cpp \
    qz/qzsqltablefrm.cpp \
    qz/qzsqltablemodel.cpp \
    sys/changepassworddlg.cpp \
    sys/logindlg.cpp \
    sys/loginthread.cpp \
    sys/netconfigdlg.cpp \
    aj/ajdetailsfrm.cpp \
    gdwj/gdwjdetailsfrm.cpp \
    jnwj/jnwjdetailsfrm.cpp \
    qz/qzdetailsfrm.cpp \
    qz/createqzfrm.cpp \
    qz/searchqzfrm.cpp \
    aj/createajfrm.cpp \
    aj/searchajfrm.cpp \
    gdwj/creategdwjfrm.cpp \
    gdwj/searchgdwjfrm.cpp \
    jnwj/createjnwjfrm.cpp \
    jnwj/searchjnwjfrm.cpp \
    log/searchlogfrm.cpp


