#pragma once
#include <QString>
#include <cv.h>
class IConfig 
{
public:
    static QString configLocation;
    static QString dataLocation;

    virtual void load(QString dir, QString file = "sampleConfig.ini") = 0;
    virtual void save(QString dir, QString file) = 0;

    static cv::Mat asMat(QString str);
    static cv::Mat asMat(std::string str);
    static std::string asStdString(cv::Mat m);
    static QString asQString(cv::Mat m);

};
