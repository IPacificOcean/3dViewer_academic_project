#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "glviewer.h"
#include <QColorDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openFile_clicked();


    void on_doubleSpinBox_Scale_valueChanged(double valueScale);




private:
    Ui::MainWindow *ui;
    void wheelEvent(QWheelEvent *event) override;
};
#endif // MAINWINDOW_H
