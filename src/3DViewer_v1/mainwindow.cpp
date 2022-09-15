#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "selectcolorbutton.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //____GIF
    timer_for_gif = new QTimer(0); // parent must be null
    connect(timer_for_gif, SIGNAL(timeout()), this, SLOT(create_screen()));
    //_____

}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer_for_gif;
}


void MainWindow::on_openFile_clicked(){

    QString file = QFileDialog::getOpenFileName(this, "Выберите файл", ".", tr( " (*.obj)"));
    ui->statusBar->showMessage(file);
    QByteArray ba = file.toLocal8Bit();
    char *str = ba.data();
    int error = 0;
    error = parser(str , &ui->widget->vertex, &ui->widget->facet);
//    qDebug() << error;
    if (error) {
        ui->statusBar->showMessage("file not found");
    }

    ui->coun_vertexes->setText(QString::number(ui->widget->vertex.count));
    ui->count_facets->setText(QString::number(ui->widget->facet.count));
    ui->filename->setText(file.right(file.size()-file.lastIndexOf("/")-1));
}

void MainWindow::wheelEvent(QWheelEvent *event){
   if (event->angleDelta().y() > 0) {

       ui->widget->change_zoom(0.9);
//       ui->doubleSpinBox_Scale->setValue(ui->widget->scale < 1.0 ? (-1.0 / ui->widget->scale) : ui->widget->scale);
       ui->doubleSpinBox_Scale->setValue(ui->widget->scale);
   } else {

       ui->widget->change_zoom(1.1);
//       ui->doubleSpinBox_Scale->setValue(ui->widget->scale < 1.0 ? (-1.0 / ui->widget->scale) : ui->widget->scale);
       ui->doubleSpinBox_Scale->setValue(ui->widget->scale);
   }

}


void MainWindow::on_doubleSpinBox_Scale_valueChanged(double valueScale){
//    std::cout<<valueScale<<std::endl;
//    ui->widget->scale = ui->doubleSpinBox_Scale->value();
    ui->widget->scale = valueScale;
    qDebug() << valueScale;
}







void MainWindow::on_update_clicked()
{
    if((ui->dx->text() != "0" ||
            ui->dy->text() != "0" ||
            ui->dz->text() != "0")){

            ui->widget->move.dx = ui->dx->text().toDouble();
            ui->widget->move.dy = ui->dy->text().toDouble();
            ui->widget->move.dz = ui->dz->text().toDouble();
            moveObj(&ui->widget->vertex, ui->widget->move);


//            ui->dx->setText("0");
//            ui->dy->setText("0");
//            ui->dz->setText("0");
        }

//        if(ui->scale->text() != "0") {
//            ui->widget->scale = ui->scale->text().toDouble();
//        }

        if(ui->modelScale->text() != "1" &&
           ui->modelScale->value() > 0) {
           ui->widget->modelScale = ui->modelScale->value();
           scaleObj(&ui->widget->vertex, ui->widget->modelScale);
//           ui->modelScale->setText("1");
        }

        if(ui->rdx->text() != "0" ||
           ui->rdy->text() != "0" ||
           ui->rdz->text() != "0") {

           ui->widget->rotate.dx = ui->rdx->value();
           ui->widget->rotate.dy = ui->rdy->text().toDouble();
           ui->widget->rotate.dz = ui->rdz->text().toDouble();
           rotationObj(&ui->widget->vertex, ui->widget->rotate);

//           ui->rdx->setText("0");
//           ui->rdy->setText("0");
//           ui->rdz->setText("0");



        }

}


void MainWindow::on_spinBox_line_width_valueChanged(int value)
{
    ui->widget->lineWidth = value;
}


void MainWindow::on_spinBox_point_size_valueChanged(int value)
{
     ui->widget->pointSize = value;
}


void MainWindow::on_color_clicked()
{
    if (ui->colorPoint->isChecked()) {
        ui->widget->colorPoint = QColorDialog::getColor(Qt::gray);
    } else if (ui->colorLine->isChecked()) {
        ui->widget->colorLine = QColorDialog::getColor(Qt::gray);
    } else if (ui->colorBackground->isChecked()) {
        ui->widget->colorWidget = QColorDialog::getColor(Qt::gray);
    }
}

// ________PHOTO ___GIF
void MainWindow::on_Pthoto_clicked()
{
      QFileDialog file_dialog_photo(this);
      QString f_name_photo =
          file_dialog_photo.getSaveFileName(this,"Save as...", QDir::currentPath(), "BMP (*.bmp);; JPEG (*.jpeg)");
      QFile file(f_name_photo);
      file.open(QIODevice::WriteOnly);
      QRect rect(0, 0, ui->widget->width(), ui->widget->height());
      QPixmap pixmap = ui->widget->grab(rect);
      pixmap.copy(rect);
      pixmap.toImage().save(&file, "jpg");
      QString q_command_line = "open " + f_name_photo;
      QByteArray temp = q_command_line.toLocal8Bit();
      char *command_line = temp.data();
      system(command_line);
}


void MainWindow::on_stop_and_save_GIF_clicked(){

    timer_for_gif->start(100);
    create_screen();

}

void MainWindow::save_gif() {

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save screenshot"), "", tr("GIF screenshot (*.gif);;GIF screenshot (*.gif)"));
    QGifImage gif(QSize(640, 480));

    gif.setDefaultTransparentColor(Qt::black);
//    gif.setDefaultDelay(100);

    for (QVector<QImage>::Iterator img = mas_image.begin(); img != mas_image.end(); ++img) {
        gif.addFrame(*img);

    }

    gif.save(fileName);
    mas_image.clear();
    ui->label_Timer_GIF->clear();
    time = 0.0;

}



void MainWindow::create_screen()
{
    if ( time <= 5.0) {
        mas_image.push_back(ui->widget->grab().toImage());
        time += 0.1;
        ui->label_Timer_GIF->setText(QString::number(time));
    } else if (time >= 5.0) {
        save_gif();
        timer_for_gif->stop();
    }
}

// test violator

//_________GIF end

// Test

void MainWindow::on_optimization_clicked(){
    double xMax = 0;
    double xMin = 0;
    double yMax = 0;
    double yMin = 0;
    double zMax = 0;
    double zMin = 0;
    double maxSize = 0;
    double scale = 100;

    for (unsigned int var = 3; var < ui->widget->vertex.count; var += 3) {

        if(ui->widget->vertex.arg[var] > xMax) xMax = ui->widget->vertex.arg[var];
        if(ui->widget->vertex.arg[var] < xMin) xMin = ui->widget->vertex.arg[var];
        if(ui->widget->vertex.arg[var+1] > yMax) yMax = ui->widget->vertex.arg[var];
        if(ui->widget->vertex.arg[var+1] < yMin) yMin = ui->widget->vertex.arg[var];
        if(ui->widget->vertex.arg[var+2] > zMax) zMax = ui->widget->vertex.arg[var];
        if(ui->widget->vertex.arg[var+2] < zMin) zMin = ui->widget->vertex.arg[var];
    }
    maxSize = xMax - xMin;
    if (maxSize < yMax - yMin) maxSize = yMax - yMin;
    if (maxSize < zMax - zMin) maxSize = zMax - zMin;


    while(maxSize * scale > 1 && scale > 0.0001) {
        scale *= 0.9;
    }

      ui->doubleSpinBox_Scale->setValue(scale);
}










