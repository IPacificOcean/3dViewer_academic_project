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
    explicit Media(QWidget *parent = nullptr);
    ~Media();

    void SavePicture(Ui::MainWindow *ui);
    void SaveGif(Ui::MainWindow *ui);
    QVector<QImage> mas_image;

signals:


   private
   slots:

   void create_screen(Ui::MainWindow *ui);
   void save_gif(Ui::MainWindow *ui);

private:
  QTimer *timer_for_gif;
  double time = 0;

};

#endif // MEDIA_H
