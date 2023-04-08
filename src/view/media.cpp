#include "media.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
//#include <QFileDialog>


Media::Media(QWidget *parent)
    : QMainWindow{parent}
{
    timer_for_gif = new QTimer(0); // parent must be null
    connect(timer_for_gif, SIGNAL(timeout()), this, SLOT(create_screen()));
}

Media::~Media()
{
    delete timer_for_gif;
}

void Media::SavePicture(Ui::MainWindow *ui)
{
    QFileDialog dialog_photo(this);
      QString name_photo = dialog_photo.getSaveFileName( this, "Save as...", "photo", "BMP (*.bmp);; JPEG (*.jpeg)");
      ui->widget->grabFramebuffer().save(name_photo);
}

void Media::SaveGif(Ui::MainWindow *ui)
{
    timer_for_gif->start(100);
    create_screen(ui);
}


void Media::save_gif(Ui::MainWindow *ui)
{
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

void Media::create_screen(Ui::MainWindow *ui)
{
    if ( time <= 5.0) {
        mas_image.push_back(ui->widget->grabFramebuffer());
        time += 0.1;
        ui->label_Timer_GIF->setText(QString::number(time));
    } else if (time >= 5.0) {
        save_gif(ui);
        timer_for_gif->stop();
    }
}
