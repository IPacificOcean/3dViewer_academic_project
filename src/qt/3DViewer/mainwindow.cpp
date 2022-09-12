#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "glwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_openTestFile_clicked() {
     ui->label->setText("/Users/violator/C8_3DViewer_v1.0-1/src/objFiles/cube.obj");
}


void MainWindow::on_openLamp_clicked(){
    ui->label->setText("/Users/violator/C8_3DViewer_v1.0-1/src/objFiles/lamp.obj");
}


void MainWindow::on_parse_clicked() {
    QString fileName = ui->label->text();
    QByteArray ba = fileName.toLocal8Bit();
    char *str = ba.data();
    int error = 0;
    error = parser(str, &ui->widget->vertex, &ui->widget->facet);

    if(!error) {
        std::cout << error << std::endl;
        std::cout << str << std::endl;
        ui->widget->scale = ui->scale->text().toFloat();
    } else if (error == 1) {
        ui->label->setText("ERROR: File not found");
    }



//    for (unsigned int a = 1; a < vertex.count; a++) {
//        std::cout << vertex.arg_v[a] << "\t";
//        if (a % 3 == 0) {
//           std::cout << std::endl;
//        }
//    }

//    std::cout << std::endl;

//    for (unsigned int a = 1; a < facet.count; a++) {
//        std::cout << facet.arg_f[a] << "\t";
//        if (a % 6 == 0) {
//           std::cout << std::endl;
//        }
//    }

//    for (int a = 0; a < facet.matrix.rows; a++) {
//            for (int b = 0; b <facet.matrix.columns; b++) {
//                std::cout << facets.matrix.matrix[a][b] << "\t";
//            }
//            std::cout << std::endl;
//        }
}


void MainWindow::on_openFile_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите файл", QDir::homePath(), tr( " (*.obj)"));
    ui->label->setText(fileName);
}


void MainWindow::on_apply_clicked(){


    if((ui->dx->text() != "0" ||
        ui->dy->text() != "0" ||
        ui->dz->text() != "0")){

        ui->widget->move.dx = ui->dx->text().toDouble();
        ui->widget->move.dy = ui->dy->text().toDouble();
        ui->widget->move.dz = ui->dz->text().toDouble();
        moveObj(&ui->widget->vertex, ui->widget->move);


        ui->dx->setText("0");
        ui->dy->setText("0");
        ui->dz->setText("0");
    }

    if(ui->scale->text() != "0") {
        ui->widget->scale = ui->scale->text().toFloat();
    }

    if(ui->modelScale->text() != "1" &&
       ui->modelScale->text().toFloat() > 0) {
       ui->widget->modelScale = ui->modelScale->text().toFloat();
       scaleObj(&ui->widget->vertex, ui->widget->modelScale);
       ui->modelScale->setText("1");
    }

    if(ui->rdx->text() != "0" ||
       ui->rdy->text() != "0" ||
       ui->rdz->text() != "0") {

       ui->widget->rotate.dx = ui->rdx->text().toDouble();
       ui->widget->rotate.dy = ui->rdy->text().toDouble();
       ui->widget->rotate.dz = ui->rdz->text().toDouble();
       rotationObj(&ui->widget->vertex, ui->widget->rotate);

       ui->rdx->setText("0");
       ui->rdy->setText("0");
       ui->rdz->setText("0");

    }

}


void MainWindow::on_adaptation_clicked() {

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

      ui->scale->setText(QString::number(scale, 'g', 6));
//    ui->scale->setText(QString::number((maxSize)/10));
//    ui->widget->scale = (xMax - xMin)/640;

}







