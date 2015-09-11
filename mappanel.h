#ifndef MAPPANEL_H
#define MAPPANEL_H

#include <QWidget>
#include"gpsmapmanager.h"
class MapPanel : public QWidget
{
    Q_OBJECT
    GPSMapManager mapMagager;
    QImage gpsMap;
public:
    int off_x;
    int off_y;
    float scale;
    double lng;
    double lat;

public:
    explicit MapPanel(const QString& mapPath,const GPSMapManager& _mapManager,QWidget *parent = 0);
    void positioning();//定位
signals:
    
public slots:
private:
    void paintEvent(QPaintEvent *);
    
};

#endif // MAPPANEL_H
