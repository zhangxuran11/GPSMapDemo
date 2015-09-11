#include "mappanel.h"
#include<QPainter>
MapPanel::MapPanel(const QString& mapPath,const GPSMapManager& _mapManager,QWidget *parent) :
    QWidget(parent),gpsMap(mapPath),mapMagager(_mapManager)
{
    off_x = 0;
    off_y = 0;
    scale = 1;
}
void MapPanel::paintEvent(QPaintEvent *)
{
    QImage img("GPSMap.png");

    QPainter painter;
    painter.begin(&img);
    QPen pen(painter.pen());
    pen.setWidth(10);
    pen.setColor(QColor(Qt::red));
    painter.setPen(pen);
    //painter.drawText(x,y,"hellow");
    painter.drawPoint(mapMagager.geog2pix(lng,lat));



    painter.end();
    painter.begin(this);
    painter.eraseRect(0,0,width(),height());
    painter.translate(off_x,off_y);
    painter.scale(scale,scale);
    painter.drawImage(0,0,img);
    painter.end();
}
void MapPanel::positioning()
{
    scale = 1;
    off_x = width()/2 - mapMagager.geog2pix(lng,lat).x();
    off_y = height()/2 - mapMagager.geog2pix(lng,lat).y();
    update();
}
