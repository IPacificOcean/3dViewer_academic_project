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

//_________GIF_PHOTO_SAVE________
#include "media.h"
//_______________________________


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private
  slots:

  void on_openFile_clicked();

  void on_doubleSpinBox_Scale_valueChanged(double valueScale);

//  void on_update_clicked();

  void on_spinBox_line_width_valueChanged(int value);

  void on_spinBox_point_size_valueChanged(int value);

  void on_color_clicked();

  //_________GIF_PHOTO_SAVE________
  void on_Pthoto_clicked();

  void on_stop_and_save_GIF_clicked();

  //_______________________________

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

  //_________GIF_PHOTO_SAVE________
  Media* picture_;
  //_______________________________

};
#endif // MAINWINDOW_H
