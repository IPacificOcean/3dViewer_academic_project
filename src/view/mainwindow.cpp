#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //_________SAVE_SETTINGS_________
    save_settings_ = new SaveSettings(this);
//    connect(this, &MainWindow::SaveSettingsSignal, save_settings_, &SaveSettings::SaveSettingsUI);
//    connect(this, &MainWindow::LoadSettingsSignal, save_settings_, &SaveSettings::LoadSettingsUI);
    //_______________________________
//    picture_ = new Media(this);

    //____GIF
    timer_for_gif = new QTimer(0); // parent must be null
    connect(timer_for_gif, SIGNAL(timeout()), this, SLOT(create_screen()));
    //_____
}

MainWindow::~MainWindow() {
    delete ui;
    delete timer_for_gif;
    delete save_settings_;
}


void MainWindow::on_openFile_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "Выберите файл", ".", tr( " (*.obj)"));

    if (file != ""){
    ui->statusBar->showMessage(file);

    std::string input_file = file.toStdString();
    try {
      controller_.OpenFile(input_file);

    } catch(std::exception& e) {
       ui->statusBar->showMessage(e.what());
    }

//    ui->coun_vertexes->setText(QString::number((ui->widget->vertex.count - 3) / 3));
//    ui->count_facets->setText(QString::number(ui->widget->facet.count / 2));
//    ui->filename->setText(file.right(file.size()-file.lastIndexOf("/")-1));
    }
}

void MainWindow::wheelEvent(QWheelEvent *event){
   if (event->angleDelta().y() > 0) {

       ui->widget->change_zoom(0.9);
       ui->doubleSpinBox_Scale->setValue(ui->widget->scale);
   } else {

       ui->widget->change_zoom(1.1);
       ui->doubleSpinBox_Scale->setValue(ui->widget->scale);
   }

}


void MainWindow::on_doubleSpinBox_Scale_valueChanged(double valueScale){
    ui->widget->scale = valueScale;
}


void MainWindow::on_spinBox_line_width_valueChanged(int value) {
    ui->widget->lineWidth = value;
}


void MainWindow::on_spinBox_point_size_valueChanged(int value) {
     ui->widget->pointSize = value;
}


void MainWindow::on_color_clicked() {
    if (ui->colorPoint->isChecked()) {
        ui->widget->colorPoint = QColorDialog::getColor(Qt::gray);
    } else if (ui->colorLine->isChecked()) {
        ui->widget->colorLine = QColorDialog::getColor(Qt::gray);
    } else if (ui->colorBackground->isChecked()) {
        ui->widget->colorWidget = QColorDialog::getColor(Qt::gray);
    }
}

// ________PHOTO ___GIF
void MainWindow::on_Pthoto_clicked() {

//    QFileDialog dialog_photo(this);
//    QString name_photo = dialog_photo.getSaveFileName( this, "Save as...", "photo", "BMP (*.bmp);; JPEG (*.jpeg)");
//    ui->widget->grabFramebuffer().save(name_photo);
    picture_.SavePicture(ui);
}

void MainWindow::on_stop_and_save_GIF_clicked(){

    timer_for_gif->start(100);
    create_screen();

}

void MainWindow::save_gif() {

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save screenshot"), "", tr("GIF screenshot (*.gif);;GIF screenshot (*.gif)"));
    QGifImage gif(QSize(640, 480));

    gif.setDefaultTransparentColor(Qt::black);
    gif.setDefaultDelay(100);

    for (QVector<QImage>::Iterator img = mas_image.begin(); img != mas_image.end(); ++img) {
        gif.addFrame(*img);
    }
    gif.save(fileName);
    mas_image.clear();
    ui->label_Timer_GIF->clear();
    time = 0.0;
}



void MainWindow::create_screen() {

    if ( time <= 5.0) {
        mas_image.push_back(ui->widget->grabFramebuffer());
        time += 0.1;
        ui->label_Timer_GIF->setText(QString::number(time));
    } else if (time >= 5.0) {
        save_gif();
        timer_for_gif->stop();
    }
}

//_________GIF end

void MainWindow::on_optimization_clicked() {
    ui->doubleSpinBox_Scale->setValue(controller_.GetOptimizeScale());
}


void MainWindow::on_comboBox_point_form_currentIndexChanged(int index) {
    ui->widget->pointForm = index;
    ui->widget->update();
}

void MainWindow::on_comboBox_line_form_currentIndexChanged(int index) {
    ui->widget->lineForm = index;
    ui->widget->update();
}


void MainWindow::on_radioButton_frustum_clicked(bool checked) {
    ui->widget->frustum = checked;

}

void MainWindow::on_radioButton_ortho_clicked() {
    ui->widget->frustum = ui->widget->EMPTY;
}

//_________SAVE_AND_LOAD_SETTINGS_________
void MainWindow::on_save_settings_clicked() {
    save_settings();
    QMessageBox::information(this, "Сохранение настроек", "Сохранение настроек выполнено успешно");
}
// try
void MainWindow::save_settings() {
    SaveSettingsSignal(ui);
}

void MainWindow::on_load_setting_clicked() {
  load_settings();
}

void MainWindow::load_settings() {
    LoadSettingsSignal(ui);
}
//________________________________________


//_________AFFINE_TRANSFORMATIONS_________
void MainWindow::on_dx_textChanged() {
    controller_.TransformObject(MOVE, ui->dx->value(), X);
}

void MainWindow::on_dy_textChanged() {
  controller_.TransformObject(MOVE, ui->dy->value(), Y);
}

void MainWindow::on_dz_textChanged() {
  controller_.TransformObject(MOVE, ui->dz->value(), Z);
}

void MainWindow::on_rdx_textChanged() {
  controller_.TransformObject(ROTATE, ui->rdx->value(), X);
}

void MainWindow::on_rdy_textChanged() {
  controller_.TransformObject(ROTATE, ui->rdy->value(), Y);
}

void MainWindow::on_rdz_textChanged() {
  controller_.TransformObject(ROTATE, ui->rdz->value(), Z);
}

void MainWindow::on_modelScale_textChanged() {
  controller_.TransformObject(SCALE, ui->modelScale->value(), {});
}
//________________________________________


















