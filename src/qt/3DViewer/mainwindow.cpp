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



void MainWindow::on_pushButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите файл", QDir::homePath(), tr( " (*.obj)"));

    ui->label->setText(fileName);
}




void MainWindow::on_pushButton_2_clicked() {
    QString fileName = ui->label->text();
    QByteArray ba = fileName.toLocal8Bit();
    char *str = ba.data();
    vertex = {0, nullptr};
    facet = {0, nullptr};
    int error = 0;
    error = parser(str, &vertex, &facet);
    std::cout << error << std::endl;
    std::cout << str << std::endl;
    ui->widget->setFacets(facet);
    ui->widget->setVertexes(vertex);
    ui->widget->scale = ui->scale->text().toFloat();

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


void MainWindow::on_openTestFile_clicked() {
     ui->label->setText("/Users/violator/C8_3DViewer_v1.0-1/src/cube.obj");
}





void MainWindow::on_openLamp_clicked(){
    ui->label->setText("/Users/violator/C8_3DViewer_v1.0-1/src/lamp.obj");
}

