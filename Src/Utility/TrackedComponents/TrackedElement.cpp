#include "TrackedElement.h"
#include "QDebug"
#include "QRect"
#include "QBrush"
#include "QPainter"

TrackedElement::TrackedElement(QObject* parent, QString name, int id)
: IModelTrackedPoint(parent)
, _name(name)
, _id(id)
{
    _x      = 0;
    _y      = 0;
    _xpx    = 0;
    _xpx    = 0;
    _valid  = false;
    _fixed  = false;
    _coordU = "px";
}

QString TrackedElement::getName()
{
    return _name;
}

void TrackedElement::setPoint(cv::Point2f p)
{
    _x     = p.x;
    _y     = p.y;
    _valid = true;
    Q_EMIT notifyView();
}

cv::Point2f TrackedElement::getPoint()
{
    return cv::Point2f(_x, _y);
}

void TrackedElement::setX(float val)
{
    _x = val;
};

void TrackedElement::setY(float val)
{
    _y = val;
};

void TrackedElement::setXpx(float val)
{
    _xpx = val;
};

void TrackedElement::setYpx(float val)
{
    _ypx = val;
};

float TrackedElement::getX()
{
    return _x;
}

float TrackedElement::getY()
{
    return _y;
}

float TrackedElement::getXpx()
{
    return _xpx;
}

float TrackedElement::getYpx()
{
    return _ypx;
}

void TrackedElement::operate()
{
    qDebug() << "I am TrackedElement " << _name;
}
