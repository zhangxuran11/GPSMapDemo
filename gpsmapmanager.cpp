#include "gpsmapmanager.h"
#include"geogpixsample.h"
#include <cmath>
#include <algorithm>

GPSMapManager::GPSMapManager(const std::vector<GeogPixSample> &_samples)
		:samples(_samples)
{
	
}
QPointF GPSMapManager::geog2pix(double lng,double lat)
{
	const std::vector<GeogPixSample> refPoints = findSample(lng,lat);
	double x_lng_factor = (refPoints[1].pix_x-refPoints[0].pix_x)/(refPoints[1].lng-refPoints[0].lng);
	double y_lat_factor = (refPoints[1].pix_y-refPoints[0].pix_y)/(refPoints[1].lat-refPoints[0].lat);

    double x = refPoints[0].pix_x + (lng - refPoints[0].lng) * x_lng_factor;
    double y = refPoints[0].pix_y + (lat - refPoints[0].lat) * y_lat_factor;
    return QPointF(x,y);
}
const std::vector<GeogPixSample> GPSMapManager::findSample(double lng,double lat)
{
	std::vector<GeogPixSample> v;
	GeogPixSample* sample1 = &samples[0];
	GeogPixSample* sample2 = &samples[1];
	double dist1 = 180,dist2 = 180;
	for(std::vector<GeogPixSample>::iterator it = samples.begin(); it != samples.end(); it++)
	{
		double dist = sqrt(pow(it->lat - lat,2)+pow(it->lng - lng,2));
		if (dist < dist1)
		{
			dist2 = dist1;
			dist1 = dist;
			sample2 = sample1;
			sample1 = &(*it);
		}
		else if(dist < dist2)
		{
			dist2 = dist;
			sample2 = &(*it);
		}
		
	}
	v.push_back(*sample1);
	v.push_back(*sample2);
	return v;
}
