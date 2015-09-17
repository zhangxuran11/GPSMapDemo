#ifndef MAPPANEL_H
#define MAPPANEL_H

#include <QWidget>
#include<QString>
#include"gpsmapmanager.h"
class MapPanel : public QWidget
{
    Q_OBJECT

public:
    int off_x;
    int off_y;
    float scale;
    GPSMapManager mapMagager;
public:
    explicit MapPanel(const GPSMapManager& _mapManager,QWidget *parent = 0);
    void positioning();//定位
    void saveImage(int width,int height,const QString& toFileName);
signals:
    
public slots:
private:
    void paintEvent(QPaintEvent *);
    const QImage& getImage();

    
};

#endif // MAPPANEL_H
