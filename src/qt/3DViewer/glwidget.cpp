#include "glwidget.h"
#include "GLUT/glut.h"




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

    glViewport(0,0, w,h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(45.0, (float) w/h, 0.01, 100.0);

//    updateGL();

}

void GLWidget::paintGL()
{
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();


//    glColor3f(1,0,0);
//    glutSolidSphere(0.5 ,100,100);

}
