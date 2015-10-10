/*
  Copyright (C) 2013 Jolla Ltd.
  Contact: Thomas Perl <thomas.perl@jollamobile.com>
  All rights reserved.

  You may use this file under the terms of BSD license as follows:

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Jolla Ltd nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <QDebug>

#include <sailfishapp.h>
#include <testpainteditem.h>

#include <QApplication>
#include <QUrl>

#include <QtQml/qqml.h>
#include <QImage>
extern "C" {
#include <rfb/rfbclient.h>
}

int main(int argc, char *argv[])
{
    //QApplication app(argc, argv);

    QUrl url("vnc://192.168.2.7");

    QGuiApplication *app = SailfishApp::application(argc, argv);

    app->setOrganizationName("harbour-qtvnc");
    app->setApplicationName("harbour-qtvnc");

    const QImage image(int x = 0, int y = 0, int w = 0, int h = 0);

    rfbClient *cl;

    cl = rfbGetClient(8, 3, 4);


    rfbClientSetClientData(cl, 0, 0);

    QString host("192.168.2.7");

    cl->serverHost = strdup(host.toUtf8().constData());



    qmlRegisterType<testpainteditem>("harbour.qtvnc.testpainteditem", 1, 0, "TestPaintedItem");


    QQuickView *view = SailfishApp::createView();

    QString qml = QString("qml/%1.qml").arg("harbour-qtvnc");
    view->setSource(SailfishApp::pathTo(qml));
    view->show();

    return app->exec();
}

