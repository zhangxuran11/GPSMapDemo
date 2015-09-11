#ifndef GPSMAPMANAGER_H
#define GPSMAPMANAGER_H
#include"geogpixsample.h"
#include<QPointF>
class GPSMapManager
{
    GeogPixSample refPoint;
    double x_lng_factor;
    double y_lat_factor;
public:
    GPSMapManager(){}
    GPSMapManager(const GeogPixSample& mapSample1,const GeogPixSample& mapSample2);
    QPointF geog2pix(double lng,double lat);
};

#endif // GPSMAPMANAGER_H
