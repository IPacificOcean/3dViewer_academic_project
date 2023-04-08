#ifndef MEDIA_H
#define MEDIA_H

#include <QObject>
#include <QMainWindow>

//_________GIF
#include <QLabel>
#include <QPixmap>
#include <QScreen>
#include <vector>
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

    void SavePicture(Ui::MainWindow *ui);

signals:

};

#endif // MEDIA_H
