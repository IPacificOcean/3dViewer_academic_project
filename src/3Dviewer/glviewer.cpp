#include "glviewer.h"
#include "ui_glviewer.h"



GLviewer::GLviewer(QWidget *parent)
    : QOpenGLWidget(parent)
    , ui(new Ui::GLviewer)
{
    ui->setupUi(this);
    setWindowTitle("New game");
    setGeometry(400, 200, 800, 600);
//    z = 0;
//    connect(&tmr,SIGNAL(timeout()), this, SLOT(changeZ()));
//    tmr.start(100);

}

GLviewer::~GLviewer()
{
    delete ui;
}

void GLviewer::initializeGL()
{
    glEnable(GL_DEPTH_TEST);

}

void GLviewer::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-1, 1, -1, 1, 1, 2);
    glFrustum(-1, 1, -1, 1, 1, 3);
}


void GLviewer::paintGL()
{
    glClearColor(0, 1, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
//    glScalef(1.5, 1.5, 1.5);
    glTranslatef(0, 0, -2);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);
    drawCube(0.5);
}

void GLviewer::drawCube(float a)
{
    float ver_cub[] = {
        -a,-a,a, a,-a,a, a,a,a, -a,a,a,
        a,-a,-a, -a,-a,-a, -a,a,-a, a,a,-a,
        -a,-a,-a, -a,-a,a, -a,a,a, -a,a,-a,
        a,-a,a, a,-a,-a, a,a,-a, a,a,a,
        -a,-a,a, a,-a,a, a,-a,-a, -a,-a,-a,
        -a,a,a, a,a,a, a,a,-a, -a,a,-a
    };

    float color_arr[] = {
        1,0,0, 1,0,0, 1,0,0, 1,0,0,
        0,0,1, 0,0,1, 0,0,1, 0,0,1,
        1,1,0, 1,1,0, 1,1,0, 1,1,0,
        0,1,1, 0,1,1, 0,1,1, 0,1,1,
        1,0,1, 1,0,1, 1,0,1, 1,0,1,
        1,0.5,0.5, 1,0.5,0.5, 1,0.5,0.5, 1,0.5,0.5

    };

    glVertexPointer(3,GL_FLOAT, 0, &ver_cub);
    glEnableClientState(GL_VERTEX_ARRAY);

//    glColorPointer(3,GL_FLOAT, 0, &color_arr);
//    glEnableClientState(GL_COLOR_ARRAY);

        glDrawArrays(GL_QUADS, 0, 24);
//        glDrawElements(GL_LINES, 124, GL_UNSIGNED_INT, &ver_cub);

//     glDisableClientState(GL_COLOR_ARRAY);
     glDisableClientState(GL_VERTEX_ARRAY);
}

void GLviewer::mousePressEvent(QMouseEvent* mo)
{
    mPos = mo->pos();
}

void GLviewer::mouseMoveEvent(QMouseEvent* mo)
{
    xRot += 0.09/M_PI * (mo->pos().y() - mPos.y());
    yRot += 0.09/M_PI * (mo->pos().x() - mPos.x());
    update();
}


