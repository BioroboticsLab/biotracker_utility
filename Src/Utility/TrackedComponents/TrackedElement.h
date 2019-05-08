#pragma once

#include "QGraphicsItem"
#include "Interfaces/IModel/IModelTrackedComponent.h"
#include "QString"
#include <cv.h>
#include <qdatetime.h>
#include <ctime>

/**
* This class is an example of how a TrackedComponent could be defined.
* This class inherits from the IModelTrackedComponent class and is therefor part of the Composite Pattern.
* This class represents the Leaf class in the Composite Pattern.
* Objects of this class have a QObject as parent.
*/
class TrackedElement : public IModelTrackedPoint
{
	Q_OBJECT

public:
	TrackedElement(QObject *parent = 0, QString name = "n.a.", int id = 0);
    virtual ~TrackedElement() {};

	virtual QString getName();
    virtual QString getCoordinateUnit() override { return _coordU; };
    
    virtual void setCoordinateUnit(QString unit) override { _coordU = unit; };

    virtual void  setX(float val) override;
    virtual void  setY(float val) override;
    virtual void  setW(float w) override {};
    virtual void  setH(float h) override {};
    virtual void  setXpx(float val) override;
    virtual void  setYpx(float val) override;
    virtual void  setWpx(float w) override {};
    virtual void  setHpx(float h) override {};
	virtual void  setRad(float r) override {};
	virtual void  setDeg(float d)  override{};
	virtual void  setId(int val) override { _id = val; };
    virtual void  setTime(std::chrono::system_clock::time_point t) {
        _timeSysclck = t;
    };
    virtual void  setTime(qint64 t) override {
        std::string::size_type sz = 0;
        long long ll = t / 1000;
        std::time_t tm(ll);
        _timeSysclck = std::chrono::system_clock::from_time_t(tm);
    };
    virtual void  setTimeString(QString t) override { _timeString = t; };
	virtual void  setValid(bool v) override { _valid = v; };
	virtual void  setFixed(bool f) override { _fixed = f; };

    virtual float getX() override;
    virtual float getY() override;
    virtual float getXpx() override;
    virtual float getYpx() override;
    virtual float getW() override { return 0; };
    virtual float getH() override { return 0; };
    virtual float getWpx() override { return 0; };
    virtual float getHpx() override { return 0; };
	virtual float getRad() override { return 0; };
	virtual float getDeg() override { return 0; };
	virtual int   getId() override { return _id; };
    virtual qint64  getTime() override {
        qint64 q(std::chrono::duration_cast<std::chrono::milliseconds>(_timeSysclck.time_since_epoch()).count());
        return q;
    };
    virtual QString getTimeString() override {
        std::time_t t = std::chrono::system_clock::to_time_t(_timeSysclck);
        QDateTime dt;
        dt.setTime_t(t);
        _timeString = dt.toString();
        return _timeString;
    };
	virtual bool  getValid() override { return _valid; };
	virtual bool  getFixed() override { return _fixed; };

	virtual bool hasX() override { return true; };
	virtual bool hasY() override { return true; };
	virtual bool hasW() override { return false; };
	virtual bool hasH() override { return false; };
    virtual bool hasXpx() override { return false; };
    virtual bool hasYpx() override { return false; };
    virtual bool hasWpx() override { return false; };
    virtual bool hasHpx() override { return false; };
	virtual bool hasRad() override { return false; };
	virtual bool hasDeg() override { return false; };
	virtual bool hasTime() override { return true; };
    virtual bool hasTimeString() override { return true; };

	virtual void setPoint(cv::Point2f p);
    virtual cv::Point2f getPoint();

	// ITrackedPoint interface
public:
	void operate();

private:
    std::chrono::system_clock::time_point _timeSysclck;
	QString _name;
    QString _timeString;                         /**< timestamp a formatted as string */
	float _x;
	float _y;
    float _xpx;
    float _ypx;
	int _id;
	bool _valid;
	bool _fixed;
    QString _coordU;
};

