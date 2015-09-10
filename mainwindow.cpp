#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QImage"
#include<QPainter>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->setAttribute(Qt::WA_PaintOutsidePaintEvent);
    off_x = 0;
    off_y = 0;
    scale = 1;
}
void MainWindow::paintEvent(QPaintEvent *)
{



    //QMainWindow::paintEvent(event);
    //paintMap(ui->widget,QPointF(991,1364),QPointF(102.549829,-13.661392),182.29507,187.793,102.549829,-13.661392);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintMap(QPaintDevice *canvas,const QPointF& refPointPix,const QPointF& refPointGeog,double x_lng_factor,double y_lat_factor,double lng,double lat)
{
    QImage img("GPSMap.png");

    QPainter painter;
    painter.begin(&img);
    x = (lng-refPointGeog.x())*x_lng_factor+refPointPix.x();
    y = (lat-refPointGeog.y())*y_lat_factor+refPointPix.y();
    QPen pen(painter.pen());
    pen.setWidth(10);
    pen.setColor(QColor(Qt::red));
    painter.setPen(pen);
    //painter.drawText(x,y,"hellow");
    painter.drawPoint(QPointF(x,y));



    painter.end();
    painter.begin(canvas);
    painter.eraseRect(0,0,canvas->width(),canvas->height());
    painter.translate(off_x,off_y);
    painter.scale(scale,scale);
    painter.drawImage(0,0,img);
    painter.end();

}

void MainWindow::on_pushButton_clicked()
{
    paintMap(ui->widget,QPointF(734,2851),QPointF(101.133644, -5.613406 ),182.331533771,187.7879418,ui->line_lng->text().toDouble(),ui->line_lat->text().toDouble());
}

void MainWindow::on_btn_up_clicked()
{
    off_y -= 100;
    paintMap(ui->widget,QPointF(734,2851),QPointF(101.133644, -5.613406 ),182.331533771,187.7879418,ui->line_lng->text().toDouble(),ui->line_lat->text().toDouble());
}

void MainWindow::on_btn_down_clicked()
{
    off_y += 100;
    paintMap(ui->widget,QPointF(734,2851),QPointF(101.133644, -5.613406 ),182.331533771,187.7879418,ui->line_lng->text().toDouble(),ui->line_lat->text().toDouble());
}

void MainWindow::on_btn_left_clicked()
{
    off_x -= 100;
    paintMap(ui->widget,QPointF(734,2851),QPointF(101.133644, -5.613406 ),182.331533771,187.7879418,ui->line_lng->text().toDouble(),ui->line_lat->text().toDouble());
}

void MainWindow::on_btn_right_clicked()
{
    off_x += 100;
   paintMap(ui->widget,QPointF(734,2851),QPointF(101.133644, -5.613406 ),182.331533771,187.7879418,ui->line_lng->text().toDouble(),ui->line_lat->text().toDouble());
}

void MainWindow::on_btn_scale_add_clicked()
{
    scale += 0.1;
    paintMap(ui->widget,QPointF(734,2851),QPointF(101.133644, -5.613406 ),182.331533771,187.7879418,ui->line_lng->text().toDouble(),ui->line_lat->text().toDouble());
}

void MainWindow::on_btn_scale_sub_clicked()
{
    scale -= 0.1;
    paintMap(ui->widget,QPointF(734,2851),QPointF(101.133644, -5.613406 ),182.331533771,187.7879418,ui->line_lng->text().toDouble(),ui->line_lat->text().toDouble());
}

void MainWindow::on_push_dw_clicked()
{

    off_x = ui->widget->width()/2 - x;
    off_y = ui->widget->height()/2 - y;
    paintMap(ui->widget,QPointF(734,2851),QPointF(101.133644, -5.613406 ),182.331533771,187.7879418,ui->line_lng->text().toDouble(),ui->line_lat->text().toDouble());
}
