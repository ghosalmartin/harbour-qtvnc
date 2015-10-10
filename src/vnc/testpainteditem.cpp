#include "testpainteditem.h"

#include <QBrush>
#include <QColor>
#include <QPainter>
#include <QPointF>
#include <QImage>
#include <QRect>
#include <QImageReader>

#include <QDebug>

testpainteditem::testpainteditem(QQuickItem *parent) :
    QQuickPaintedItem(parent)
{
}

void testpainteditem::paint(QPainter *painter)
{

    QImageReader reader("/home/nemo/Pictures/test.jpg");

    QImage source = reader.read();

    QRect rect(source.rect());
    QRect devRect(0,0,painter->device()->width(), painter->device()->height());

    rect.moveCenter(devRect.center());
    painter->drawImage(rect.topLeft(), source);

}
