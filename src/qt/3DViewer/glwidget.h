#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "QtOpenGLWidgets/qopenglwidget.h"

#include "mainwindow.h"

extern "C" {
#include "../../parser.h"
}


class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = nullptr);

    float xRot, yRot, zRot;
    QPoint mPos;

    Vertexes vertex;
    Facets facet;

    void drawCube(float a);
    void drawCubeLine();
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;


    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;


};

#endif // GLWIDGET_H
