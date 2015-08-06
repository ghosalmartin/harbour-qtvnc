# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = harbour-qtvnc

DEFINES += QTONLY

QT+= widgets

CONFIG += sailfishapp

INCLUDEPATH += \
                src/ \
                src/vnc \
                libvncserver-i486/
                libvncserver-i486/rfb

DEPENDPATH += $$PWD/libvncserver-i486 $$PWD/libvncserver-i486/rfb

LIBS += -lz -L$$PWD/libvncserver-i486/libvncclient/.libs -lvncclient

SOURCES += \
           src/harbour-qtvnc.cpp \
           src/vnc/vncclientthread.cpp \
           src/vnc/vncview.cpp \
           src/vnc/remoteview.cpp

HEADERS += \
           src/vnc/vncclientthread.h \
           src/vnc/vncview.h \
           src/vnc/remoteview.h

OTHER_FILES += qml/harbour-qtvnc.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    qml/pages/SecondPage.qml \
    rpm/harbour-qtvnc.changes.in \
    rpm/harbour-qtvnc.spec \
    rpm/harbour-qtvnc.yaml \
    translations/*.ts \
    harbour-qtvnc.desktop \
    libvncserver-i486/* \
    libvncserver-i486/rfb/* \
    libvncserver-i486/libvncclient/* \
    libvncserver-i486/libvncclient/.libs/* \

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/harbour-qtvnc-de.ts

