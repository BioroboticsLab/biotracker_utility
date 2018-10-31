#include "IConfig.h"
#include <QStandardPaths>

QString IConfig::configLocation = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
QString IConfig::dataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

cv::Mat IConfig::asMat(QString str){
    return asMat(str.toStdString());
}

std::vector<std::string> explode(std::string const & s, char delim)
{
	std::vector<std::string> result;
	std::istringstream iss(s);

	for (std::string token; std::getline(iss, token, delim); )
	{
		result.push_back(std::move(token));
	}

	return result;
}

cv::Mat IConfig::asMat(std::string str){
    std::vector<std::string> row = explode(str, ';');
    std::vector<std::string> cols = explode(row[0], '#');

    cv::Mat m(row.size(), cols.size(), CV_32F);

    for (int i = 0; i < row.size(); i++) {
        std::vector<std::string> cols = explode(row[i], '#');
        for (int j = 0; j < cols.size(); j++) {
            m.at<float>(i, j) = std::atof(cols[j].c_str());
        }
    }

    return m;
};


std::string IConfig::asStdString(cv::Mat m){
    return asQString(m).toStdString();
}

QString IConfig::asQString(cv::Mat m){
    std::string result;
    int w = m.size().width;
    int h = m.size().height;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            result += std::to_string(m.at<float>(i, j));
            if (j < w - 1)
                result += "#";
        }
        result += ";";
    }
    return QString(result.c_str());
};

