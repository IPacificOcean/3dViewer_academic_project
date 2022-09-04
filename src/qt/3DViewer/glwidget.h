#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "QtOpenGLWidgets/qopenglwidget.h"

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = nullptr);

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;



};

#endif // GLWIDGET_H
