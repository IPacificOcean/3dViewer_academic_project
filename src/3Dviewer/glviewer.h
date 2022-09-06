#ifndef GLVIEWER_H
#define GLVIEWER_H

#define GL_SILENCE_DEPRECATION
//#include <QWidget>
#include <QtWidgets/QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets>
#include <OpenGL/gl.h>
#include <OpenGL/GLU.h>
#include <GLUT/glut.h>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QFileDialog>

#include<iostream>

#include <QTimer>

extern "C" {
#include "../../../../../Downloads/C8_3DViewer_v1.0-1-develop-src/src/parser.h"
}
//#include <clocale.h>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "GlU32.lib")

QT_BEGIN_NAMESPACE
namespace Ui { class GLviewer; }
QT_END_NAMESPACE

class GLviewer : public QOpenGLWidget
{
    Q_OBJECT
private:
    float xRot, yRot, zRot;
    QPoint mPos;

    void drawCube(float a);
    void drawCubeLine();
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

public:
    GLviewer(QWidget *parent = nullptr);
    ~GLviewer();



private:
    Ui::GLviewer *ui;


};
#endif // GLVIEWER_H
