#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "glviewer.h"


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
    QString file = QFileDialog::getOpenFileName(this, "Выберите файл", QDir::homePath(), tr( " (*.obj)"));
    ui->pwd->setText(file);
//    ui->widget->scale = ui->doubleSpinBox_Scale->text().toDouble();
    QByteArray ba = file.toLocal8Bit();
    char *str = ba.data();
    int error = 0;
    error = parser(str , &ui->widget->vertex, &ui->widget->facet);
//    qDebug() << error;
    if (error) {
        ui->pwd->setText("Not found file");
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




