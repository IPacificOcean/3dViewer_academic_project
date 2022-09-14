#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "selectcolorbutton.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openFile_clicked()
{
//    ui->widget->vertex = {0, nullptr};
//    ui->widget->facet = {0, nullptr};
    QString file = QFileDialog::getOpenFileName(this, "Выберите файл", ".", tr( " (*.obj)"));
//    ui->pwd->setText(file);
    ui->statusBar->showMessage(file);
//    ui->widget->scale = ui->doubleSpinBox_Scale->text().toDouble();
    QByteArray ba = file.toLocal8Bit();
    char *str = ba.data();
    int error = 0;
    error = parser(str , &ui->widget->vertex, &ui->widget->facet);
//    qDebug() << error;
    if (error) {
        ui->statusBar->showMessage("file not found");
    }


}

void MainWindow::wheelEvent(QWheelEvent *event)
{
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


void MainWindow::on_doubleSpinBox_Scale_valueChanged(double valueScale)

{
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

           ui->widget->rotate.dx = ui->rdx->text().toDouble();
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

