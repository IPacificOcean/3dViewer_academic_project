#include "glwidget.h"

GLWidget ::  GLWidget(QWidget *parent) : QOpenGLWidget (parent)
{

}

void GLWidget::initializeGL()
{
    glClearColor(0.51,0.68, 0.72, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

void GLWidget::resizeGL(int w, int h)
{

}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
