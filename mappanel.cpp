#include "mappanel.h"
#include<QPainter>
MapPanel::MapPanel(const QString& mapPath,const GPSMapManager& _mapManager,QWidget *parent) :
    QWidget(parent),mapMagager(_mapManager)
{
	this->mapPath = mapPath;
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
    painter.drawImage(0,0,getImage());
    painter.end();
}
void MapPanel::positioning()
{
    scale = 1;
    off_x = width()/2 - mapMagager.geog2pix(lng,lat).x();
    off_y = height()/2 - mapMagager.geog2pix(lng,lat).y();
    update();
}

const QImage& MapPanel::getImage()
{
    mapImage.load(mapPath);

    QPainter painter;
    painter.begin(&mapImage);
    QPen pen(painter.pen());
    pen.setWidth(10);
    pen.setColor(QColor(Qt::red));
    painter.setPen(pen);
    //painter.drawText(x,y,"hellow");
    painter.drawPoint(mapMagager.geog2pix(lng,lat));
    painter.end();
    return mapImage;
}

void MapPanel::saveImage(int width,int height,const QString& toFileName)
{
    QImage img(getImage().copy(mapMagager.geog2pix(lng,lat).x()-width/2,mapMagager.geog2pix(lng,lat).y()-height/2, width,height));
    img.save(toFileName);
}
