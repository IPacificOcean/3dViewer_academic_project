#ifndef MEDIA_H
#define MEDIA_H

#include <QObject>
#include <QMainWindow>

//_________GIF
#include <QLabel>
#include <QPixmap>
#include <QScreen>
#include <vector>
#include <QVector>
#include <cstdint>
#include <QTimer>
#include <QSettings>
#include <QTextEdit>
#include <math.h>
#include "QtGifImage-master/src/gifimage/qgifimage.h"
#include <QPainter>
#include <QImage>
//__________________

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Media : public QMainWindow
{
    Q_OBJECT
public:
    explicit Media(Ui::MainWindow *ui, QWidget *parent = nullptr);
    ~Media();

    void SavePicture();
    void SaveGif();
    QVector<QImage> mas_image;

private
   slots:

   void create_screen();
   void save_gif();

private:
  Ui::MainWindow *ui;
  QTimer *timer_for_gif{};
  double time = 0;

};

#endif // MEDIA_H
