#include "modified_spider.h"

modified_spider::modified_spider(QWidget *parent)
    : QWidget(parent)
{

    Qt::WindowFlags myflags;
    myflags = Qt::CustomizeWindowHint;

    this->setWindowFlags(myflags);

    myflags |= Qt::WindowCloseButtonHint;

    this->setWindowFlags(myflags);

    myflags |= Qt::WindowMinMaxButtonsHint;

    this->setWindowFlags(myflags);

    //Qt::WindowStates mystate = this->windowState();

    this->setWindowState(Qt::WindowNoState);

    QString mytitle = "asdfads";
    this->setWindowTitle(mytitle);

    QString myname = QObject::tr("Choose Inactice Back Color");

    QPalette mypalette;
    QColor call = QColorDialog::getColor(Qt::white, Q_NULLPTR, myname, Q_NULLPTR);

    if(call.isValid())
    {
        mypalette.setColor(QPalette::Inactive, QPalette::Window, call/*QColor(65,105,225)*/);
    }
    else
    {
        mypalette.setColor(QPalette::Inactive, QPalette::Window, QColor(65,105,225));
    }
    this->setPalette(mypalette);

    QString Activve_pic = QObject::tr("Picture of Active State of Window");
    //QStyle?????????????
    QString chosen_file = QFileDialog::getOpenFileName(Q_NULLPTR, Activve_pic, "./Images_lab1", Q_NULLPTR, Q_NULLPTR, Q_NULLPTR);

    if (chosen_file.isEmpty())
    {
        QPixmap myPic("./Images_lab1/13.jpg");
        QBrush myBrushWorking(myPic);
        mypalette.setBrush(QPalette::Active, QPalette::Window, myBrushWorking);
    }
    else
    {
        QPixmap myPic(chosen_file);
        QBrush myBrushWorking(myPic);
        mypalette.setBrush(QPalette::Active, QPalette::Window, myBrushWorking);
    }

    this->setPalette(mypalette);
    this->setWindowOpacity(0.95);
    this->setGeometry(25, 45, 800, 450);
    this->move(50, 150);
    this->setMinimumSize(750, 400);
    this->setMaximumSize(1000, 625);
    QPixmap pixCursor("./Images_lab1/cursor4.bmp");
    pixCursor.setMask(QBitmap("./Images_lab1/cursor4.bmp"));

    my_Sword = QCursor(pixCursor);
    this->setCursor(my_Sword);

    //начинается 2 лаба

}

modified_spider::~modified_spider()
{

}

void modified_spider::mousePressEvent(QMouseEvent * moimausivent)
{
    if (moimausivent->buttons() == Qt::LeftButton && moimausivent->modifiers())
    {        
        if (moimausivent->modifiers() == Qt::ControlModifier)
        {
            QString txt = "x = ";
            QString txt2 = ", y = ";
            QString my_x;
            my_x.setNum(moimausivent->x());

            QString my_y;
            my_y.setNum(moimausivent->y());

            txt = txt + my_x + txt2 + my_y;

            QToolTip::showText(moimausivent->globalPos(), txt);
        }
        else if (moimausivent->modifiers() == Qt::ShiftModifier)
        {
            QString txt = " - my Local Position";
            QToolTip::showText(moimausivent->localPos().toPoint(), txt);
        }
    }
}

void modified_spider::mouseReleaseEvent(QMouseEvent *)
{
   isDrawing = false;
   this->repaint();
}

void modified_spider::mouseMoveEvent(QMouseEvent * mymouseevent)
{
    if(this->rect().contains(mymouseevent->localPos().toPoint()))
    {
        this->setCursor(my_Sword);
        if(mymouseevent->buttons() == Qt::RightButton)
        {
            modified_spider::isDrawing = true;
            my_point = mymouseevent->localPos().toPoint();
            this->repaint();
        }
    }
    else
    {
        this->unsetCursor();
    }
}

void modified_spider::paintEvent(QPaintEvent *)
{
    if(isDrawing)
    {
        QPainter mypainter(this);
        mypainter.setPen(QColor(0, 80, 80));

        QRect myRect = this->rect();
        for (int i = myRect.topLeft().x(); i < myRect.topRight().x(); i+= 20)
        {
            mypainter.drawLine(i, 0, my_point.x(), my_point.y());
            mypainter.drawLine(i, myRect.bottomLeft().y(), my_point.x(), my_point.y());
        }

        for (int i = myRect.topLeft().y(); i < myRect.bottomLeft().y(); i+= 20)
        {
            mypainter.drawLine(0, i, my_point.x(), my_point.y());
            mypainter.drawLine(myRect.topRight().x(), i, my_point.x(), my_point.y());
        }
    }
}
