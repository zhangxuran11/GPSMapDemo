#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include<QPainter>
#include<QDebug>
#include"mappanel.h"
#include <vector>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    SamplesList v;
	v.push_back(GeogPixSample(1991,51,106.805015,-20.675571));
	v.push_back(GeogPixSample(776,2730,100.120199,-6.423076));
	v.push_back(GeogPixSample(861,1414,100.578835,-13.555069));
	v.push_back(GeogPixSample(1743,951,105.426127,-15.991936));
    mapPanel = new MapPanel(GPSMapManager("GPSMap.png",v),this);

    QStringList strList = ui->line_lng->text().split(QChar(','));
    mapPanel->mapMagager.setLng(strList[1].toDouble());
    mapPanel->mapMagager.setLat((strList[0].toDouble()*(-1)));

    mapPanel->resize(800,800);
    mapPanel->show();
}
//void MainWindow::paintEvent(QPaintEvent *)
//{



    //QMainWindow::paintEvent(event);
    //paintMap(ui->widget,QPointF(991,1364),QPointF(102.549829,-13.661392),182.29507,187.793,102.549829,-13.661392);
//}

MainWindow::~MainWindow()
{
    delete ui;
    delete mapPanel;
}
//void MainWindow::paintMap(QPaintDevice *canvas,const QPointF& refPointPix,const QPointF& refPointGeog,double x_lng_factor,double y_lat_factor,double lng,double lat)
//{
//    QImage img("GPSMap.png");

//    QPainter painter;
//    painter.begin(&img);
//    x = (lng-refPointGeog.x())*x_lng_factor+refPointPix.x();
//    y = (lat-refPointGeog.y())*y_lat_factor+refPointPix.y();
//    QPen pen(painter.pen());
//    pen.setWidth(10);
//    pen.setColor(QColor(Qt::red));
//    painter.setPen(pen);
//    //painter.drawText(x,y,"hellow");
//    painter.drawPoint(QPointF(x,y));



//    painter.end();
//    painter.begin(canvas);
//    painter.eraseRect(0,0,canvas->width(),canvas->height());
//    painter.translate(off_x,off_y);
//    painter.scale(scale,scale);
//    painter.drawImage(0,0,img);
//    painter.end();

//}


void MainWindow::on_pushButton_clicked()
{
    QStringList strList = ui->line_lng->text().split(QChar(','));
    mapPanel->mapMagager.setLng(strList[1].toDouble());
    mapPanel->mapMagager.setLat(strList[0].toDouble()*(-1));
    mapPanel->update();

}

void MainWindow::on_btn_up_clicked()
{
    mapPanel->off_y -= 100;
    mapPanel->update();
}

void MainWindow::on_btn_down_clicked()
{
    mapPanel->off_y += 100;
    mapPanel->update();
}

void MainWindow::on_btn_left_clicked()
{
    mapPanel->off_x -= 100;
    mapPanel->update();
}

void MainWindow::on_btn_right_clicked()
{
    mapPanel->off_x += 100;
    mapPanel->update();
}

void MainWindow::on_btn_scale_add_clicked()
{
    mapPanel->scale += 0.1;
    mapPanel->update();
}

void MainWindow::on_btn_scale_sub_clicked()
{
    mapPanel->scale -= 0.1;
    mapPanel->update();
}

void MainWindow::on_push_dw_clicked()
{
    mapPanel->positioning();
}

void MainWindow::on_pushButton_2_clicked()
{
    mapPanel->saveImage(500,500,"./zztest.png");
}
