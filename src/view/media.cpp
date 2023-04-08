#include "media.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
//#include <QFileDialog>


Media::Media(QWidget *parent)
    : QMainWindow{parent}
{

}

void Media::SavePicture(Ui::MainWindow *ui)
{
    QFileDialog dialog_photo(this);
      QString name_photo = dialog_photo.getSaveFileName( this, "Save as...", "photo", "BMP (*.bmp);; JPEG (*.jpeg)");
      ui->widget->grabFramebuffer().save(name_photo);
}
