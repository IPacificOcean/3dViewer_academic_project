#include "mainwindow.h"
#include "ui_mainwindow.h"


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



void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите файл", QDir::homePath(), tr( " (*.obj)"));

    ui->label->setText(fileName);



}


void MainWindow::on_pushButton_2_clicked()
{
    QString fileName = ui->label->text();
    QByteArray ba = fileName.toLocal8Bit();
    char *str = ba.data();
    Data vertexes = {0, {NULL, 0, 0}};
    Data facets = {0, {NULL, 0, 0}};
    int error = 0;
    error = parser(str, &vertexes, &facets);
    std::cout << error << std::endl;
    std::cout << str << std::endl;

    for (int a = 0; a < vertexes.matrix.rows; a++) {
            for (int b = 0; b <vertexes.matrix.columns; b++) {
                std::cout << vertexes.matrix.matrix[a][b] << "\t";
            }
            std::cout << std::endl;
        }

    for (int a = 0; a < facets.matrix.rows; a++) {
            for (int b = 0; b <facets.matrix.columns; b++) {
                std::cout << facets.matrix.matrix[a][b] << "\t";
            }
            std::cout << std::endl;
        }

}


void MainWindow::on_openTestFile_clicked()
{
     ui->label->setText("/Users/violator/C8_3DViewer_v1.0-1/src/cube.obj");
}

