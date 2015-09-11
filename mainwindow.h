#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class MapPanel;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    MapPanel* mapPanel;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();

    void on_btn_up_clicked();

    void on_btn_down_clicked();

    void on_btn_left_clicked();

    void on_btn_right_clicked();

    void on_btn_scale_add_clicked();

    void on_btn_scale_sub_clicked();

    void on_push_dw_clicked();

private:
    Ui::MainWindow *ui;

    //void paintEvent(QPaintEvent *);
    //void paintMap(QPaintDevice *canvas,const QPointF& refPointPix,const QPointF& refPointGeog,double x_lon_factor,double y_lan_factor,double longitude,double latitude);
};

#endif // MAINWINDOW_H
