#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "glviewer.h"
#include <QColorDialog>

//_________GIF
#include <Qlabel>
#include <QPixmap>
#include <QScreen>
#include <vector>
#include <cstdint>
#include <QTimer>
#include <QSettings>
#include <QTextEdit>
#include <math.h>
#include "QtGifImage-master/src/gifimage/qgifimage.h"
#include <QPainter>
#include <QImage>
//__________________


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //___ GIF
    QVector<QImage> mas_image;
    //____

private slots:
    void on_openFile_clicked();


    void on_doubleSpinBox_Scale_valueChanged(double valueScale);




    void on_update_clicked();

    void on_spinBox_line_width_valueChanged(int value);

    void on_spinBox_point_size_valueChanged(int value);


    void on_color_clicked();

    //_______GIF
    void on_Pthoto_clicked();

    void create_screen();

    void on_stop_and_save_GIF_clicked();

    void save_gif();
    //_______

private:
    Ui::MainWindow *ui;
    void wheelEvent(QWheelEvent *event) override;

    //_____GIF
    QTimer *timer;
    QTimer *timer_for_gif;
    QThread* somethread;
    double time = 0;
    int xyz = 1;
    int flag_record = 0;
    //_-----
};
#endif // MAINWINDOW_H
