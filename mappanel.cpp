#include "mappanel.h"
#include<QPainter>
MapPanel::MapPanel(const GPSMapManager& _mapManager,QWidget *parent) :
    QWidget(parent),mapMagager(_mapManager)
{
    off_x = 0;
    off_y = 0;
    scale = 1;
}
void MapPanel::paintEvent(QPaintEvent *)
{

    QPainter painter;
    painter.begin(this);
    painter.eraseRect(0,0,width(),height());
    painter.translate(off_x,off_y);
    painter.scale(scale,scale);
    painter.drawImage(0,0,mapMagager.getImage());
    painter.end();
}
void MapPanel::positioning()
{
    scale = 1;
    off_x = width()/2 - mapMagager.geog2pix(mapMagager.getLng(),mapMagager.getLat()).x();
    off_y = height()/2 - mapMagager.geog2pix(mapMagager.getLng(),mapMagager.getLat()).y();
    update();
}



void MapPanel::saveImage(int width,int height,const QString& toFileName)
{
    mapMagager.saveImage(width,height,toFileName);
}
