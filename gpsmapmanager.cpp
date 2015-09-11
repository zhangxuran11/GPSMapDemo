#include "gpsmapmanager.h"
#include"geogpixsample.h"

GPSMapManager::GPSMapManager(const GeogPixSample& mapSample1,const GeogPixSample& mapSample2)
{

    x_lng_factor = (mapSample2.pix_x - mapSample1.pix_x) / (mapSample2.lng - mapSample1.lng);
    y_lat_factor = (mapSample2.pix_y - mapSample1.pix_y) / (mapSample2.lat - mapSample1.lat);
    refPoint = mapSample1;
}
QPointF GPSMapManager::geog2pix(double lng,double lat)
{
    double x = refPoint.pix_x + (lng - refPoint.lng) * x_lng_factor;
    double y = refPoint.pix_y + (lat - refPoint.lat) * y_lat_factor;
    return QPointF(x,y);
}
