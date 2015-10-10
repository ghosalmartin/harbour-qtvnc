#ifndef TESTPAINTEDITEM_H
#define TESTPAINTEDITEM_H

#include <QQuickPaintedItem>
#include <QImage>
class testpainteditem : public QQuickPaintedItem
{
    Q_OBJECT
public:
    explicit testpainteditem(QQuickItem *parent = 0);
    void paint(QPainter *painter);

signals:

public slots:

};

#endif // TESTPAINTEDITEM_H
