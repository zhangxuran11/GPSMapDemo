#ifndef GEOGPIXSAMPLE_H
#define GEOGPIXSAMPLE_H
class GPSMapManager;
class GeogPixSample
{
    double pix_x;
    double pix_y;
    double lng;
    double lat;
    double x_lng_factor_upper;
    double y_lat_factor_upper;
    double x_lng_factor_under;
    double y_lat_factor_under;
    friend class GPSMapManager;
public:
    GeogPixSample(){}
    GeogPixSample(double _pix_x,double _pix_y,double _lng,double _lat);
};

#endif // GEOGPIXSAMPLE_H

