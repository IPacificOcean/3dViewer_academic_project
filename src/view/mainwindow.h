#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "glviewer.h"
#include <QColorDialog>

#include <QMessageBox>
#include <QMovie>
#include "../controller/controller.h"


//_________SAVE_SETTINGS_________
#include "save_settings.h"
//_______________________________


//_________GIF
//#include <QLabel>
//#include <QPixmap>
//#include <QScreen>
//#include <vector>
//#include <cstdint>
//#include <QTimer>
//#include <QSettings>
//#include <QTextEdit>
//#include <math.h>
//#include "QtGifImage-master/src/gifimage/qgifimage.h"
//#include <QPainter>
//#include <QImage>

#include "media.h"
//__________________


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  //___ GIF
//  QVector<QImage> mas_image;
  //____
//try
  //_________SAVE_AND_LOAD_SETTINGS_________
  signals:
  //________________________________________


 private
  slots:

  void on_openFile_clicked();

  void on_doubleSpinBox_Scale_valueChanged(double valueScale);

//  void on_update_clicked();

  void on_spinBox_line_width_valueChanged(int value);

  void on_spinBox_point_size_valueChanged(int value);

  void on_color_clicked();

  //_______GIF
  void on_Pthoto_clicked();

//  void create_screen();

  void on_stop_and_save_GIF_clicked();

//  void save_gif();
  //_______

  void on_optimization_clicked();

  void on_comboBox_point_form_currentIndexChanged(int index);

  void on_comboBox_line_form_currentIndexChanged(int index);

  void on_radioButton_frustum_clicked(bool checked);

  void on_radioButton_ortho_clicked();





  //_________AFFINE_TRANSFORMATIONS_________
  void on_dx_textChanged();
  void on_dy_textChanged();
  void on_dz_textChanged();
  void on_rdx_textChanged();
  void on_rdy_textChanged();
  void on_rdz_textChanged();
  void on_modelScale_textChanged();
  //________________________________________

  //_________SAVE_AND_LOAD_SETTINGS_________
  void on_save_settings_clicked();
  void on_load_setting_clicked();
  //________________________________________




  private:
  Ui::MainWindow *ui;
  void wheelEvent(QWheelEvent *event) override;
  s21::Controller controller_;

  //_________SAVE_AND_LOAD_SETTINGS_________
  SaveSettings save_settings_;
  void save_settings();
  void load_settings();
  void SaveSettingsSignal(Ui::MainWindow *ui) {
        save_settings_.SaveSettingsUI(ui);
  };
  void LoadSettingsSignal(Ui::MainWindow *ui) {
      save_settings_.LoadSettingsUI(ui);
  };
  //________________________________________

  //_____Photo
  Media picture_;

  //_____GIF

//  QTimer *timer;
//  QTimer *timer_for_gif;
////  QThread *somethread;
//  double time = 0;
////  int xyz = 1;
//  int flag_record = 0;
  //_______



};
#endif // MAINWINDOW_H
