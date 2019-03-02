#ifndef MODIFIED_SPIDER_H
#define MODIFIED_SPIDER_H
#include <QDebug>
#include <QIcon>
#include <QPixmap>
#include <QWidget>
#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include <QStyle>
#include <QRect>
#include <QPoint>
#include <QCursor>
#include <QBitmap>
#include <QColorDialog>
#include <QFileDialog>
#include <QMouseEvent>
#include <QToolTip>
#include <QPainter>

#include <QWidget>

class modified_spider : public QWidget
{
    Q_OBJECT

public:
    modified_spider(QWidget *parent = 0);
    ~modified_spider();

    bool isDrawing = false;
    QPoint my_point;
    QCursor my_Sword;


    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *) override;

    virtual void mouseReleaseEvent(QMouseEvent *) override;
    virtual void mouseMoveEvent(QMouseEvent *) override;

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *) override;
};

#endif // MODIFIED_SPIDER_H

