#ifndef GPSMAPMANAGER_H
#define GPSMAPMANAGER_H
#include"geogpixsample.h"
#include<QPointF>
#include<vector>
class GPSMapManager
{
    std::vector<GeogPixSample> samples;
public:
    GPSMapManager(){}
    GPSMapManager(const std::vector<GeogPixSample> &_samples);
    GeogPixSample find(double lng,double lat);
    QPointF geog2pix(double lng,double lat);
private:
	const std::vector<GeogPixSample> findSample(double lng,double lat);
};

#endif // GPSMAPMANAGER_H
