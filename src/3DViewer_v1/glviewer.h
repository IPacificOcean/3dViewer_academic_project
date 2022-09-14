#ifndef GLVIEWER_H
#define GLVIEWER_H

#define GL_SILENCE_DEPRECATION

#include <QtWidgets/QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets>
//#include <OpenGL/gl.h>
//#include <OpenGL/GLU.h>
//#include <GLUT/glut.h>
//#include <QOpenGLShaderProgram>
//#include <QOpenGLBuffer>
#include <QFileDialog>

#include<iostream>

#include <QTimer>

extern "C" {
#include "../backend/parser.h"
}

//#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "GlU32.lib")

QT_BEGIN_NAMESPACE
namespace Ui { class GLviewer; }
QT_END_NAMESPACE

class GLviewer : public QOpenGLWidget
{
    Q_OBJECT

public:
    GLviewer(QWidget *parent = nullptr);
    ~GLviewer();
    Vertexes vertex;
    Facets facet;
    double scale = 0.05;

    void change_zoom(double value);

private:
//    Ui::GLviewer *ui;

    float xRot, yRot, zRot;
    QPoint mPos;


    void drawShape();
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;


    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;


};
#endif // GLVIEWER_H
